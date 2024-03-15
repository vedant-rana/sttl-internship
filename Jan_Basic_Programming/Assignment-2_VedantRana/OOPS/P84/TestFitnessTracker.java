package P84;

import java.util.ArrayList;
import java.util.List;

class Activity {
    private String name;
    private int durationInMinutes;
    private double distanceInKilometers;
    private int caloriesBurned;

    public Activity(String name, int durationInMinutes, double distanceInKilometers, int caloriesBurned) {
        this.name = name;
        this.durationInMinutes = durationInMinutes;
        this.distanceInKilometers = distanceInKilometers;
        this.caloriesBurned = caloriesBurned;
    }

    public String getName() {
        return name;
    }

    public int getDurationInMinutes() {
        return durationInMinutes;
    }

    public double getDistanceInKilometers() {
        return distanceInKilometers;
    }

    public int getCaloriesBurned() {
        return caloriesBurned;
    }
}

class User {
    private String username;
    private List<Activity> activities;
    private int dailyGoal;

    public User(String username, int dailyGoal) {
        this.username = username;
        this.activities = new ArrayList<>();
        this.dailyGoal = dailyGoal;
    }

    public String getUsername() {
        return username;
    }

    public void addActivity(Activity activity) {
        activities.add(activity);
    }

    public List<Activity> getActivities() {
        return activities;
    }

    public int getDailyGoal() {
        return dailyGoal;
    }

    public void setDailyGoal(int dailyGoal) {
        this.dailyGoal = dailyGoal;
    }

    public boolean hasReachedDailyGoal() {
        int totalCaloriesBurned = activities.stream().mapToInt(Activity::getCaloriesBurned).sum();
        return totalCaloriesBurned >= dailyGoal;
    }
}

class Tracker {
    private List<User> users;

    public Tracker() {
        this.users = new ArrayList<>();
    }

    public void addUser(User user) {
        users.add(user);
    }

    public List<User> getUsers() {
        return users;
    }

    public void generateActivityReport(User user) {
        System.out.println("Activity report for user: " + user.getUsername());
        System.out.println("Daily goal: " + user.getDailyGoal() + " calories");

        List<Activity> activities = user.getActivities();
        for (Activity activity : activities) {
            System.out.println("- " + activity.getName() + ": " +
                    "Duration: " + activity.getDurationInMinutes() + " mins, " +
                    "Distance: " + activity.getDistanceInKilometers() + " km, " +
                    "Calories burned: " + activity.getCaloriesBurned() + " calories");
        }

        if (user.hasReachedDailyGoal()) {
            System.out.println("Congratulations! Daily goal reached.");
        } else {
            System.out.println("Keep it up! You're making progress towards your goal.");
        }
        System.out.println();
    }
}

public class TestFitnessTracker {
    public static void main(String[] args) {
        User user1 = new User("Alice", 500);
        User user2 = new User("Bob", 700);

        Activity running = new Activity("Running", 30, 5.0, 300);
        Activity cycling = new Activity("Cycling", 45, 15.0, 400);

        user1.addActivity(running);
        user1.addActivity(cycling);

        Activity swimming = new Activity("Swimming", 60, 1.5, 500);
        user2.addActivity(swimming);

        Tracker fitnessTracker = new Tracker();
        fitnessTracker.addUser(user1);
        fitnessTracker.addUser(user2);

        for (User user : fitnessTracker.getUsers()) {
            fitnessTracker.generateActivityReport(user);
        }
    }
}
