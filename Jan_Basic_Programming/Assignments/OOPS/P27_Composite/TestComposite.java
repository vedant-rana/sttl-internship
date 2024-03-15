package P27_Composite;


import java.util.ArrayList;
import java.util.List;

interface Component {
    void display();
}

class Leaf implements Component {
    private String name;

    public Leaf(String name) {
        this.name = name;
    }

    @Override
    public void display() {
        System.out.println("Leaf: " + name);
    }
}

class Composite implements Component {
    private String name;
    private List<Component> components = new ArrayList<>();

    public Composite(String name) {
        this.name = name;
    }

    public void addComponent(Component component) {
        components.add(component);
    }

    public void removeComponent(Component component) {
        components.remove(component);
    }

    @Override
    public void display() {
        System.out.println("Composite: " + name);
        for (Component component : components) {
            component.display();
        }
    }
}


public class TestComposite {
    public static void main(String[] args) {

        Component leaf1 = new Leaf("Leaf 1");
        Component leaf2 = new Leaf("Leaf 2");
        Component leaf3 = new Leaf("Leaf 3");

        Composite composite1 = new Composite("Composite 1");
        Composite composite2 = new Composite("Composite 2");

         composite1.addComponent(leaf1);
        composite1.addComponent(leaf2);

        composite2.addComponent(leaf3);
        composite2.addComponent(composite1);

        composite2.display();
    }
}
