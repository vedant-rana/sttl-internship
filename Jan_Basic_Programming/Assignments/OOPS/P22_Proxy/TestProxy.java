package P22_Proxy;


interface Image {
    void display();
}


class RealImage implements Image {
    private String filename;

    public RealImage(String filename) {
        this.filename = filename;
        loadImageFromDisk();
    }

    private void loadImageFromDisk() {
        System.out.println("Loading image from disk: " + filename);
    }

    @Override
    public void display() {
        System.out.println("Displaying image: " + filename);
    }
}


class ProxyImage implements Image {
    private RealImage realImage;
    private String filename;

    public ProxyImage(String filename) {
        this.filename = filename;
    }

    @Override
    public void display() {
        if (realImage == null) {

            realImage = new RealImage(filename);
        }
        realImage.display();
    }
}


public class TestProxy {
    public static void main(String[] args) {

        Image image1 = new ProxyImage("image1.jpg");
       image1.display();


        Image image2 = new ProxyImage("image2.png");
        image2.display();
    }
}
