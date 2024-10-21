#include <iostream>
using namespace std;

class Student
{
protected:
    int id;

public:
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
    void show()
    {
        total_marks = marks1 + marks2 + sports_marks;
        get_marks1();
        get_marks2();
        get_sports_marks();

        cout << "Total Marks: " << total_marks << endl;
    }
};

int main()
{
    result r;
    r.set_id(2036168);
    r.set_marks1(90);
    r.set_marks2(90);
    r.set_sports_marks(80);
    r.show();

    return 0;
}