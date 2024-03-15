package P37_AbstractFactory;


interface Chair {
    void sitOn();
}

interface Sofa {
    void relaxOn();
}


class ModernChair implements Chair {
    @Override
    public void sitOn() {
        System.out.println("Sitting on a modern chair");
    }
}

class ModernSofa implements Sofa {
    @Override
    public void relaxOn() {
        System.out.println("Relaxing on a modern sofa");
    }
}

class VictorianChair implements Chair {
    @Override
    public void sitOn() {
        System.out.println("Sitting on a Victorian chair");
    }
}

class VictorianSofa implements Sofa {
    @Override
    public void relaxOn() {
        System.out.println("Relaxing on a Victorian sofa");
    }
}


interface FurnitureFactory {
    Chair createChair();
    Sofa createSofa();
}


class ModernFurnitureFactory implements FurnitureFactory {
    @Override
    public Chair createChair() {
        return new ModernChair();
    }

    @Override
    public Sofa createSofa() {
        return new ModernSofa();
    }
}

class VictorianFurnitureFactory implements FurnitureFactory {
    @Override
    public Chair createChair() {
        return new VictorianChair();
    }

    @Override
    public Sofa createSofa() {
        return new VictorianSofa();
    }
}



public class TestFurnitureFactory {
    public static void main(String[] args) {

        FurnitureFactory modernFactory = new ModernFurnitureFactory();
        Chair modernChair = modernFactory.createChair();
        Sofa modernSofa = modernFactory.createSofa();


        FurnitureFactory victorianFactory = new VictorianFurnitureFactory();
        Chair victorianChair = victorianFactory.createChair();
        Sofa victorianSofa = victorianFactory.createSofa();


        modernChair.sitOn();
        modernSofa.relaxOn();

        System.out.println();

        victorianChair.sitOn();
        victorianSofa.relaxOn();
    }
}
