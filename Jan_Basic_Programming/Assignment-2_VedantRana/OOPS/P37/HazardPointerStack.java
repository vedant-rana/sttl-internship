import java.util.concurrent.atomic.AtomicReference;
import java.util.concurrent.atomic.AtomicStampedReference;

public class HazardPointerStack<T> {
    private static final int MAX_HAZARD_POINTERS = 2;

    private static class Node<T> {
        T value;
        AtomicReference<Node<T>> next;

        Node(T value) {
            this.value = value;
            this.next = new AtomicReference<>(null);
        }
    }

    private AtomicReference<Node<T>> top = new AtomicReference<>(null);

    private ThreadLocal<AtomicStampedReference<Node<T>>> hazardPointers = ThreadLocal
            .withInitial(() -> new AtomicStampedReference<>(null, 0));

    private ThreadLocal<Integer> activeHazardPointers = ThreadLocal.withInitial(() -> 0);

    public void push(T value) {
        Node<T> newNode = new Node<>(value);
        while (true) {
            Node<T> currentTop = top.get();
            newNode.next.set(currentTop);
            if (top.compareAndSet(currentTop, newNode)) {
                return;
            }
        }
    }

    public T pop() {
        while (true) {
            Node<T> currentTop = top.get();
            if (currentTop == null) {
                return null; // Stack is empty
            }
            hazardPointers.get().set(currentTop, 0);
            if (top.compareAndSet(currentTop, currentTop.next.get())) {
                retireNode(currentTop);
                return currentTop.value;
            }
        }
    }

    private void retireNode(Node<T> node) {
        if (activeHazardPointers.get() >= MAX_HAZARD_POINTERS) {
            clean();
        }
        AtomicStampedReference<Node<T>>[] localHazardPointers = new AtomicStampedReference[MAX_HAZARD_POINTERS];
        for (int i = 0; i < MAX_HAZARD_POINTERS; i++) {
            localHazardPointers[i] = hazardPointers.get();
        }
        for (int i = 0; i < MAX_HAZARD_POINTERS; i++) {
            if (localHazardPointers[i].getReference() == node) {
                return;
            }
        }
        retireNode(node, localHazardPointers);
    }

    private void retireNode(Node<T> node, AtomicStampedReference<Node<T>>[] localHazardPointers) {
        for (int i = 0; i < MAX_HAZARD_POINTERS; i++) {
            if (localHazardPointers[i].compareAndSet(null, node, 0, 1)) {
                activeHazardPointers.set(activeHazardPointers.get() + 1);
                return;
            }
        }
        clean();
        retireNode(node, localHazardPointers);
    }

    private void clean() {
        for (int i = 0; i < MAX_HAZARD_POINTERS; i++) {
            AtomicStampedReference<Node<T>> hazardPointer = hazardPointers.get();
            if (hazardPointer.compareAndSet(hazardPointer.getReference(), null, 0, 1)) {
                activeHazardPointers.set(activeHazardPointers.get() - 1);
            }
        }
        Node<T> node;
        do {
            node = getRetiredNode();
            if (node != null) {
                reclaimNode(node);
            }
        } while (node != null);
    }

    private Node<T> getRetiredNode() {
        // Simulate getting a node to retire
        return new Node<>(null);
    }

    private void reclaimNode(Node<T> node) {
        // Simulate reclaiming memory of the retired node
        System.out.println("Reclaiming memory of node: " + node.value);
    }

    public static void main(String[] args) {
        HazardPointerStack<Integer> stack = new HazardPointerStack<>();

        for (int i = 1; i <= 10; i++) {
            stack.push(i);
        }

        for (int i = 1; i <= 10; i++) {
            Integer value = stack.pop();
            if (value != null) {
                System.out.println("Popped value: " + value);
            } else {
                System.out.println("Stack is empty");
            }
        }
    }
}
