package P83;

import java.util.ArrayList;
import java.util.List;

class Instrument {
    private String name;
    private String type;
    private double price;
    private boolean available;

    public Instrument(String name, String type, double price) {
        this.name = name;
        this.type = type;
        this.price = price;
        this.available = true;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public double getPrice() {
        return price;
    }

    public boolean isAvailable() {
        return available;
    }

    public void sell() {
        available = false;
    }
}

class Musician {
    private String name;
    private List<Instrument> instruments;

    public Musician(String name) {
        this.name = name;
        this.instruments = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void addInstrument(Instrument instrument) {
        instruments.add(instrument);
    }

    public List<Instrument> getInstruments() {
        return instruments;
    }
}

class Inventory {
    private List<Instrument> instruments;

    public Inventory() {
        this.instruments = new ArrayList<>();
    }

    public void addInstrument(Instrument instrument) {
        instruments.add(instrument);
    }

    public List<Instrument> getInstruments() {
        return instruments;
    }

    public void sellInstrument(Instrument instrument) {
        if (instrument.isAvailable()) {
            instrument.sell();
        } else {
            System.out.println("Instrument " + instrument.getName() + " is not available for sale.");
        }
    }
}


public class TestMusicInstrument {
    public static void main(String[] args) {
        Inventory musicStoreInventory = new Inventory();

        Instrument guitar = new Instrument("Acoustic Guitar", "String", 500.0);
        Instrument trumpet = new Instrument("Trumpet", "Brass", 800.0);

        musicStoreInventory.addInstrument(guitar);
        musicStoreInventory.addInstrument(trumpet);

        Musician musician1 = new Musician("John");
        Musician musician2 = new Musician("Jane");

        musician1.addInstrument(guitar);
        musician2.addInstrument(trumpet);

        musicStoreInventory.sellInstrument(guitar);
        musicStoreInventory.sellInstrument(trumpet);

        for (Instrument instrument : musicStoreInventory.getInstruments()) {
            System.out.println("Instrument: " + instrument.getName() +
                    ", Type: " + instrument.getType() +
                    ", Price: $" + instrument.getPrice() +
                    ", Available: " + instrument.isAvailable());
        }

        for (Musician musician : List.of(musician1, musician2)) {
            System.out.println(musician.getName() + "'s Instruments:");
            for (Instrument instrument : musician.getInstruments()) {
                System.out.println("- " + instrument.getName() + " (" + instrument.getType() + ")");
            }
        }
    }
}
