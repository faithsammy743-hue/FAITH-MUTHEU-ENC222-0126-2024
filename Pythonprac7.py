# Employee class definition
class Employee:
    def __init__(self, name, age, service_year, salary):
        self._name = name
        self._age = age
        self._service_year = service_year
        self._salary = salary

    # Accessors (getters)
    def getName(self):
        return self._name

    def getAge(self):
        return self._age

    def getServiceYear(self):
        return self._service_year

    def getSalary(self):
        return self._salary


# Main program to test Employee class
if __name__ == "__main__":
    emp = Employee("Brown Otieno", 27, 1, 360000)

    print("Details:")
    print("Name:", emp.getName())
    print("Age:", emp.getAge())
    print("Service Years:", emp.getServiceYear())
    print("Salary: KSH.", emp.getSalary())
