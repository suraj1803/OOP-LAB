#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
    string name;
    int rollNo;

public:
    Student(string n, int r)
    {
        name = n;
        rollNo = r;
    }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

class BscStudent : public Student
{
public:
    BscStudent(string n, int r) : Student(n, r) {}

    void display()
    {
        cout << "BSc Student" << endl;
        displayInfo();
    }
};

class CommerceStudent : public Student
{
public:
    CommerceStudent(string n, int r) : Student(n, r) {}

    void display()
    {
        cout << "Commerce Student" << endl;
        displayInfo();
    }
};

class EngineeringStudent : public Student
{
public:
    EngineeringStudent(string n, int r) : Student(n, r) {}
};

class MechanicalStudent : public EngineeringStudent
{
public:
    MechanicalStudent(string n, int r) : EngineeringStudent(n, r) {}

    void display()
    {
        cout << "Mechanical Engineering Student" << endl;
        displayInfo();
    }
};

class ComputerScienceStudent : public EngineeringStudent
{
public:
    ComputerScienceStudent(string n, int r) : EngineeringStudent(n, r) {}

    void display()
    {
        cout << "Computer Science Engineering Student" << endl;
        displayInfo();
    }
};

class ITStudent : public EngineeringStudent
{
public:
    ITStudent(string n, int r) : EngineeringStudent(n, r) {}

    void display()
    {
        cout << "Information Technology Engineering Student" << endl;
        displayInfo();
    }
};

int main()
{
    BscStudent bsc("Ram", 101);
    CommerceStudent commerce("Shyam", 102);
    MechanicalStudent mech("Dileep", 201);
    ComputerScienceStudent cs("Jaddu", 202);
    ITStudent it("Suraj", 203);

    bsc.display();

    commerce.display();

    mech.display();

    cs.display();

    it.display();

    return 0;
}
