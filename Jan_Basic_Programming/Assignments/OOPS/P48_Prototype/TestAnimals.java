package P48_Prototype;


interface AnimalPrototype extends Cloneable {
    AnimalPrototype cloneAnimal();
    void makeSound();
}


class Dog implements AnimalPrototype {
    @Override
    public AnimalPrototype cloneAnimal() {
        return new Dog();
    }

    @Override
    public void makeSound() {
        System.out.println("Woof! Woof!");
    }
}

class Cat implements AnimalPrototype {
    @Override
    public AnimalPrototype cloneAnimal() {
        return new Cat();
    }

    @Override
    public void makeSound() {
        System.out.println("Meow!");
    }
}



public class TestAnimals {
    public static void main(String[] args) {
        AnimalPrototype dogPrototype = new Dog();
        AnimalPrototype catPrototype = new Cat();

        AnimalPrototype clonedDog = dogPrototype.cloneAnimal();
        AnimalPrototype clonedCat = catPrototype.cloneAnimal();

        System.out.println("Cloned Dog:");
        clonedDog.makeSound();

        System.out.println("\nCloned Cat:");
        clonedCat.makeSound();
    }
}
