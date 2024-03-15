package P34_Proxy;



interface CostlyResource {
    void performOperation();
}


class RealCostlyResource implements CostlyResource {
    public RealCostlyResource() {
        initializeResource();
    }

    private void initializeResource() {

        System.out.println("Initializing the costly resource");
    }

    @Override
    public void performOperation() {

        System.out.println("Performing a costly operation");
    }
}


class CostlyResourceProxy implements CostlyResource {
    private RealCostlyResource realResource;

    @Override
    public void performOperation() {
        if (realResource == null) {
            realResource = new RealCostlyResource();
        }


        if (someCondition()) {
            realResource.performOperation();
        } else {
            System.out.println("Access to the costly resource denied.");
        }
    }

    private boolean someCondition() {
        return true;
    }
}



public class TestProxy {
    public static void main(String[] args) {
        CostlyResource proxy = new CostlyResourceProxy();

        proxy.performOperation();
    }
}
