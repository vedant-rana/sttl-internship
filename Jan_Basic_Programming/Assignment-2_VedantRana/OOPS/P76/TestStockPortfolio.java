package P76;


import java.util.ArrayList;
import java.util.List;

class Stock {
    private String symbol;
    private double price;

    public Stock(String symbol, double price) {
        this.symbol = symbol;
        this.price = price;
    }

    public String getSymbol() {
        return symbol;
    }

    public double getPrice() {
        return price;
    }
}

class Transaction {
    private Stock stock;
    private int quantity;
    private String type; // "Buy" or "Sell"

    public Transaction(Stock stock, int quantity, String type) {
        this.stock = stock;
        this.quantity = quantity;
        this.type = type;
    }

    public Stock getStock() {
        return stock;
    }

    public int getQuantity() {
        return quantity;
    }

    public String getType() {
        return type;
    }
}

class Portfolio {
    private List<Transaction> transactions;

    public Portfolio() {
        this.transactions = new ArrayList<>();
    }

    public void buyStock(Stock stock, int quantity) {
        Transaction buyTransaction = new Transaction(stock, quantity, "Buy");
        transactions.add(buyTransaction);
        System.out.println(quantity + " shares of " + stock.getSymbol() + " bought.");
    }

    public void sellStock(Stock stock, int quantity) {
        Transaction sellTransaction = new Transaction(stock, quantity, "Sell");
        transactions.add(sellTransaction);
        System.out.println(quantity + " shares of " + stock.getSymbol() + " sold.");
    }

    public double calculatePortfolioValue() {
        double portfolioValue = 0;
        for (Transaction transaction : transactions) {
            Stock stock = transaction.getStock();
            double transactionValue = stock.getPrice() * transaction.getQuantity();
            if (transaction.getType().equals("Sell")) {
                transactionValue *= -1; // Selling reduces portfolio value
            }
            portfolioValue += transactionValue;
        }
        return portfolioValue;
    }

    public List<Transaction> getTransactionHistory() {
        return transactions;
    }
}


public class TestStockPortfolio {
    public static void main(String[] args) {
        Stock appleStock = new Stock("AAPL", 150.0);
        Stock googleStock = new Stock("GOOGL", 2800.0);

        Portfolio portfolio = new Portfolio();

        portfolio.buyStock(appleStock, 10);
        portfolio.sellStock(googleStock, 5);
        portfolio.buyStock(appleStock, 8);

        double portfolioValue = portfolio.calculatePortfolioValue();
        System.out.println("Portfolio Value: $" + portfolioValue);

        List<Transaction> transactionHistory = portfolio.getTransactionHistory();
        System.out.println("Transaction History:");
        for (Transaction transaction : transactionHistory) {
            System.out.println("- " + transaction.getType() + " " +
                    transaction.getQuantity() + " shares of " + transaction.getStock().getSymbol());
        }
    }
}
