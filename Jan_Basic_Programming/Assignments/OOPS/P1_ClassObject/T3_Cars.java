package P1_ClassObject;

public class T3_Cars {
    String company;
    String model;
    int year;

    T3_Cars(String company, String model, int year){
        this.company=company;
        this.model = model;
        this.year = year;
    }

    public void display(){
        System.out.println("Company : "+this.company+"\nModel : "+this.model+"\nYear : "+this.year);
    }

    public static void main(String[] args) {
        T3_Cars c1 = new T3_Cars("Tesla", "T1", 2023);
        c1.display();
    }
}
