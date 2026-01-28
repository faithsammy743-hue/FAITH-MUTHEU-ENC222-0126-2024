#include <iostream>
#include <string>
using namespace std;

/* =========================
   Abstract Base Class
   ========================= */
class Employee {
protected:
    string firstName;
    char initial;
    string lastName;

public:
    Employee(string f, char i, string l)
        : firstName(f), initial(i), lastName(l) {}

    virtual ~Employee() {}   // virtual destructor

    string getFullName() const {
        return firstName + " " + initial + ". " + lastName;
    }

    // Pure virtual function
    virtual double getMonthlyPay() const = 0;
};

/* =========================
   Salaried Employee
   ========================= */
class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(string f, char i, string l, double salary)
        : Employee(f, i, l), monthlySalary(salary) {}

    double getMonthlyPay() const override {
        return monthlySalary;
    }
};

/* =========================
   Hourly Employee
   ========================= */
class HourlyEmployee : public Employee {
private:
    double hoursWorked;
    double ratePerHour;

public:
    HourlyEmployee(string f, char i, string l,
                   double hours, double rate)
        : Employee(f, i, l),
          hoursWorked(hours),
          ratePerHour(rate) {}

    double getMonthlyPay() const override {
        return hoursWorked * ratePerHour;
    }
};

/* =========================
   Application / Test
   ========================= */
int main() {
    // Polymorphism using base class pointers
    Employee* emp1 = new SalariedEmployee("John", 'A', "Doe", 50000);
    Employee* emp2 = new HourlyEmployee("Mary", 'B', "Smith", 160, 300);

    cout << emp1->getFullName()
         << " Monthly Pay: " << emp1->getMonthlyPay() << endl;

    cout << emp2->getFullName()
         << " Monthly Pay: " << emp2->getMonthlyPay() << endl;

    delete emp1;
    delete emp2;

    return 0;
}




