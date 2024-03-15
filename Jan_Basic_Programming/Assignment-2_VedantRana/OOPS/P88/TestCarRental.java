package P88;

import java.util.ArrayList;
import java.util.List;

class Car {
    private String make;
    private String model;
    private boolean available;

    public Car(String make, String model) {
        this.make = make;
        this.model = model;
        this.available = true;
    }

    public String getMake() {
        return make;
    }

    public String getModel() {
        return model;
    }

    public boolean isAvailable() {
        return available;
    }

    public void rent() {
        available = false;
    }

    public void returnCar() {
        available = true;
    }
}

class RentalAgency {
    private List<Car> cars;
    private List<Customer> customers;

    public RentalAgency() {
        this.cars = new ArrayList<>();
        this.customers = new ArrayList<>();
    }

    public void addCar(Car car) {
        cars.add(car);
    }

    public void addCustomer(Customer customer) {
        customers.add(customer);
    }

    public List<Car> getCars() {
        return cars;
    }

    public List<Customer> getCustomers() {
        return customers;
    }

    public void rentCar(Customer customer, Car car) {
        if (car.isAvailable()) {
            car.rent();
            customer.rentCar(car);
        } else {
            System.out.println("Car not available for rent.");
        }
    }

    public void returnCar(Customer customer, Car car) {
        if (customer.hasRentedCar(car)) {
            car.returnCar();
            customer.returnCar(car);
        } else {
            System.out.println("Customer didn't rent this car from us.");
        }
    }
}

class Customer {
    private String name;
    private List<Car> rentedCars;

    public Customer(String name) {
        this.name = name;
        this.rentedCars = new ArrayList<>();
    }

    public String getName() {
        return name;
    }

    public void rentCar(Car car) {
        rentedCars.add(car);
    }

    public void returnCar(Car car) {
        rentedCars.remove(car);
    }

    public boolean hasRentedCar(Car car) {
        return rentedCars.contains(car);
    }

    public List<Car> getRentedCars() {
        return rentedCars;
    }
}


public class TestCarRental {
    public static void main(String[] args) {
        RentalAgency rentalAgency = new RentalAgency();

        Car sedan = new Car("Toyota", "Camry");
        Car suv = new Car("Honda", "CR-V");

        rentalAgency.addCar(sedan);
        rentalAgency.addCar(suv);

        Customer customer1 = new Customer("John");
        Customer customer2 = new Customer("Jane");

        rentalAgency.addCustomer(customer1);
        rentalAgency.addCustomer(customer2);

        rentalAgency.rentCar(customer1, sedan);
        rentalAgency.rentCar(customer2, suv);

        System.out.println(customer1.getName() + "'s rented cars: " + customer1.getRentedCars().size());
        System.out.println(customer2.getName() + "'s rented cars: " + customer2.getRentedCars().size());

        rentalAgency.returnCar(customer1, sedan);

        System.out.println(customer1.getName() + "'s rented cars after return: " + customer1.getRentedCars().size());
    }
}
