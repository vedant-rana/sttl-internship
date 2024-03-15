//package P18;
//
//// Domain Entity
//class Order {
//    private final String orderId;
//    private List<OrderItem> orderItems;
//
//    public Order(String orderId) {
//        this.orderId = orderId;
//        this.orderItems = new ArrayList<>();
//    }
//
//    public String getOrderId() {
//        return orderId;
//    }
//
//    public void addOrderItem(Product product, int quantity) {
//        OrderItem orderItem = new OrderItem(product, quantity);
//        orderItems.add(orderItem);
//    }
//
//    // Other domain logic, validations, and behaviors
//}
//
//// Value Object
//class Product {
//    private final String productId;
//    private final String name;
//
//    public Product(String productId, String name) {
//        this.productId = productId;
//        this.name = name;
//    }
//
//    // Getters
//}
//
//// Aggregate
//class OrderItem {
//    private final Product product;
//    private final int quantity;
//
//    public OrderItem(Product product, int quantity) {
//        this.product = product;
//        this.quantity = quantity;
//    }
//
//    // Getters
//}
//
//// Repository
//class OrderRepository {
//    private final Map<String, Order> orderStore = new HashMap<>();
//
//    public void save(Order order) {
//        orderStore.put(order.getOrderId(), order);
//    }
//
//    public Order findById(String orderId) {
//        return orderStore.get(orderId);
//    }
//}
//
//// Service
//class OrderService {
//    private final OrderRepository orderRepository;
//
//    public OrderService(OrderRepository orderRepository) {
//        this.orderRepository = orderRepository;
//    }
//
//    public void createOrder(String orderId, Product product, int quantity) {
//        Order order = new Order(orderId);
//        order.addOrderItem(product, quantity);
//        orderRepository.save(order);
//    }
//
//    public Order getOrderById(String orderId) {
//        return orderRepository.findById(orderId);
//    }
//}
//
//
//public class TestDDDSystem {
//}
