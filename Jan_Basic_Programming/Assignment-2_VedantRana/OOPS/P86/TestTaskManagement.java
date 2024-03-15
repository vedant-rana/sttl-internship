package P86;

import java.util.ArrayList;
import java.util.List;

class Task {
    private String name;
    private String description;
    private boolean completed;

    public Task(String name, String description) {
        this.name = name;
        this.description = description;
        this.completed = false;
    }

    public String getName() {
        return name;
    }

    public String getDescription() {
        return description;
    }

    public boolean isCompleted() {
        return completed;
    }

    public void markAsCompleted() {
        completed = true;
    }
}

class Project {
    private String name;
    private List<Task> tasks;

    public Project(String name) {
        this.name = name;
        this.tasks = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void addTask(Task task) {
        tasks.add(task);
    }

    public List<Task> getTasks() {
        return tasks;
    }

    public double getProjectProgress() {
        if (tasks.isEmpty()) {
            return 0.0;
        }

        long completedTasks = tasks.stream().filter(Task::isCompleted).count();
        return (double) completedTasks / tasks.size() * 100;
    }
}

class TeamMember {
    private String name;
    private List<Task> assignedTasks;

    public TeamMember(String name) {
        this.name = name;
        this.assignedTasks = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void assignTask(Task task) {
        assignedTasks.add(task);
    }

    public void completeTask(Task task) {
        task.markAsCompleted();
        assignedTasks.remove(task);
    }

    public List<Task> getAssignedTasks() {
        return assignedTasks;
    }
}

public class TestTaskManagement {
    public static void main(String[] args) {
        Project softwareProject = new Project("Software Development");
        Task task1 = new Task("Implement Feature A", "Develop and test Feature A");
        Task task2 = new Task("Bug Fixing", "Address reported bugs in the system");

        softwareProject.addTask(task1);
        softwareProject.addTask(task2);

        TeamMember developer1 = new TeamMember("John");
        TeamMember developer2 = new TeamMember("Jane");

        developer1.assignTask(task1);
        developer2.assignTask(task2);

        System.out.println("Assigned tasks to " + developer1.getName() + ": " + developer1.getAssignedTasks().size());
        System.out.println("Assigned tasks to " + developer2.getName() + ": " + developer2.getAssignedTasks().size());

        developer1.completeTask(task1);
        developer2.completeTask(task2);

        System.out.println("Completed tasks by " + developer1.getName() + ": " + developer1.getAssignedTasks().size());
        System.out.println("Completed tasks by " + developer2.getName() + ": " + developer2.getAssignedTasks().size());

        System.out.println("Project progress for " + softwareProject.getName() + ": " + softwareProject.getProjectProgress() + "%");
    }

}
