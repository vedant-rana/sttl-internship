package P18_FactoryMethor;

interface Document{
    void print();
}

class PDFDocument implements Document{
    @Override
    public void print(){
        System.out.println("Pdf Document");
    }
}

class WordDocument implements Document{
    @Override
    public void print(){
        System.out.println("Word document");
    }
}


class DocumentFactory{
    public static Document getDocument(String DocType)
    {
        if(DocType.trim().equalsIgnoreCase("WORD")){
            return new WordDocument();
        }
        else if(DocType.trim().equalsIgnoreCase("PDF")){
            return new PDFDocument();
        }
        else{
            return null;
        }
    }
}

public class TestFactory {
        public static void main(String[] args) {
            Document d1 = DocumentFactory.getDocument("WORD");
            Document d2 = DocumentFactory.getDocument("PDF");
            d1.print();
            d2.print();
    }

}
