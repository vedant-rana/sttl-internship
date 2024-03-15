import java.util.concurrent.atomic.AtomicReference;
import java.util.concurrent.atomic.AtomicStampedReference;

class LockFreeTransactionalMemory<T> {

    private static final int MAX_RETRIES = 100;

    private static class TransactionalNode<T> {
        T value;
        AtomicStampedReference<TransactionalNode<T>> next;

        TransactionalNode(T value, TransactionalNode<T> next) {
            this.value = value;
            this.next = new AtomicStampedReference<>(next, 0);
        }
    }

    private AtomicReference<TransactionalNode<T>> head;

    public LockFreeTransactionalMemory() {
        this.head = new AtomicReference<>(null);
    }

    public void add(T value) {
        TransactionalNode<T> newNode = new TransactionalNode<>(value, null);
        while (true) {
            Pair<T> result = find(value);
            TransactionalNode<T> pred = result.pred;
            TransactionalNode<T> curr = result.curr;

            if (curr != null) {
                return; // Value already exists, do not add
            }

            newNode.next.set(pred.next.getReference(), 0);

            if (pred.next.compareAndSet(null, newNode, pred.next.getStamp(), pred.next.getStamp() + 1)) {
                return; // Successfully added
            }
        }
    }

    public boolean remove(T value) {
        for (int retries = 0; retries < MAX_RETRIES; retries++) {
            Pair<T> result = find(value);
            TransactionalNode<T> pred = result.pred;
            TransactionalNode<T> curr = result.curr;

            if (curr == null) {
                return false; // Value not found, cannot remove
            }

            TransactionalNode<T> succ = curr.next.getReference();
            int stamp = pred.next.getStamp();
            
            if (pred.next.compareAndSet(curr, succ, stamp, stamp + 1)) {
                return true; // Successfully removed
            }
        }

        return false; // Exceeded max retries, consider it a failure
    }

    private Pair<T> find(T value) {
        TransactionalNode<T> pred = null;
        TransactionalNode<T> curr = head.get();
        
        while (curr != null && value.hashCode() > curr.value.hashCode()) {
            pred = curr;
            curr = curr.next.getReference();
        }

        return new Pair<>(pred, curr);
    }

    public void print() {
        TransactionalNode<T> current = head.get();
        while (current != null) {
            System.out.print(current.value + " ");
            current = current.next.getReference();
        }
        System.out.println();
    }

    private static class Pair<T> {
        TransactionalNode<T> pred;
        TransactionalNode<T> curr;

        Pair(TransactionalNode<T> pred, TransactionalNode<T> curr) {
            this.pred = pred;
            this.curr = curr;
        }
    }

    public static void main(String[] args) {
        LockFreeTransactionalMemory<Integer> memory = new LockFreeTransactionalMemory<>();

        // Add values concurrently
        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                memory.add(i);
            }
        });

        // Remove values concurrently
        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                memory.remove(i);
            }
        });

        t1.start();
        t2.start();

        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        memory.print();
    }
}
