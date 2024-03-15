package P14;
// Existing class with an incompatible interface
class LegacyRectangle {
    public void draw(int x, int y, int width, int height) {
        System.out.println("LegacyRectangle - Drawing at (" + x + ", " + y + ") with width " + width + " and height " + height);
    }
}

// Target interface expected by the new client
interface NewRectangle {
    void draw(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY);
}

// Adapter
class LegacyRectangleAdapter implements NewRectangle {
    private LegacyRectangle legacyRectangle;

    public LegacyRectangleAdapter(LegacyRectangle legacyRectangle) {
        this.legacyRectangle = legacyRectangle;
    }

    @Override
    public void draw(int topLeftX, int topLeftY, int bottomRightX, int bottomRightY) {
        int width = bottomRightX - topLeftX;
        int height = bottomRightY - topLeftY;
        legacyRectangle.draw(topLeftX, topLeftY, width, height);
    }
}

// Client using the new interface
class Client {
    public void drawRectangle(NewRectangle rectangle) {
        rectangle.draw(10, 20, 30, 40);
    }
}

public class TestAdapterDesign {
    public static void main(String[] args) {
        LegacyRectangle legacyRectangle = new LegacyRectangle();
        NewRectangle adaptedRectangle = new LegacyRectangleAdapter(legacyRectangle);

        Client client = new Client();
        client.drawRectangle(adaptedRectangle);
    }
}
