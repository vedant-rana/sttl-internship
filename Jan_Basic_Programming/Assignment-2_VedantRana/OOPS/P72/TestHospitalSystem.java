package P72;

import java.util.ArrayList;
import java.util.List;

class Hospital {
    private List<Doctor> doctors;
    private List<Patient> patients;
    private List<Appointment> appointments;

    public Hospital() {
        this.doctors = new ArrayList<>();
        this.patients = new ArrayList<>();
        this.appointments = new ArrayList<>();
    }

    public void addDoctor(Doctor doctor) {
        doctors.add(doctor);
    }

    public void addPatient(Patient patient) {
        patients.add(patient);
    }

    public void scheduleAppointment(Doctor doctor, Patient patient, String dateTime) {
        Appointment appointment = new Appointment(doctor, patient, dateTime);
        appointments.add(appointment);
    }

    public void printAppointments() {
        System.out.println("Scheduled Appointments:");
        for (Appointment appointment : appointments) {
            System.out.println("Doctor: " + appointment.getDoctor().getName());
            System.out.println("Patient: " + appointment.getPatient().getName());
            System.out.println("Date and Time: " + appointment.getDateTime());
            System.out.println("---------------------------");
        }
    }
}

class Doctor {
    private String name;
    private String specialization;

    public Doctor(String name, String specialization) {
        this.name = name;
        this.specialization = specialization;
    }

    public String getName() {
        return name;
    }
}

class Patient {
    private String name;
    private int age;

    public Patient(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }
}

class Appointment {
    private Doctor doctor;
    private Patient patient;
    private String dateTime;

    public Appointment(Doctor doctor, Patient patient, String dateTime) {
        this.doctor = doctor;
        this.patient = patient;
        this.dateTime = dateTime;
    }

    public Doctor getDoctor() {
        return doctor;
    }

    public Patient getPatient() {
        return patient;
    }

    public String getDateTime() {
        return dateTime;
    }
}

public class TestHospitalSystem {
    public static void main(String[] args) {
        Hospital hospital = new Hospital();

        Doctor doctor1 = new Doctor("Dr. Smith", "Cardiologist");
        Doctor doctor2 = new Doctor("Dr. Johnson", "Orthopedic");

        Patient patient1 = new Patient("John Doe", 35);
        Patient patient2 = new Patient("Jane Smith", 45);

        hospital.addDoctor(doctor1);
        hospital.addDoctor(doctor2);

        hospital.addPatient(patient1);
        hospital.addPatient(patient2);

        hospital.scheduleAppointment(doctor1, patient1, "2024-01-20 10:00 AM");
        hospital.scheduleAppointment(doctor2, patient2, "2024-01-21 02:30 PM");

        // Print scheduled appointments
        hospital.printAppointments();
    }
}
