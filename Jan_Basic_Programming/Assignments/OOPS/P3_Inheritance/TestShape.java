package P3_Inheritance;

class Shape{
    public void calculateArea(){

    }
    public void calculatePeri(){

    }
}

class Rectangle extends Shape{
    int l,w;

    Rectangle(int l, int w){
        this.l=l;
        this.w=w;
    }

    @Override
    public void calculateArea() {
        System.out.println("Rectangle Area : "+(l*w));
    }

    @Override
    public void calculatePeri() {
        System.out.println("Rectangle Perimeter : "+(2*(l+w)));
    }
}

class Circle extends Shape{
    int r;

    Circle(int r){
        this.r=r;
    }

    @Override
    public void calculateArea() {
        System.out.println("circle Area : "+(3.14*r*r));
    }

    @Override
    public void calculatePeri() {
        System.out.println("Circle Perimeter : "+(2*3.14*r));
    }
}

public class TestShape {
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle(5,6);
        r1.calculateArea();
        r1.calculatePeri();

        Circle c1 = new Circle(5);
        c1.calculateArea();
        c1.calculatePeri();
    }
}
