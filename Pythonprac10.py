from abc import ABC, abstractmethod

# =========================
# Abstract Base Class
# =========================
class Employee(ABC):
    def __init__(self, first_name, initial, last_name):
        self.first_name = first_name
        self.initial = initial
        self.last_name = last_name

    def getFullName(self):
        return f"{self.first_name} {self.initial}. {self.last_name}"

    # Abstract method
    @abstractmethod
    def getMonthlyPay(self):
        pass


# =========================
# Salaried Employee
# =========================
class SalariedEmployee(Employee):
    def __init__(self, first_name, initial, last_name, monthly_salary):
        super().__init__(first_name, initial, last_name)
        self.monthly_salary = monthly_salary

    def getMonthlyPay(self):
        return self.monthly_salary


# =========================
# Hourly Employee
# =========================
class HourlyEmployee(Employee):
    def __init__(self, first_name, initial, last_name, hours_worked, rate_per_hour):
        super().__init__(first_name, initial, last_name)
        self.hours_worked = hours_worked
        self.rate_per_hour = rate_per_hour

    def getMonthlyPay(self):
        return self.hours_worked * self.rate_per_hour


# =========================
# Application / Test
# =========================
if __name__ == "__main__":
    # Polymorphism: base class references
    emp1: Employee = SalariedEmployee("John", "A", "Doe", 50000)
    emp2: Employee = HourlyEmployee("Mary", "B", "Smith", 160, 300)

    print(emp1.getFullName(), "Monthly Pay:", emp1.getMonthlyPay())
    print(emp2.getFullName(), "Monthly Pay:", emp2.getMonthlyPay())
