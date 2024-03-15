package P16_Strategy;

interface PaymentStrategy{
    void pay(int amount);
}

class CreditCard implements PaymentStrategy{
    double cardNo;
    String name;

    CreditCard(double cardNo, String name){
        this.cardNo=cardNo;
        this.name = name;
    }

    @Override
    public void pay(int amount) {
        System.out.println(amount + " paid by Credit card No. : "+this.cardNo);
    }
}

class PayPalStretegy implements PaymentStrategy{
    String email;

    PayPalStretegy(String email){
        this.email = email;
    }

    @Override
    public void pay(int amount) {
        System.out.println(amount+" paid by PayPal with email: "+this.email);
    }
}

class Billing {
    private PaymentStrategy paymentMethod;

    public void setPaymentMethod(PaymentStrategy paymentMethod){
        this.paymentMethod = paymentMethod;
    }

    public void payBill(int amount){
        if(paymentMethod == null){
            System.out.println("Select Appropriate Payment method");
        }else{
            paymentMethod.pay(amount);
        }
    }
}

public class TestStrategy {
    public static void main(String[] args) {
        PaymentStrategy paypal = new PayPalStretegy("abc@gmail.com");

        Billing bill1 = new Billing();
        bill1.payBill(1000);

        bill1.setPaymentMethod(paypal);
        bill1.payBill(1000);



        PaymentStrategy creditCard = new CreditCard(12345678, "mr. John");
        Billing bill2 = new Billing();
        bill2.setPaymentMethod(creditCard);
        bill2.payBill(2000);
    }
}
