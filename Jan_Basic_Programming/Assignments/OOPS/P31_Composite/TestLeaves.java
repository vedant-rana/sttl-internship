package P31_Composite;


interface Component {
    void add(Component component);
    void remove(Component component);
    void display();
}


class Leaf implements Component {
    private String name;

    public Leaf(String name) {
        this.name = name;
    }

    @Override
    public void add(Component component) {
        
        System.out.println("Cannot add to a leaf");
    }

    @Override
    public void remove(Component component) {
        System.out.println("Cannot remove from a leaf");
    }

    @Override
    public void display() {
        System.out.println("Leaf: " + name);
    }
}

class Composite implements Component {
    private java.util.List<Component> components = new java.util.ArrayList<>();

    @Override
    public void add(Component component) {
        components.add(component);
    }

    @Override
    public void remove(Component component) {
        components.remove(component);
    }

    @Override
    public void display() {
        System.out.println("Composite:");
        for (Component component : components) {
            component.display();
        }
    }
}



public class TestLeaves {
    public static void main(String[] args) {

        Component leaf1 = new Leaf("Leaf 1");
        Component leaf2 = new Leaf("Leaf 2");
        Component leaf3 = new Leaf("Leaf 3");


        Component composite1 = new Composite();
        Component composite2 = new Composite();


        composite1.add(leaf1);
        composite1.add(leaf2);

        composite1.display();

        composite2.add(leaf3);
        composite2.add(leaf1);


        composite2.display();

        composite2.remove(leaf3);
        composite2.display();
    }
}
