package P62;

import java.util.ArrayList;
import java.util.List;

class Product {
    private String productName;
    private double price;

    public Product(String productName, double price) {
        this.productName = productName;
        this.price = price;
    }

    public String getProductName() {
        return productName;
    }

    public double getPrice() {
        return price;
    }
}

class ShoppingCart {
    private List<Product> cartItems;

    public ShoppingCart() {
        this.cartItems = new ArrayList<>();
    }

    public void addItem(Product product) {
        cartItems.add(product);
    }

    public void removeItem(Product product) {
        cartItems.remove(product);
    }

    public double calculateTotal() {
        double total = 0;
        for (Product item : cartItems) {
            total += item.getPrice();
        }
        return total;
    }

    public void checkout() {
        // Simulate the checkout process, e.g., deducting inventory, processing payment, etc.
        System.out.println("Checkout completed. Total amount: $" + calculateTotal());
        cartItems.clear();
    }

    public List<Product> getCartItems() {
        return new ArrayList<>(cartItems);
    }
}

class Customer {
    private String customerName;
    private ShoppingCart shoppingCart;

    public Customer(String customerName) {
        this.customerName = customerName;
        this.shoppingCart = new ShoppingCart();
    }

    public void addToCart(Product product) {
        shoppingCart.addItem(product);
        System.out.println(product.getProductName() + " added to the cart.");
    }

    public void removeFromCart(Product product) {
        shoppingCart.removeItem(product);
        System.out.println(product.getProductName() + " removed from the cart.");
    }

    public void viewCart() {
        System.out.println("Shopping Cart for " + customerName + ":");
        for (Product item : shoppingCart.getCartItems()) {
            System.out.println(item.getProductName() + " - $" + item.getPrice());
        }
        System.out.println("Total: $" + shoppingCart.calculateTotal());
    }

    public void checkout() {
        shoppingCart.checkout();
    }
}

public class TestOnlineShopping {
    public static void main(String[] args) {
        Product laptop = new Product("Laptop", 1200.0);
        Product headphones = new Product("Headphones", 100.0);

        Customer customer = new Customer("John Doe");

        customer.addToCart(laptop);
        customer.addToCart(headphones);

        customer.viewCart();

        customer.checkout();
    }
}
