package P12_Interface;

interface Drawable{
    void draw();
}

class Circle implements Drawable{
    @Override
    public void draw() {
        System.out.println("Circle can be Drawn.");
    }
}

class Rectangle implements Drawable{
    @Override
    public void draw() {
        System.out.println("Rectangle can be Drawn.");
    }
}

public class TestDrwable {
    public static void main(String[] args) {
        Rectangle r1= new Rectangle();
        Circle c1= new Circle();

        r1.draw();

        c1.draw();
    }
}
