package P39_Decorator;

class TextEditor{
    private String textType;

    TextEditor(String textType){
        this.textType = textType;
    }

    public String getTextType(){
        return textType;
    }
}

interface Styles{
    String getStyle();
}

class Bold implements Styles{
    TextEditor text;

    Bold(TextEditor t1){
        this.text=t1;
    }

    @Override
    public String getStyle() {
        return text.getTextType()+" with Bold Style";
    }
}

class Italic implements Styles{
    TextEditor text;

    Italic(TextEditor t1){
        this.text=t1;
    }

    @Override
    public String getStyle() {
        return text.getTextType()+" with Italic Style";
    }
}

public class TestTextEditor {
    public static void main(String[] args) {
        TextEditor font = new TextEditor("Times New Roman");

        Styles boldFont = new Bold(font);
        System.out.println("Cuurent font : "+boldFont.getStyle());

        Styles italicFont = new Italic(font);
        System.out.println("Current Font : "+italicFont.getStyle());
    }
}
