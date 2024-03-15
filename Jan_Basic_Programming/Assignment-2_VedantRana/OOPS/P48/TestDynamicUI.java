package P48;

import javax.swing.*;
import java.awt.*;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

// Simple UIElement class representing a GUI element
class UIElement {
    private final String type;
    private final String text;

    public UIElement(String type, String text) {
        this.type = type;
        this.text = text;
    }

    // Dynamic UI construction using reflection
    public Component createComponent() {
        try {
            // Assuming a convention: UI classes are in the same package
            Class<?> uiClass = Class.forName("your.package." + type);
            Constructor<?> constructor = uiClass.getConstructor(String.class);
            return (Component) constructor.newInstance(text);
        } catch (ClassNotFoundException | NoSuchMethodException | InstantiationException
                 | IllegalAccessException | InvocationTargetException e) {
            e.printStackTrace();
            return new JLabel("Error creating UI element");
        }
    }
}

// Example UI classes (can be extended based on your needs)
class UILabel extends JLabel {
    public UILabel(String text) {
        super(text);
    }
}

class UIButton extends JButton {
    public UIButton(String text) {
        super(text);
    }
}

// Simple UIForm class representing a dynamic UI form
class UIForm extends JFrame {
    private final JPanel panel;

    public UIForm() {
        this.panel = new JPanel();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 200);
        add(panel);
        setVisible(true);
    }

    // Add UI elements to the form
    public void addUIElement(UIElement uiElement) {
        panel.add(uiElement.createComponent());
        panel.revalidate();
        panel.repaint();
    }
}



public class TestDynamicUI {

    public static void main(String[] args) {
        // Example usage of the dynamic GUI framework
        UIForm form = new UIForm();

        UIElement labelElement = new UIElement("UILabel", "Dynamic Label");
        UIElement buttonElement = new UIElement("UIButton", "Click me!");

        form.addUIElement(labelElement);
        form.addUIElement(buttonElement);
    }
}
