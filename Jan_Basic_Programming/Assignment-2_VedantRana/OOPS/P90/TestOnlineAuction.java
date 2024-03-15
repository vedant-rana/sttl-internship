package P90;

import java.util.ArrayList;
import java.util.List;

class Auction {
    private List<Item> items;
    private List<Bidder> bidders;

    public Auction() {
        this.items = new ArrayList<>();
        this.bidders = new ArrayList<>();
    }

    public void createAuction(Item item) {
        items.add(item);
    }

    public void addBidder(Bidder bidder) {
        bidders.add(bidder);
    }

    public List<Item> getItems() {
        return items;
    }

    public List<Bidder> getBidders() {
        return bidders;
    }
}

class Item {
    private String name;
    private double currentBid;

    public Item(String name) {
        this.name = name;
        this.currentBid = 0.0;
    }

    public String getName() {
        return name;
    }

    public double getCurrentBid() {
        return currentBid;
    }

    public void placeBid(double amount) {
        if (amount > currentBid) {
            currentBid = amount;
        }
    }
}

class Bidder {
    private String name;

    public Bidder(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void bid(Item item, double amount) {
        item.placeBid(amount);
    }
}

public class TestOnlineAuction {
    public static void main(String[] args) {
        Auction auction = new Auction();

        Item laptop = new Item("Laptop");
        Item painting = new Item("Painting");

        auction.createAuction(laptop);
        auction.createAuction(painting);

        Bidder bidder1 = new Bidder("Bidder1");
        Bidder bidder2 = new Bidder("Bidder2");

        auction.addBidder(bidder1);
        auction.addBidder(bidder2);

        bidder1.bid(laptop, 500.0);
        bidder2.bid(laptop, 600.0);

        bidder1.bid(painting, 200.0);
        bidder2.bid(painting, 300.0);

        for (Item item : auction.getItems()) {
            System.out.println("Item: " + item.getName() + ", Current Bid: $" + item.getCurrentBid());
        }
    }
}
