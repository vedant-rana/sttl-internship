package P4_Polymorphism;

interface Shape{
     void calculateArea();
}

class Rectangle implements Shape {
    int l,w;

    Rectangle(int l, int w){
        this.l=l;
        this.w=w;
    }

    @Override
    public void calculateArea() {
        System.out.println("Rectangle Area : "+(l*w));
    }

}

class Circle implements Shape {
    int r;

    Circle(int r){
        this.r=r;
    }

    @Override
    public void calculateArea() {
        System.out.println("circle Area : "+(3.14*r*r));
    }

}

public class TestShape {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle(5,6);
        r1.calculateArea();

        Circle c1 = new Circle(5);
        c1.calculateArea();
    }
}


