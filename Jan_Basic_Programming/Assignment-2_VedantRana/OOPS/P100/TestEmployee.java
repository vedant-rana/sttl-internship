package P100;

import java.util.HashMap;
import java.util.Map;

class Employee {
    private int employeeId;
    private String name;
    private String designation;

    public Employee(int employeeId, String name, String designation) {
        this.employeeId = employeeId;
        this.name = name;
        this.designation = designation;
    }

    public int getEmployeeId() {
        return employeeId;
    }

    public String getName() {
        return name;
    }

    public String getDesignation() {
        return designation;
    }
}

class Salary {
    private static final double BASE_SALARY = 50000.0;

    public static double calculateSalary(Employee employee) {
        return BASE_SALARY;
    }
}

class Payroll {
    private Map<Integer, Double> payrollMap;

    public Payroll() {
        this.payrollMap = new HashMap<>();
    }

    public void generatePayStub(Employee employee) {
        double salary = Salary.calculateSalary(employee);
        payrollMap.put(employee.getEmployeeId(), salary);

        System.out.println("Pay Stub for Employee " + employee.getName());
        System.out.println("Employee ID: " + employee.getEmployeeId());
        System.out.println("Designation: " + employee.getDesignation());
        System.out.println("Salary: $" + salary);
        System.out.println("---------------");
    }

    public double getSalary(int employeeId) {
        return payrollMap.getOrDefault(employeeId, 0.0);
    }
}


public class TestEmployee {
    public static void main(String[] args) {

        Employee employee1 = new Employee(1, "John Doe", "Software Engineer");


        Payroll payroll = new Payroll();


        payroll.generatePayStub(employee1);


        double salary = payroll.getSalary(employee1.getEmployeeId());
        System.out.println("Salary for Employee " + employee1.getName() + ": $" + salary);
    }
}
