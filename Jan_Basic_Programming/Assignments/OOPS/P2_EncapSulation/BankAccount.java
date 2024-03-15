package P2_EncapSulation;

public class BankAccount {
    private long acNo;
    private long balance;

    BankAccount(long acNo, long balance){
        this.acNo=acNo;
        this.balance=balance;
    }

    private void depositMoney(long amount){
        this.balance += amount;
        System.out.println("New Balance after deposit: "+this.balance);
    }

    private void withdrawMoney(int amount){
        this.balance -=amount;
        System.out.println("New Balance after withdrwal: "+this.balance);
    }

    public void display(){
        System.out.println("Account No. : "+this.acNo);
        System.out.println("balance : "+this.balance);
    }

    public static void main(String[] args) {
        BankAccount ac1 = new BankAccount(1234567890, 125000);
        ac1.display();

        ac1.depositMoney(25000);

        ac1.withdrawMoney(10000);

        ac1.display();
    }
}
