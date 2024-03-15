package P63;

import java.util.ArrayList;
import java.util.List;

class Employee {
    private String name;
    private double salary;

    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public void promote(double salaryIncrease) {
        this.salary += salaryIncrease;
        System.out.println(name + " has been promoted. New salary: " + salary);
    }
}

class Manager extends Employee {
    private List<Employee> subordinates;

    public Manager(String name, double salary) {
        super(name, salary);
        this.subordinates = new ArrayList<>();
    }

    public List<Employee> getSubordinates() {
        return subordinates;
    }

    public void addSubordinate(Employee subordinate) {
        subordinates.add(subordinate);
    }

    public void removeSubordinate(Employee subordinate) {
        subordinates.remove(subordinate);
    }

    @Override
    public void promote(double salaryIncrease) {
        super.promote(salaryIncrease);
        for (Employee subordinate : subordinates) {
            subordinate.promote(salaryIncrease);
        }
    }
}

class Department {
    private String name;
    private List<Employee> employees;

    public Department(String name) {
        this.name = name;
        this.employees = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public List<Employee> getEmployees() {
        return employees;
    }

    public void addEmployee(Employee employee) {
        employees.add(employee);
    }

    public void removeEmployee(Employee employee) {
        employees.remove(employee);
    }
}

public class TestEmployee {
    public static void main(String[] args) {
        Employee employee1 = new Employee("John", 50000.0);
        Employee employee2 = new Employee("Jane", 45000.0);

        Manager manager = new Manager("Manager1", 80000.0);
        manager.addSubordinate(employee1);
        manager.addSubordinate(employee2);

        Department department = new Department("Engineering");
        department.addEmployee(manager);

        System.out.println("Employees in the " + department.getName() + " department:");
        for (Employee employee : department.getEmployees()) {
            System.out.println(employee.getName() + " - Salary: " + employee.getSalary());
        }

        double promotionAmount = 10000.0;
        manager.promote(promotionAmount);
    }
}
