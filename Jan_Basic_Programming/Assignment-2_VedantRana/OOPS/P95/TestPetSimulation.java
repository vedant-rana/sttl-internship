package P95;

class Pet {
    private String name;
    private int health;
    private int happiness;

    public Pet(String name) {
        this.name = name;
        this.health = 100; // Initial health
        this.happiness = 100; // Initial happiness
    }

    public String getName() {
        return name;
    }

    public int getHealth() {
        return health;
    }

    public int getHappiness() {
        return happiness;
    }

    public void feed(Food food) {
        int nutritionValue = food.getNutritionValue();
        health = Math.min(100, health + nutritionValue); // Ensure health doesn't exceed 100
        happiness = Math.min(100, happiness + 10); // Increase happiness when fed
    }

    public void play() {
        happiness = Math.min(100, happiness + 20); // Increase happiness when played with
    }

    public void takeCare() {
        health = Math.min(100, health + 5); // Taking care of the pet slightly improves health
    }
}

class Food {
    private String name;
    private int nutritionValue;

    public Food(String name, int nutritionValue) {
        this.name = name;
        this.nutritionValue = nutritionValue;
    }

    public String getName() {
        return name;
    }

    public int getNutritionValue() {
        return nutritionValue;
    }
}

class Owner {
    private String name;
    private Pet pet;

    public Owner(String name, Pet pet) {
        this.name = name;
        this.pet = pet;
    }

    public void feedPet(Food food) {
        pet.feed(food);
    }

    public void playWithPet() {
        pet.play();
    }

    public void takeCareOfPet() {
        pet.takeCare();
    }

    public void checkPetStatus() {
        System.out.println("Pet Status for " + pet.getName() + ":");
        System.out.println("Health: " + pet.getHealth());
        System.out.println("Happiness: " + pet.getHappiness());
        System.out.println("----------------------");
    }
}


public class TestPetSimulation {
    public static void main(String[] args) {
        Pet myPet = new Pet("Fluffy");
        Owner owner = new Owner("John", myPet);
        Food petFood = new Food("Dog Food", 15);


        owner.feedPet(petFood);
        owner.playWithPet();
        owner.takeCareOfPet();


        owner.checkPetStatus();
    }
}
