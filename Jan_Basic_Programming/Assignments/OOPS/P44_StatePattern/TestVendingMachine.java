package P44_StatePattern;


interface CoinState{
    void insertCoin();
    void ejectCoin();
    void selectProduct();
}

class NoCoinState implements CoinState{
    @Override
    public void insertCoin() {
        System.out.println("Coin inserted in Machine.");
        VendingMachineContext.setState(new HasCoinState());
    }

    @Override
    public void ejectCoin() {
        System.out.println("NO coin in machine.");
    }

    @Override
    public void selectProduct() {
        System.out.println("Please insert coin first.");
    }
}

class HasCoinState implements CoinState{
    @Override
    public void insertCoin() {
        System.out.println("Coin already injected.");
    }

    @Override
    public void ejectCoin() {
        System.out.println("Coin ejected successfully");
        VendingMachineContext.setState(new NoCoinState());
    }

    @Override
    public void selectProduct() {
        System.out.println("Product selected Successfully.");
        VendingMachineContext.setState(new NoCoinState());

    }
}

class VendingMachineContext{
    private static CoinState currentState;

    static {
        currentState = new NoCoinState();
    }

    public static CoinState getState(){
        return currentState;
    }

    public static void setState(CoinState state){
        currentState = state;
    }

}

public class TestVendingMachine {
    public static void main(String[] args) {
        VendingMachineContext.getState().selectProduct();
        VendingMachineContext.getState().insertCoin();
        VendingMachineContext.getState().selectProduct();
        VendingMachineContext.getState().ejectCoin();
    }
}
