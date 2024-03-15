package P93;


import java.util.ArrayList;
import java.util.List;

class Transaction {
    private int transactionId;
    private double amount;
    private String transactionType;

    public Transaction(int transactionId, double amount, String transactionType) {
        this.transactionId = transactionId;
        this.amount = amount;
        this.transactionType = transactionType;
    }

    public int getTransactionId() {
        return transactionId;
    }

    public double getAmount() {
        return amount;
    }

    public String getTransactionType() {
        return transactionType;
    }
}

class Account {
    private int accountId;
    private double balance;
    private List<Transaction> transactionHistory;

    public Account(int accountId) {
        this.accountId = accountId;
        this.balance = 0.0;
        this.transactionHistory = new ArrayList<>();
    }

    public int getAccountId() {
        return accountId;
    }

    public double getBalance() {
        return balance;
    }

    public List<Transaction> getTransactionHistory() {
        return transactionHistory;
    }

    public void deposit(double amount) {
        balance += amount;
        transactionHistory.add(new Transaction(transactionHistory.size() + 1, amount, "Deposit"));
    }

    public void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactionHistory.add(new Transaction(transactionHistory.size() + 1, amount, "Withdrawal"));
        } else {
            System.out.println("Insufficient funds for withdrawal.");
        }
    }

    public void transfer(Account recipient, double amount) {
        if (amount <= balance) {
            balance -= amount;
            recipient.deposit(amount);
            transactionHistory.add(new Transaction(transactionHistory.size() + 1, amount, "Transfer to Account " + recipient.getAccountId()));
        } else {
            System.out.println("Insufficient funds for transfer.");
        }
    }
}

class Customer {
    private String customerId;
    private String customerName;
    private List<Account> accounts;

    public Customer(String customerId, String customerName) {
        this.customerId = customerId;
        this.customerName = customerName;
        this.accounts = new ArrayList<>();
    }

    public String getCustomerId() {
        return customerId;
    }

    public String getCustomerName() {
        return customerName;
    }

    public List<Account> getAccounts() {
        return accounts;
    }

    public void addAccount(Account account) {
        accounts.add(account);
    }

    public void viewAccountBalances() {
        System.out.println("Account Balances for Customer " + customerName + ":");
        for (Account account : accounts) {
            System.out.println("Account ID " + account.getAccountId() + ": $" + account.getBalance());
        }
        System.out.println("----------------------");
    }

    public void viewTransactionHistory() {
        System.out.println("Transaction History for Customer " + customerName + ":");
        for (Account account : accounts) {
            System.out.println("Account ID " + account.getAccountId() + " Transactions:");
            for (Transaction transaction : account.getTransactionHistory()) {
                System.out.println("Transaction ID " + transaction.getTransactionId() +
                        ": " + transaction.getTransactionType() + " $" + transaction.getAmount());
            }
            System.out.println("----------------------");
        }
    }
}

class Bank {
    private List<Customer> customers;

    public Bank() {
        this.customers = new ArrayList<>();
    }

    public void addCustomer(Customer customer) {
        customers.add(customer);
    }
}


public class TestOnlineBanking {
    public static void main(String[] args) {

        Bank bank = new Bank();


        Customer customer1 = new Customer("C101", "Alice");
        Customer customer2 = new Customer("C102", "Bob");

        Account account1 = new Account(1);
        Account account2 = new Account(2);

        customer1.addAccount(account1);
        customer2.addAccount(account2);

        bank.addCustomer(customer1);
        bank.addCustomer(customer2);

        account1.deposit(1000.0);
        account1.withdraw(200.0);
        account2.deposit(500.0);
        account1.transfer(account2, 300.0);
        customer1.viewAccountBalances();
        customer1.viewTransactionHistory();

        customer2.viewAccountBalances();
        customer2.viewTransactionHistory();
        }
}
