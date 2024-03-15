package P8_Opertaor;

class ComplexNums{
    int real, imaginary;

    ComplexNums(int real, int imaginary){
        this.real=real;
        this.imaginary = imaginary;
    }

    ComplexNums add(ComplexNums second){
        int newReal = this.real+second.real;
        int newImag = this.imaginary+second.imaginary;

        return new ComplexNums(newReal, newImag);
    }

    public void display(){
        System.out.println("Complex no. : "+this.real+" + "+this.imaginary+"i");
    }
}
public class TestOperator {
    public static void main(String[] args) {
        ComplexNums c1 = new ComplexNums(2,3);
        ComplexNums c2 = new ComplexNums(5,4);
        ComplexNums ans = c1.add(c2);

        c1.display();
        c2.display();
        ans.display();
    }
}
