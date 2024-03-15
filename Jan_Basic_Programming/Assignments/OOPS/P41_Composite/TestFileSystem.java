package P41_Composite;

import java.util.ArrayList;
import java.util.List;


interface FileSystemComponent {
    void display();
}


class File implements FileSystemComponent {
    private String name;

    public File(String name) {
        this.name = name;
    }

    @Override
    public void display() {
        System.out.println("File: " + name);
    }
}


class Directory implements FileSystemComponent {
    private String name;
    private List<FileSystemComponent> components = new ArrayList<>();

    public Directory(String name) {
        this.name = name;
    }

    public void addComponent(FileSystemComponent component) {
        components.add(component);
    }

    @Override
    public void display() {
        System.out.println("Directory: " + name);
        for (FileSystemComponent component : components) {
            component.display();
        }
    }
}




public class TestFileSystem {
    public static void main(String[] args) {
        FileSystemComponent file1 = new File("Document.txt");
        FileSystemComponent file2 = new File("Image.jpg");
        FileSystemComponent file3 = new File("Code.java");

        
        Directory rootDirectory = new Directory("Root");
        Directory documentsDirectory = new Directory("Documents");
        Directory imagesDirectory = new Directory("Images");

        
        rootDirectory.addComponent(documentsDirectory);
        rootDirectory.addComponent(imagesDirectory);
        documentsDirectory.addComponent(file1);
        imagesDirectory.addComponent(file2);
        rootDirectory.addComponent(file3);

        
        rootDirectory.display();
    }
}
