#include <iostream>
#include <string>
using namespace std;

// Employee class definition
class Employee {
private:
    string name;
    unsigned int age;
    unsigned int serviceYear;
    double salary;

public:
    // Parameterized constructor
    Employee(const string& name,
             unsigned int age,
             unsigned int serviceYear,
             double salary)
        : name(name), age(age), serviceYear(serviceYear), salary(salary) {}

    // Destructor
    Employee() {}

    // Accessors (getters)
    const string& getName() const { return name; }
    unsigned int getAge() const { return age; }
    unsigned int getServiceYear() const { return serviceYear; }
    double getSalary() const { return salary; }
};

// Main function to test Employee class
int main() {
    Employee emp("Brown Otieno", 27, 1, 360000);

    cout << "Details:\n";
    cout << "Name: " << emp.getName() << "\n";
    cout << "Age: " << emp.getAge() << "\n";
    cout << "Service Years: " << emp.getServiceYear() << "\n";
    cout << "Salary: KSH." << emp.getSalary() << "\n";

    return 0;
}