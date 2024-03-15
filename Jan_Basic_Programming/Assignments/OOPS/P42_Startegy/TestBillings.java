package P42_Startegy;



interface BillingStrategy {
    double calculateBill(double rawPrice);
}


class NormalBilling implements BillingStrategy {
    @Override
    public double calculateBill(double rawPrice) {
        return rawPrice;
    }
}

class DiscountBilling implements BillingStrategy {
    private double discountPercentage;

    public DiscountBilling(double discountPercentage) {
        this.discountPercentage = discountPercentage;
    }

    @Override
    public double calculateBill(double rawPrice) {
        return rawPrice * (1 - discountPercentage / 100);
    }
}


class BillingContext {
    private BillingStrategy billingStrategy;

    public BillingContext(BillingStrategy billingStrategy) {
        this.billingStrategy = billingStrategy;
    }

    public void setBillingStrategy(BillingStrategy billingStrategy) {
        this.billingStrategy = billingStrategy;
    }

    public double calculateFinalBill(double rawPrice) {
        return billingStrategy.calculateBill(rawPrice);
    }
}


public class TestBillings {
    public static void main(String[] args) {
        BillingStrategy normalBilling = new NormalBilling();
        BillingStrategy discountBilling = new DiscountBilling(10);

        BillingContext billingContext = new BillingContext(normalBilling);

        double rawPrice = 100.0;

        System.out.println("Final Bill with Normal Billing: ₹" + billingContext.calculateFinalBill(rawPrice));

        billingContext.setBillingStrategy(discountBilling);
        System.out.println("Final Bill with Discount Billing: ₹" + billingContext.calculateFinalBill(rawPrice));
    }
}
