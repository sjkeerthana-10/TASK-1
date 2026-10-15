#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int id;
    string fullName;
    double percentage;
    static int totalStudents;

public:
    
    Student()
        : id(0), fullName("Not Assigned"), percentage(0.0) {
        ++totalStudents;
    }

    
    Student(int i, const string& n, double p)
        : id(i), fullName(n), percentage(p) {
        ++totalStudents;
    }

    
    ~Student() {
        --totalStudents;
    }

    
    void update(double p) {
        percentage = p;
    }

    void update(const string& n) {
        fullName = n;
    }

    void update(int i, const string& n, double p) {
        id = i;
        fullName = n;
        percentage = p;
    }

    
    void show() const {
        cout << "ID: " << id
             << " | Name: " << fullName
             << " | Percentage: " << percentage << "%"
             << endl;
    }

    
    const string& getName() const {
        return fullName;
    }

    
    static int getTotalStudents() {
        return totalStudents;
    }

    
    friend void printGrade(const Student& s);

    
    bool operator>(const Student& other) const {
        return percentage > other.percentage;
    }
};


int Student::totalStudents = 0;


void printGrade(const Student& s) {
    char grade;

    if (s.percentage >= 75)
        grade = 'A';
    else if (s.percentage >= 60)
        grade = 'B';
    else if (s.percentage >= 40)
        grade = 'C';
    else
        grade = 'F';

    cout << s.fullName << " -> Grade " << grade << endl;
}

int main() {
    Student a(201, "Meera", 91.5);
    Student b(202, "Kabir", 78.25);
    Student c;

    
    c.update(203, "Ishaan", 64.0);
    c.update(58.0);
    c.update("Ishaan Verma");

    cout << "=== Student Records ===" << endl;
    a.show();
    b.show();
    c.show();

    cout << "\n=== Grades (Friend Function) ===" << endl;
    printGrade(a);
    printGrade(b);
    printGrade(c);

    cout << "\n=== Comparison (Operator Overloading) ===" << endl;
    if (a > b)
        cout << a.getName() << " scores higher than "
             << b.getName() << endl;
    else
        cout << b.getName() << " scores higher than or equal to "
             << a.getName() << endl;

    cout << "\n=== Static Member ===" << endl;
    cout << "Students currently alive: "
         << Student::getTotalStudents() << endl;

    cout << "\n=== Dynamic Memory Management ===" << endl;

    Student* d = new Student(204, "Ananya", 88.5);

    cout << "Count after dynamic creation: "
         << Student::getTotalStudents() << endl;

    d->show();

    delete d;
    d = nullptr;

    cout << "Count after deletion: "
         << Student::getTotalStudents() << endl;

    cout << "\n=== Final Student Count ===" << endl;
    cout << "Students currently alive: "
         << Student::getTotalStudents() << endl;

    return 0;
}