package P61;

class BankAccount {
    private String accountNumber;
    private double balance;

    public BankAccount(String accountNumber, double initialBalance) {
        this.accountNumber = accountNumber;
        this.balance = initialBalance;
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposit successful. New balance: $" + balance);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawal successful. New balance: $" + balance);
        } else {
            System.out.println("Invalid withdrawal amount or insufficient funds.");
        }
    }

    public double checkBalance() {
        return balance;
    }
}

class SavingsAccount extends BankAccount {
    private double interestRate;

    public SavingsAccount(String accountNumber, double initialBalance, double interestRate) {
        super(accountNumber, initialBalance);
        this.interestRate = interestRate;
    }

    public void applyInterest() {
        double interestAmount = checkBalance() * interestRate;
        deposit(interestAmount);
        System.out.println("Interest applied. New balance: $" + checkBalance());
    }
}

public class TestBank {
    public static void main(String[] args) {
        BankAccount account1 = new BankAccount("123456", 1000.0);
        SavingsAccount savingsAccount = new SavingsAccount("789012", 2000.0, 0.05);

        account1.deposit(500.0);
        account1.withdraw(200.0);

        System.out.println("Account Balance: $" + account1.checkBalance());

        savingsAccount.deposit(1000.0);
        savingsAccount.applyInterest();

        System.out.println("Savings Account Balance: $" + savingsAccount.checkBalance());
    }
}
