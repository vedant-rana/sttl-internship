package P5_Abstraction;

abstract class Animal{
    abstract  void eat();
    abstract void sound();
}

class Dog extends Animal{
    @Override
    void eat() {
        System.out.println("Dog can eat");
    }

    @Override
    void sound() {
        System.out.println("Dog is barking");
    }
}

class Cat extends Animal{
    @Override
    void eat() {
        System.out.println("Cat can Eat.");
    }

    @Override
    void sound() {
        System.out.println("Cat can't Bark.");
    }
}
public class TestAnimal {
    public static void main(String[] args) {
        Dog d1 = new Dog();
        d1.eat();
        d1.sound();

        Cat c1 = new Cat();
        c1.eat();
        c1.sound();
    }

}
