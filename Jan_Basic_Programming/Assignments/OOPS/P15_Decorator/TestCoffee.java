package P15_Decorator;

class Coffee{
    int price;
    String description;

    Coffee(){
        price = 50;
        description = "Plain Coffee";
    }

    public int getCost(){
        return price;
    }

    public String getDescription(){
        return description;
    }
}


abstract class CoffeeDecorator{
    abstract int getCost();
    abstract String getDescription();
}

class Milk extends CoffeeDecorator{

    Coffee c ;

    Milk(Coffee c1){
        this.c= c1;
    }
    @Override
    int getCost() {
        return c.getCost() + 30;
    }

    @Override
    String getDescription() {
        return c.getDescription()+" with Milk.";
    }
}

class Sugar extends CoffeeDecorator{

    Coffee c ;

    Sugar(Coffee c1){
        this.c= c1;
    }
    @Override
    int getCost() {
        return c.getCost() + 20;
    }

    @Override
    String getDescription() {
        return c.getDescription()+" with Sugar.";
    }
}

public class TestCoffee {
    public static void main(String[] args) {
        Coffee simple = new Coffee();
        displayCoffee(simple);

        Coffee milkCoffee = new Coffee();
        CoffeeDecorator milk = new Milk(milkCoffee);
        displayDecoratedCoffee(milk);

        Coffee sugarCoffee = new Coffee();
        CoffeeDecorator sugar = new Sugar(sugarCoffee);
        displayDecoratedCoffee(sugar);

    }

    public static void displayCoffee(Coffee c){
        System.out.println("Coffee Price : "+c.getCost());
        System.out.println("Added : "+c.getDescription());
    }

    public static void displayDecoratedCoffee(CoffeeDecorator c){
        System.out.println("\nCoffee Price : "+c.getCost());
        System.out.println("Added : "+c.getDescription());
    }
}
