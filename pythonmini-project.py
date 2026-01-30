# ---------------- Department ----------------
class Department:
    def __init__(self, name, code):
        self.dept_name = name
        self.dept_code = code
        self.courses = []  # Association: Department has many courses

    def add_course(self, course):
        self.courses.append(course)

    def display_courses(self):
        print(f"Courses offered by {self.dept_name} Department:")
        for course in self.courses:
            course.display_course()


# ---------------- Course ----------------
class Course:
    def __init__(self, code, title, credits, department: Department):
        self.course_code = code
        self.course_title = title
        self.credits = credits
        self.department = department
        department.add_course(self)  # Dependency: Course depends on Department

    def get_code(self):
        return self.course_code

    def get_title(self):
        return self.course_title

    def display_course(self):
        print(f"{self.course_code} - {self.course_title} ({self.credits} credits)")


# ---------------- Student ----------------
class Student:
    def __init__(self, student_id, name, year):
        self.student_id = student_id
        self.name = name
        self.year = year
        self.registrations = []  # Association: Student has many registrations

    def add_registration(self, reg):
        self.registrations.append(reg)

    def display_registrations(self):
        print(f"Registrations for {self.name}:")
        for reg in self.registrations:
            reg.display_registration()

    def get_name(self):
        return self.name


# ---------------- Registration ----------------
class Registration:
    def __init__(self, reg_id, semester, student: Student, course: Course):
        self.registration_id = reg_id
        self.semester = semester
        self.student = student
        self.course = course
        student.add_registration(self)  # Link back to student

    def display_registration(self):
        print(f"Registration ID: {self.registration_id} | Semester: {self.semester} | "
              f"Student: {self.student.get_name()} | Course: {self.course.get_title()}")


# ---------------- Main ----------------
if __name__ == "__main__":
    # Create Department
    cs = Department("Computer Science", "CS")

    # Create Courses
    c1 = Course("CS101", "Introduction to Programming", 3, cs)
    c2 = Course("CS102", "Data Structures", 4, cs)

    # Display Department Courses
    cs.display_courses()

    # Create Student
    s1 = Student("S001", "Alice", 2)

    # Register Student for Courses
    r1 = Registration("R001", "Fall 2025", s1, c1)
    r2 = Registration("R002", "Fall 2025", s1, c2)

    # Display Student Registrations
    s1.display_registrations()
