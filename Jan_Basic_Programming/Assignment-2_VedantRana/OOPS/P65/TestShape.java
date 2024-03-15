package P65;


import java.util.ArrayList;
import java.util.List;

abstract class Shape {
    abstract double calculateArea();
    abstract void draw();
}

class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    double calculateArea() {
        return Math.PI * radius * radius;
    }

    @Override
    void draw() {
        System.out.println("Drawing Circle");
    }
}

class Rectangle extends Shape {
    private double length;
    private double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    double calculateArea() {
        return length * width;
    }

    @Override
    void draw() {
        System.out.println("Drawing Rectangle");
    }
}

class Triangle extends Shape {
    private double base;
    private double height;

    public Triangle(double base, double height) {
        this.base = base;
        this.height = height;
    }

    @Override
    double calculateArea() {
        return 0.5 * base * height;
    }

    @Override
    void draw() {
        System.out.println("Drawing Triangle");
    }
}

class Drawing {
    private List<Shape> shapes;

    public Drawing() {
        this.shapes = new ArrayList<>();
    }

    public void addShape(Shape shape) {
        shapes.add(shape);
    }

    public void drawShapes() {
        for (Shape shape : shapes) {
            shape.draw();
        }
    }

    public double calculateTotalArea() {
        double totalArea = 0;
        for (Shape shape : shapes) {
            totalArea += shape.calculateArea();
        }
        return totalArea;
    }
}

public class TestShape {
    public static void main(String[] args) {
        Drawing drawing = new Drawing();

        Circle circle = new Circle(5.0);
        Rectangle rectangle = new Rectangle(4.0, 6.0);
        Triangle triangle = new Triangle(3.0, 4.0);

        drawing.addShape(circle);
        drawing.addShape(rectangle);
        drawing.addShape(triangle);

        drawing.drawShapes();

        System.out.println("Total Area: " + drawing.calculateTotalArea());
    }
}
