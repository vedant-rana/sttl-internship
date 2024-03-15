package P96;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Product {
    private int productId;
    private String productName;
    private double price;
    private int stockQuantity;

    public Product(int productId, String productName, double price, int stockQuantity) {
        this.productId = productId;
        this.productName = productName;
        this.price = price;
        this.stockQuantity = stockQuantity;
    }

    public int getProductId() {
        return productId;
    }

    public String getProductName() {
        return productName;
    }

    public double getPrice() {
        return price;
    }

    public int getStockQuantity() {
        return stockQuantity;
    }

    public void setStockQuantity(int stockQuantity) {
        this.stockQuantity = stockQuantity;
    }
}

class Category {
    private String categoryName;
    private List<Product> products;

    public Category(String categoryName) {
        this.categoryName = categoryName;
        this.products = new ArrayList<>();
    }

    public String getCategoryName() {
        return categoryName;
    }

    public List<Product> getProducts() {
        return products;
    }

    public void addProduct(Product product) {
        products.add(product);
    }

    public void removeProduct(Product product) {
        products.remove(product);
    }
}

class Warehouse {
    private Map<Integer, Product> productMap;

    public Warehouse() {
        this.productMap = new HashMap<>();
    }

    public void addProduct(Product product) {
        productMap.put(product.getProductId(), product);
    }

    public void removeProduct(int productId) {
        productMap.remove(productId);
    }

    public void updateStockQuantity(int productId, int newStockQuantity) {
        Product product = productMap.get(productId);
        if (product != null) {
            product.setStockQuantity(newStockQuantity);
        }
    }

    public void generateInventoryReport() {
        System.out.println("Inventory Report:");
        for (Product product : productMap.values()) {
            System.out.println("Product ID: " + product.getProductId());
            System.out.println("Product Name: " + product.getProductName());
            System.out.println("Category: " + getCategoryName(product));
            System.out.println("Price: $" + product.getPrice());
            System.out.println("Stock Quantity: " + product.getStockQuantity());
            System.out.println("----------------------");
        }
    }

    private String getCategoryName(Product product) {
        for (Category category : productCategories) {
            if (category.getProducts().contains(product)) {
                return category.getCategoryName();
            }
        }
        return "Uncategorized";
    }

    private List<Category> productCategories = new ArrayList<>();

    public void addCategory(Category category) {
        productCategories.add(category);
    }
}


public class TestInventorySystem {
    public static void main(String[] args) {

        Product product1 = new Product(1, "Laptop", 999.99, 50);
        Product product2 = new Product(2, "Smartphone", 399.99, 100);

        Category electronicsCategory = new Category("Electronics");
        electronicsCategory.addProduct(product1);
        electronicsCategory.addProduct(product2);

        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(product1);
        warehouse.addProduct(product2);
        warehouse.addCategory(electronicsCategory);

        warehouse.updateStockQuantity(1, 45);

        warehouse.removeProduct(2);

        warehouse.generateInventoryReport();
    }
}
