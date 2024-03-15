package P6_Constructer;

import P1_ClassObject.T1_Person;

public class TestPerson {
}

class Person{
    private String name;
    private int age;

    Person(){
        this.name="Abc";
        this.age=18;
    }

    Person(String name){
        this.name=name;
        this.age=18;
    }
    Person(String name ,int age){
        this.name = name;
        this.age = age;
    }
    public void display(){
        System.out.println("Name : "+this.name);
        System.out.println("Age : "+this.age);
    }

    public static void main(String[] args) {
        Person p1 = new Person();
        Person p2 = new Person("Jane");
        Person p3 = new Person("John", 25);
        p1.display();
        p2.display();
        p3.display();
    }
}
