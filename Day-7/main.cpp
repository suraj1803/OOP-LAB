#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    int id;
    string name;

public:
    Student(string name, int id) {
      this->name = name;
      this->id = id;
    }
    void get_name() {
        cout << "Name: " << name << endl;
    }
    int get_id()
    {
        return id;
    }

    void set_id(int id)
    {
        this->id = id;
    }
};

class marks : virtual public Student {
protected:
    int marks1, marks2;

public:
    marks(string name, int id, int marks1, int marks2) : Student(name, id) {
      this->marks1 = marks1;
      this->marks2 = marks2;
    }
    void get_marks1()
    {
        cout << "Sub1 marks: " << marks1 << endl;
    }
    void set_marks1(int marks)
    {
        marks1 = marks;
    }
    void get_marks2()
    {
        cout << "Sub2 marks: " << marks2 << endl;
    }
    void set_marks2(int marks)
    {
        marks2 = marks;
    }
};

class sports : public virtual Student
{
protected:
    int sports_marks;

public:
    sports(string name, int id, int sports_marks): Student(name, id){
      this->sports_marks = sports_marks;
    }
    void get_sports_marks()
    {
        cout << "Sports marks: " << sports_marks << endl;
    }
    void set_sports_marks(int marks)
    {
        sports_marks = marks;
    }
};

class result : public sports, public marks
{
private:
    int total_marks;
public:
    result(string name, int id, int marks1, int marks2, int sports_marks) : sports(name, id, sports_marks), marks(name, id, marks1, marks2) , Student(name, id){
    }
    void show()
    {
        total_marks = marks1 + marks2 + sports_marks;
        get_name();
        get_marks1();
        get_marks2();
        get_sports_marks();

        cout << "Total Marks: " << total_marks << endl;
    }
};

int main()
{
    result r("Suraj", 68, 70, 80, 90) ;
    r.show();
    r.get_id();
    return 0;
}
