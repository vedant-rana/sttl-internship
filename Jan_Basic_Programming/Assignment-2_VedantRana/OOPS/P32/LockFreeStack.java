package P32;

import java.util.concurrent.atomic.AtomicReference;

public class LockFreeStack<T> {

    private static class Node<T> {
        final T value;
        Node<T> next;

        Node(T value) {
            this.value = value;
        }
    }

    private final AtomicReference<Node<T>> top = new AtomicReference<>();

    public void push(T value) {
        Node<T> newNode = new Node<>(value);

        while (true) {
            Node<T> currentTop = top.get();
            newNode.next = currentTop;

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

            Node<T> newTop = currentTop.next;

            if (top.compareAndSet(currentTop, newTop)) {
                return currentTop.value;
            }
        }
    }

    public static void main(String[] args) {
        LockFreeStack<Integer> stack = new LockFreeStack<>();

        // Push elements onto the stack
        stack.push(1);
        stack.push(2);
        stack.push(3);

        // Pop elements from the stack
        System.out.println("Popped: " + stack.pop()); // 3
        System.out.println("Popped: " + stack.pop()); // 2
        System.out.println("Popped: " + stack.pop()); // 1
        System.out.println("Popped: " + stack.pop()); // null (stack is empty)
    }
}
