package P43_Visitor;


interface DocumentElement {
    void accept(Visitor visitor);
}


class Paragraph implements DocumentElement {
    @Override
    public void accept(Visitor visitor) {
        visitor.visitParagraph(this);
    }


    public void display() {
        System.out.println("This is a paragraph.");
    }
}

class Image implements DocumentElement {
    @Override
    public void accept(Visitor visitor) {
        visitor.visitImage(this);
    }


    public void display() {
        System.out.println("This is an image.");
    }
}


interface Visitor {
    void visitParagraph(Paragraph paragraph);
    void visitImage(Image image);
}


class DocumentOperationVisitor implements Visitor {
    @Override
    public void visitParagraph(Paragraph paragraph) {
        System.out.println("Processing paragraph...");
        paragraph.display();

    }

    @Override
    public void visitImage(Image image) {
        System.out.println("Processing image...");
        image.display();

    }
}


public class TestDocuments {
    public static void main(String[] args) {

        DocumentElement paragraph = new Paragraph();
        DocumentElement image = new Image();


        Visitor documentOperationVisitor = new DocumentOperationVisitor();


        paragraph.accept(documentOperationVisitor);
        image.accept(documentOperationVisitor);
    }
}
