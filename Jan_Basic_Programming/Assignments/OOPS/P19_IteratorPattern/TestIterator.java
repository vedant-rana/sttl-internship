package P19_IteratorPattern;

import java.util.ArrayList;
import java.util.List;


interface Iterator<T> {
    boolean hasNext();
    T next();
}


interface Collection<T> {
    Iterator<T> iterator();
}


class CustomIterator<T> implements Iterator<T> {
    private List<T> elements;
    private int position;

    public CustomIterator(List<T> elements) {
        this.elements = elements;
        this.position = 0;
    }

    @Override
    public boolean hasNext() {
        return position < elements.size();
    }

    @Override
    public T next() {
        if (hasNext()) {
            return elements.get(position++);
        } else {
            throw new IndexOutOfBoundsException("No more elements");
        }
    }
}


class CustomCollection<T> implements Collection<T> {
    private List<T> elements;

    public CustomCollection() {
        this.elements = new ArrayList<>();
    }

    public void addElement(T element) {
        elements.add(element);
    }

    @Override
    public Iterator<T> iterator() {
        return new CustomIterator<>(elements);
    }
}

public class TestIterator {
    public static void main(String[] args) {
        CustomCollection<String> collection = new CustomCollection<>();
        collection.addElement("Abc");
        collection.addElement("Def");
        collection.addElement("Mno");

        Iterator<String> iterator = collection.iterator();

        while (iterator.hasNext()) {
            String element = iterator.next();
            System.out.print( element+", ");
        }
    }
}
