package P1_ClassObject;

public class T1_Person {
    private String name;
    private int age;

    T1_Person(String name ,int age){
        this.name = name;
        this.age = age;
    }
    public void display(){
        System.out.println("Name : "+this.name);
        System.out.println("Age : "+this.age);
    }

    public static void main(String[] args) {
        T1_Person p1 = new T1_Person("John", 25);
        p1.display();
    }
}

