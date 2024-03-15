package P33_Observer;
import java.util.ArrayList;
import java.util.List;


interface Observer {
    void update(String stockName, double stockPrice);
}


interface Subject {
    void registerObserver(Observer observer);
    void removeObserver(Observer observer);
    void notifyObservers();
}


class StockObserver implements Observer {
    private String name;

    public StockObserver(String name) {
        this.name = name;
    }

    @Override
    public void update(String stockName, double stockPrice) {
        System.out.println(name + " received an update - " + stockName + " price: " + stockPrice);
    }
}


class StockMarket implements Subject {
    private String stockName;
    private double stockPrice;
    private List<Observer> observers = new ArrayList<>();

    public void setStockData(String stockName, double stockPrice) {
        this.stockName = stockName;
        this.stockPrice = stockPrice;
        notifyObservers();
    }

    @Override
    public void registerObserver(Observer observer) {
        observers.add(observer);
    }

    @Override
    public void removeObserver(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers() {
        for (Observer observer : observers) {
            observer.update(stockName, stockPrice);
        }
    }
}




public class TestObserver {
    public static void main(String[] args) {

        StockMarket stockMarket = new StockMarket();

        Observer observer1 = new StockObserver("Observer 1");
        Observer observer2 = new StockObserver("Observer 2");

        stockMarket.registerObserver(observer1);
        stockMarket.registerObserver(observer2);

        stockMarket.setStockData("ABC", 100.0);

        stockMarket.removeObserver(observer1);

        stockMarket.setStockData("XYZ", 150.0);
    }
}
