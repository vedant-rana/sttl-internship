package P14_Observer;

import java.util.ArrayList;


//Observer interface implement by instagram users object to follow stars
//observer will continuously observe the stars to get notification
interface Observer{
    void update(String message);
}

class User1 implements Observer{
    @Override
    public void update(String message) {
        System.out.println("User 1 gets : "+message);
    }
}

class User2 implements Observer{
    @Override
    public void update(String message) {
        System.out.println("User 2 gets : "+message);
    }
}

class User3 implements Observer{
    @Override
    public void update(String message) {
        System.out.println("User 3 gets : "+message);
    }
}


//Account is like instagram's stars who when posts then insta sends their notifications to users
interface Account{
    void follow(Observer o);
    void unFollow(Observer o);
    void getNotified(String message);
}

class StarAccount1 implements Account{
    ArrayList<Observer> followers;

    StarAccount1(){
        this.followers = new ArrayList<Observer>();
    }

    @Override
    public void follow(Observer o) {
        this.followers.add(o);
    }

    @Override
    public void unFollow(Observer o) {
        int i = followers.indexOf(o);
        if(i>=0){
            this.followers.remove(i);
        }
    }

    @Override
    public void getNotified(String message) {
        for(Observer o: followers){
            o.update(message);
        }
    }

    void newPostAdded(String message){
        getNotified(message);
    }
}

class StarAccount2 implements Account{
    ArrayList<Observer> followers;

    StarAccount2(){
        this.followers = new ArrayList<Observer>();
    }

    @Override
    public void follow(Observer o) {
        followers.add(o);
    }

    @Override
    public void unFollow(Observer o) {
        int i = followers.indexOf(o);
        if(i>=0){
            followers.remove(i);
        }
    }

    @Override
    public void getNotified(String message) {
        for(Observer o: followers){
            o.update(message);
        }
    }

    void newPostAdded(String message){
        getNotified(message);
    }
}

public class TestInstagram {
    public static void main(String[] args) {
        //suppose there are two stars and 3 users who follow stars
        StarAccount1 s1 = new StarAccount1();
        StarAccount2 s2 = new StarAccount2();

        User1 u1 = new User1();
        User2 u2 = new User2();
        User3 u3 = new User3();

        s1.follow(u1);
        s1.follow(u2);

        s2.follow(u3);
        s2.follow(u1);

        //send notifications to all follwers
        s1.newPostAdded("Diwali Post Added by Star 1");
        s2.newPostAdded("Christmas post Added by Star 2");
    }
}
