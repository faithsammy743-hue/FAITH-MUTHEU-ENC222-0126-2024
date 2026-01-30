#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------- Department ----------------
class Course; // Forward declaration

class Department {
private:
    string deptName;
    string deptCode;
    vector<Course*> courses; // Association: Department has many courses

public:
    Department(string name, string code) : deptName(name), deptCode(code) {}

    void addCourse(Course* course) {
        courses.push_back(course);
    }

    void displayCourses();
};

// ---------------- Course ----------------
class Course {
private:
    string courseCode;
    string courseTitle;
    int credits;
    Department* department; // Association: Course belongs to a Department

public:
    Course(string code, string title, int cr, Department* dept)
        : courseCode(code), courseTitle(title), credits(cr), department(dept) {
        dept->addCourse(this); // Link course to department
    }

    string getCode() { return courseCode; }
    string getTitle() { return courseTitle; }

    void displayCourse() {
        cout << courseCode << " - " << courseTitle << " (" << credits << " credits)" << endl;
    }
};

void Department::displayCourses() {
    cout << "Courses offered by " << deptName << " Department:" << endl;
    for (auto course : courses) {
        course->displayCourse();
    }
}

// ---------------- Student ----------------
class Registration; // Forward declaration

class Student {
private:
    string studentID;
    string name;
    int year;
    vector<Registration*> registrations; // Association: Student has many registrations

public:
    Student(string id, string n, int y) : studentID(id), name(n), year(y) {}

    void addRegistration(Registration* reg) {
        registrations.push_back(reg);
    }

    void displayRegistrations();

    string getName() { return name; }
};

// ---------------- Registration ----------------
class Registration {
private:
    string registrationID;
    string semester;
    Student* student; // Dependency: Registration depends on Student
    Course* course;   // Dependency: Registration depends on Course

public:
    Registration(string regID, string sem, Student* s, Course* c)
        : registrationID(regID), semester(sem), student(s), course(c) {
        s->addRegistration(this); // Link back to student
    }

    void displayRegistration() {
        cout << "Registration ID: " << registrationID
             << " | Semester: " << semester
             << " | Student: " << student->getName()
             << " | Course: " << course->getTitle() << endl;
    }
};

void Student::displayRegistrations() {
    cout << "Registrations for " << name << ":" << endl;
    for (auto reg : registrations) {
        reg->displayRegistration();
    }
}

// ---------------- Main ----------------
int main() {
    // Create Department
    Department cs("Computer Science", "CS");

    // Create Courses
    Course c1("CS101", "Introduction to Programming", 3, &cs);
    Course c2("CS102", "Data Structures", 4, &cs);

    // Display Department Courses
    cs.displayCourses();
    cout << endl;

    // Create Student
    Student s1("S001", "Alice", 2);

    // Register Student for Courses
    Registration r1("R001", "Fall 2025", &s1, &c1);
    Registration r2("R002", "Fall 2025", &s1, &c2);

    // Display Student Registrations
    s1.displayRegistrations();

    return 0;
}

