package P99;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Course {
    private String courseId;
    private String courseName;
    private Instructor instructor;
    private List<Student> enrolledStudents;
    public Map<Student, Double> studentProgress;

    public Course(String courseId, String courseName, Instructor instructor) {
        this.courseId = courseId;
        this.courseName = courseName;
        this.instructor = instructor;
        this.enrolledStudents = new ArrayList<>();
        this.studentProgress = new HashMap<>();
    }

    public String getCourseId() {
        return courseId;
    }

    public String getCourseName() {
        return courseName;
    }

    public Instructor getInstructor() {
        return instructor;
    }

    public List<Student> getEnrolledStudents() {
        return enrolledStudents;
    }

    public void enrollStudent(Student student) {
        enrolledStudents.add(student);
        studentProgress.put(student, 0.0); // Initial progress is set to 0%
    }

    public void assignGrade(Student student, double progress) {
        if (enrolledStudents.contains(student)) {
            studentProgress.put(student, progress);
        }
    }
}

class Student {
    private int studentId;
    private String studentName;

    public Student(int studentId, String studentName) {
        this.studentId = studentId;
        this.studentName = studentName;
    }

    public int getStudentId() {
        return studentId;
    }

    public String getStudentName() {
        return studentName;
    }
}

class Instructor {
    private int instructorId;
    private String instructorName;

    public Instructor(int instructorId, String instructorName) {
        this.instructorId = instructorId;
        this.instructorName = instructorName;
    }

    public int getInstructorId() {
        return instructorId;
    }

    public String getInstructorName() {
        return instructorName;
    }
}




public class TestOnlineLearning {
    public static void main(String[] args) {
        // Create an Instructor
        Instructor instructor = new Instructor(1, "Dr. Smith");

        // Create a Course
        Course javaCourse = new Course("CS101", "Java Programming", instructor);

        // Create Students
        Student student1 = new Student(101, "John Doe");
        Student student2 = new Student(102, "Jane Smith");

        // Enroll Students in the Course
        javaCourse.enrollStudent(student1);
        javaCourse.enrollStudent(student2);

        // Assign Grades/Progress
        javaCourse.assignGrade(student1, 75.0);
        javaCourse.assignGrade(student2, 90.0);

        // Display Course Information
        System.out.println("Course: " + javaCourse.getCourseName());
        System.out.println("Instructor: " + javaCourse.getInstructor().getInstructorName());
        System.out.println("Enrolled Students: " + javaCourse.getEnrolledStudents().size());

        // Display Student Progress
        for (Student student : javaCourse.getEnrolledStudents()) {
            System.out.println("Student: " + student.getStudentName() + ", Progress: " + javaCourse.studentProgress.get(student) + "%");
        }
    }
}
