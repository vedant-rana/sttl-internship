package P12;

import java.util.HashMap;
import java.util.Map;

// Flyweight interface
interface CoffeeOrder {
    void serveCoffee(CoffeeContext context);
}

// ConcreteFlyweight
class CoffeeFlavor implements CoffeeOrder {
    private final String flavor;

    public CoffeeFlavor(String flavor) {
        this.flavor = flavor;
    }

    @Override
    public void serveCoffee(CoffeeContext context) {
        System.out.println("Serving coffee flavor: " + flavor + " to table number " + context.getTableNumber());
    }
}

// Context
class CoffeeContext {
    private final int tableNumber;

    public CoffeeContext(int tableNumber) {
        this.tableNumber = tableNumber;
    }

    public int getTableNumber() {
        return tableNumber;
    }
}

// FlyweightFactory
class CoffeeFlavorFactory {
    private final Map<String, CoffeeFlavor> flavors = new HashMap<>();

    public CoffeeFlavor getCoffeeFlavor(String flavor) {
        CoffeeFlavor coffeeFlavor = flavors.get(flavor);

        if (coffeeFlavor == null) {
            coffeeFlavor = new CoffeeFlavor(flavor);
            flavors.put(flavor, coffeeFlavor);
        }

        return coffeeFlavor;
    }
}

public class TestFlyWeight {
    public static void main(String[] args) {
        CoffeeFlavorFactory flavorFactory = new CoffeeFlavorFactory();

        // Order coffee for multiple tables
        CoffeeOrder order1 = flavorFactory.getCoffeeFlavor("Cappuccino");
        order1.serveCoffee(new CoffeeContext(1));

        CoffeeOrder order2 = flavorFactory.getCoffeeFlavor("Espresso");
        order2.serveCoffee(new CoffeeContext(2));

        CoffeeOrder order3 = flavorFactory.getCoffeeFlavor("Cappuccino");
        order3.serveCoffee(new CoffeeContext(3));

        CoffeeOrder order4 = flavorFactory.getCoffeeFlavor("Latte");
        order4.serveCoffee(new CoffeeContext(4));
    }
}
