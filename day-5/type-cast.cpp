#include <iostream>
using namespace std;

class Integer {
private:
    int val;
public:
    Integer() {
        val = 0;
    }

    // int to Integer
    Integer(int val) {
        this->val = val;
    }

    int get_val() {
        return val;
    }

    friend ostream& operator<<(ostream& out, const Integer& integer);
};

ostream& operator<<(ostream& out, const Integer& integer) {
    out << integer.val;
    return out;
}

class Time {
private:
    int hours, minutes;
public:
    Time() {}

    Time(int hours, int minutes) {
        this->hours = hours;
        hours += minutes / 60;
        this->minutes = minutes % 60;
    }

    // int to Time type
    Time(int time) {
        this->hours = time / 60;
        this->minutes = time % 60;
    }

    // Integer to Time type
    Time(Integer &a) {
        hours = (a.get_val()) / 60;
        minutes = (a.get_val()) % 60;
    }

    int get_hours() {
        return hours;
    }

    int get_minutes() {
        return minutes;
    }

    // Time to int type
    operator int() {
        return hours * 60 + minutes;
    }

    // Time to Integer type
    operator Integer() {
        Integer a(hours * 60 + minutes);
        return a;
    }

    friend ostream& operator<<(ostream& out, const Time& t);
};

ostream &operator<<(ostream &out, const Time &t)
{
    out << "Hours: " << t.hours << " , Minutes: " << t.minutes;
    return out;
}


int main() {
    // int to Time type
    Time t1 = 77;
    cout << t1 << endl;
    // time to int type
    int a = t1;
    cout << a << endl;

    // int to Integer type
    Integer b = 65;
    // Integer to Time type
    Time t2 = b;
    cout << t2 << endl;
    
    // Time to Integer type
    Integer c = t2;
    cout << c << endl;

    return 0;
}
