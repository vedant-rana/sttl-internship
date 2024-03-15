package P45_AbstarctFactory;

interface Button {
    void click();
}

interface TextField {
    void inputText(String text);
}

class DesktopButton implements Button {
    @Override
    public void click() {
        System.out.println("Desktop button clicked");
    }
}

class DesktopTextField implements TextField {
    @Override
    public void inputText(String text) {
        System.out.println("Desktop text field: " + text);
    }
}


class MobileButton implements Button {
    @Override
    public void click() {
        System.out.println("Mobile button clicked");
    }
}

class MobileTextField implements TextField {
    @Override
    public void inputText(String text) {
        System.out.println("Mobile text field: " + text);
    }
}


interface UIFactory {
    Button createButton();
    TextField createTextField();
}


class DesktopUIFactory implements UIFactory {
    @Override
    public Button createButton() {
        return new DesktopButton();
    }

    @Override
    public TextField createTextField() {
        return new DesktopTextField();
    }
}

class MobileUIFactory implements UIFactory {
    @Override
    public Button createButton() {
        return new MobileButton();
    }

    @Override
    public TextField createTextField() {
        return new MobileTextField();
    }
}


public class TestUIFactory {
    public static void main(String[] args) {
        UIFactory desktopFactory = new DesktopUIFactory();


        Button desktopButton = desktopFactory.createButton();
        TextField desktopTextField = desktopFactory.createTextField();


        desktopButton.click();
        desktopTextField.inputText("Hello from desktop");

        System.out.println();


        UIFactory mobileFactory = new MobileUIFactory();


        Button mobileButton = mobileFactory.createButton();
        TextField mobileTextField = mobileFactory.createTextField();


        mobileButton.click();
        mobileTextField.inputText("Hello from mobile");
    }
}
