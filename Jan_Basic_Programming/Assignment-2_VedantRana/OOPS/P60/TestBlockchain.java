package P60;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.List;

// Block class representing a block in the blockchain
class Block {
    private int index;
    private String previousHash;
    private String data;
    private long timestamp;
    private String hash;

    public Block(int index, String previousHash, String data) {
        this.index = index;
        this.previousHash = previousHash;
        this.data = data;
        this.timestamp = System.currentTimeMillis();
        this.hash = calculateHash();
    }

    public String calculateHash() {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            String input = index + previousHash + data + timestamp;
            byte[] hashBytes = digest.digest(input.getBytes());

            StringBuilder hexString = new StringBuilder();
            for (byte hashByte : hashBytes) {
                String hex = Integer.toHexString(0xff & hashByte);
                if (hex.length() == 1) hexString.append('0');
                hexString.append(hex);
            }

            return hexString.toString();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            return null;
        }
    }

    public int getIndex() {
        return index;
    }

    public String getPreviousHash() {
        return previousHash;
    }

    public String getData() {
        return data;
    }

    public long getTimestamp() {
        return timestamp;
    }

    public String getHash() {
        return hash;
    }
}

// Blockchain class managing the blocks and consensus algorithm
class Blockchain {
    private List<Block> blocks;

    public Blockchain() {
        this.blocks = new ArrayList<>();
        // Genesis block
        addBlock(new Block(0, "0", "Genesis Block"));
    }

    public void addBlock(Block newBlock) {
        blocks.add(newBlock);
    }

    public List<Block> getBlocks() {
        return blocks;
    }

    public boolean isValid() {
        for (int i = 1; i < blocks.size(); i++) {
            Block currentBlock = blocks.get(i);
            Block previousBlock = blocks.get(i - 1);

            if (!currentBlock.getHash().equals(currentBlock.calculateHash())) {
                System.out.println("Block #" + currentBlock.getIndex() + " has an invalid hash.");
                return false;
            }

            if (!currentBlock.getPreviousHash().equals(previousBlock.getHash())) {
                System.out.println("Block #" + currentBlock.getIndex() + " has an invalid previous hash.");
                return false;
            }
        }

        return true;
    }

    public Block getLatestBlock() {
        if (blocks.isEmpty()) {
            return null;
        }
        return blocks.get(blocks.size() - 1);
    }
}


public class TestBlockchain {
    public static void main(String[] args) {
        Blockchain blockchain = new Blockchain();

        // Add some blocks to the blockchain
        blockchain.addBlock(new Block(1, blockchain.getLatestBlock().getHash(), "Transaction Data 1"));
        blockchain.addBlock(new Block(2, blockchain.getLatestBlock().getHash(), "Transaction Data 2"));
        blockchain.addBlock(new Block(3, blockchain.getLatestBlock().getHash(), "Transaction Data 3"));

        // Display the blockchain
        for (Block block : blockchain.getBlocks()) {
            System.out.println("Block #" + block.getIndex());
            System.out.println("Previous Hash: " + block.getPreviousHash());
            System.out.println("Data: " + block.getData());
            System.out.println("Timestamp: " + block.getTimestamp());
            System.out.println("Hash: " + block.getHash() + "\n");
        }

        // Check if the blockchain is valid
        System.out.println("Is Blockchain Valid: " + blockchain.isValid());
    }
}
