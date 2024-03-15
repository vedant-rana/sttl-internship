package P78;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Product {
    private String productId;
    private String name;
    private double price;

    public Product(String productId, String name, double price) {
        this.productId = productId;
        this.name = name;
        this.price = price;
    }

    public String getProductId() {
        return productId;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }
}

class ShoppingCart {
    private Map<Product, Integer> items;

    public ShoppingCart() {
        this.items = new HashMap<>();
    }

    public void addItem(Product product, int quantity) {
        items.put(product, items.getOrDefault(product, 0) + quantity);
    }

    public void removeItem(Product product, int quantity) {
        int currentQuantity = items.getOrDefault(product, 0);
        if (currentQuantity > quantity) {
            items.put(product, currentQuantity - quantity);
        } else {
            items.remove(product);
        }
    }

    public Map<Product, Integer> getItems() {
        return items;
    }

    public double calculateTotal() {
        double total = 0;
        for (Map.Entry<Product, Integer> entry : items.entrySet()) {
            total += entry.getKey().getPrice() * entry.getValue();
        }
        return total;
    }

    public void clearCart() {
        items.clear();
    }
}

class Order {
    private String orderId;
    private ShoppingCart cart;
    private String customerName;
    private String shippingAddress;

    public Order(String orderId, ShoppingCart cart, String customerName, String shippingAddress) {
        this.orderId = orderId;
        this.cart = cart;
        this.customerName = customerName;
        this.shippingAddress = shippingAddress;
    }

    public String getOrderId() {
        return orderId;
    }

    public ShoppingCart getCart() {
        return cart;
    }

    public String getCustomerName() {
        return customerName;
    }

    public String getShippingAddress() {
        return shippingAddress;
    }
}



public class TestE_Commerce {
    public static void main(String[] args) {
        Product laptop = new Product("P1", "Laptop", 1000.0);
        Product phone = new Product("P2", "Smartphone", 500.0);

        ShoppingCart cart = new ShoppingCart();
        cart.addItem(laptop, 2);
        cart.addItem(phone, 1);

        double totalBeforeOrder = cart.calculateTotal();
        System.out.println("Total before order: $" + totalBeforeOrder);

        Order order = new Order("O1", cart, "John Doe", "123 Main St");
        System.out.println("Order placed. Order ID: " + order.getOrderId());

        double totalAfterOrder = cart.calculateTotal();
        System.out.println("Total after order: $" + totalAfterOrder);

        // Clear the cart after completing the order
        cart.clearCart();
        System.out.println("Cart cleared. Items in cart: " + cart.getItems().size());
    }
}
