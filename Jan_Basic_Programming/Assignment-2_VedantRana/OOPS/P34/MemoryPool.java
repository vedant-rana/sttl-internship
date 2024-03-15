public class MemoryPool {
    private final byte[] memory;
    private final int blockSize;
    private final boolean[] allocated;

    public MemoryPool(int poolSize, int blockSize) {
        this.memory = new byte[poolSize];
        this.blockSize = blockSize;
        this.allocated = new boolean[poolSize / blockSize];

        // Initialize all blocks as free
        for (int i = 0; i < allocated.length; i++) {
            allocated[i] = false;
        }
    }

    public int allocate() {
        for (int i = 0; i < allocated.length; i++) {
            if (!allocated[i]) {
                allocated[i] = true;
                return i * blockSize;
            }
        }
        // No free block available
        return -1;
    }

    public void deallocate(int offset) {
        if (offset % blockSize == 0 && offset / blockSize < allocated.length) {
            allocated[offset / blockSize] = false;
        } else {
            // Invalid offset
            throw new IllegalArgumentException("Invalid offset");
        }
    }

    // Other methods for advanced features can be added here

    public static void main(String[] args) {
        int poolSize = 1024;
        int blockSize = 64;

        MemoryPool memoryPool = new MemoryPool(poolSize, blockSize);

        // Allocate memory blocks
        int block1 = memoryPool.allocate();
        int block2 = memoryPool.allocate();

        // Deallocate memory block
        memoryPool.deallocate(block1);

        // Allocate another memory block
        int block3 = memoryPool.allocate();

        // Print allocated blocks
        System.out.println("Allocated Blocks:");
        System.out.println("Block 2: " + block2);
        System.out.println("Block 3: " + block3);
    }
}
