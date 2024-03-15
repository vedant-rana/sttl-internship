#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    double grade;

public:
    Student(const string& name, int rollNumber, double grade)
        : name(name), rollNumber(rollNumber), grade(grade) {}

    void display() const {
        cout << "Name: " << name << "\n";
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Grade: " << fixed << setprecision(2) << grade << "\n\n";
    }

    int getRollNumber() const {
        return rollNumber;
    }

    double getGrade() const {
        return grade;
    }
};

class StudentInformationSystem {
private:
    vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void displayAllStudents() const {
        cout << "Student Information:\n";
        for (const auto& student : students) {
            student.display();
        }
    }

    void displayStudentDetails(int rollNumber) const {
        for (const auto& student : students) {
            if (student.getRollNumber() == rollNumber) {
                student.display();
                return;
            }
        }
        cout << "Student with Roll Number " << rollNumber << " not found.\n";
    }

    double averageGrade() const {
        if (students.empty()) {
            return 0.0;
        }

        double totalGrade = 0.0;
        for (const auto& student : students) {
            totalGrade += student.getGrade();
        }

        return totalGrade / students.size();
    }
};

int main() {
    StudentInformationSystem sis;

    sis.addStudent(Student("Alice", 101, 85.5));
    sis.addStudent(Student("Bob", 102, 78.0));
    sis.addStudent(Student("Charlie", 103, 92.3));

    sis.displayAllStudents();

    int searchRollNumber;
    cout << "Enter Roll Number to search: ";
    cin >> searchRollNumber;

    sis.displayStudentDetails(searchRollNumber);

    cout << "Average Grade: " << fixed << setprecision(2) << sis.averageGrade() << "\n";

    return 0;
}
