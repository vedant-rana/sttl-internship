package P51;

import java.util.concurrent.ConcurrentHashMap;

// Distributed Cache Interface
interface DistributedCache<K, V> {
    V get(K key);

    void put(K key, V value);

    void remove(K key);
}

// Simple Node class representing a node in the distributed cache system
class Node<K, V> {
    private final DistributedCache<K, V> localCache;

    public Node() {
        this.localCache = new SimpleDistributedCache<>();
    }

    public V get(K key) {
        return localCache.get(key);
    }

    public void put(K key, V value) {
        localCache.put(key, value);
    }

    public void remove(K key) {
        localCache.remove(key);
    }
}

// Simple implementation of a distributed cache using ConcurrentHashMap
class SimpleDistributedCache<K, V> implements DistributedCache<K, V> {
    private final ConcurrentHashMap<K, V> cache;

    public SimpleDistributedCache() {
        this.cache = new ConcurrentHashMap<>();
    }

    @Override
    public V get(K key) {
        return cache.get(key);
    }

    @Override
    public void put(K key, V value) {
        cache.put(key, value);
    }

    @Override
    public void remove(K key) {
        cache.remove(key);
    }
}

// Distributed Cache System orchestrating multiple nodes
class DistributedCacheSystem<K, V> {
    private final Node<K, V>[] nodes;

    public DistributedCacheSystem(int numNodes) {
        this.nodes = new Node[numNodes];
        for (int i = 0; i < numNodes; i++) {
            nodes[i] = new Node<>();
        }
    }

    public V get(K key) {
        int nodeIndex = hash(key, nodes.length);
        return nodes[nodeIndex].get(key);
    }

    public void put(K key, V value) {
        int nodeIndex = hash(key, nodes.length);
        nodes[nodeIndex].put(key, value);
    }

    public void remove(K key) {
        int nodeIndex = hash(key, nodes.length);
        nodes[nodeIndex].remove(key);
    }

    private int hash(K key, int numNodes) {
        // Simple hash function, a more sophisticated approach is recommended in a production system
        return Math.abs(key.hashCode()) % numNodes;
    }
}

public class TestCacheSystem {
    public static void main(String[] args) {
        // Create a distributed cache system with 3 nodes
        DistributedCacheSystem<String, Integer> cacheSystem = new DistributedCacheSystem<>(3);

        // Put and get data from the distributed cache
        cacheSystem.put("key1", 42);
        System.out.println("Value for key1: " + cacheSystem.get("key1"));

        // Remove data from the distributed cache
        cacheSystem.remove("key1");
        System.out.println("Value for key1 after removal: " + cacheSystem.get("key1"));
    }
}
