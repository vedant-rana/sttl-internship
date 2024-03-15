package P28;

// Contract Interface
interface SmartContract {
    void execute();
}

// Concrete Contract Classes
class PaymentContract implements SmartContract {
    private String sender;
    private String recipient;
    private double amount;

    public PaymentContract(String sender, String recipient, double amount) {
        this.sender = sender;
        this.recipient = recipient;
        this.amount = amount;
    }

    @Override
    public void execute() {
        System.out.println("Executing PaymentContract: " + sender + " pays " + recipient + " $" + amount);
        // Implement payment logic here
    }
}

class TokenTransferContract implements SmartContract {
    private String from;
    private String to;
    private int amount;

    public TokenTransferContract(String from, String to, int amount) {
        this.from = from;
        this.to = to;
        this.amount = amount;
    }

    @Override
    public void execute() {
        System.out.println("Executing TokenTransferContract: " + from + " transfers " + amount + " tokens to " + to);
        // Implement token transfer logic here
    }
}

// Executor Class
class SmartContractExecutor {
    public void executeContract(SmartContract contract) {
        contract.execute();
    }
}


public class TestSmartContract {
    public static void main(String[] args) {
        SmartContract paymentContract = new PaymentContract("Alice", "Bob", 100.0);
        SmartContract tokenTransferContract = new TokenTransferContract("Alice", "Charlie", 50);

        SmartContractExecutor executor = new SmartContractExecutor();

        // Execute PaymentContract
        executor.executeContract(paymentContract);

        // Execute TokenTransferContract
        executor.executeContract(tokenTransferContract);
    }
}
