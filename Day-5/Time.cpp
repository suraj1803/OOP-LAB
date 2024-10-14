#include <iostream>
using namespace std;

class Time{
private:
    int hour, minutes, seconds;
public:
    Time() {}

    Time(int hour, int minutes, int seconds)
    {
        this->hour = hour;
        this->minutes = minutes;
        this->seconds = seconds;
    }


    void set_time() {
        int hour, minutes, seconds;
        cout << "Enter hour, minutes and seconds: ";
        cin >> hour >> minutes >> seconds;
        this->hour = hour;
        this->minutes = minutes;
        this->seconds = seconds;
        validate();
    }

    void validate() {
        minutes += seconds / 60;
        seconds = seconds % 60;
        hour += minutes / 60;
        minutes = minutes % 60;
    }

    void display() {
        cout << hour << " : " << minutes << " : " << seconds << endl;
    }

    Time operator+(const Time &t) {
        Time t3;
        int seconds = this->seconds+ t.seconds;
        int minutes = seconds / 60;
        seconds = seconds % 60;
        minutes += this->minutes + t.minutes;
        int hour = minutes / 60;
        minutes = minutes % 60;
        hour += this->hour + t.hour;

        t3.hour = hour;
        t3.minutes = minutes;
        t3.seconds = seconds;
        return t3;
    }

    friend Time operator +(const Time &t1, const Time &t2);
};

Time operator+(const Time &t1, const Time &t2) {
    Time t3;
    int seconds = t1.seconds+ t2.seconds;
    int minutes = seconds / 60;
    seconds = seconds % 60;
    minutes += t1.minutes + t2.minutes;
    int hour = minutes / 60;
    minutes = minutes % 60;
    hour += t1.hour + t2.hour;

    t3.hour = hour;
    t3.minutes = minutes;
    t3.seconds = seconds;
    return t3;
}

int main() {
    Time t1, t2, t3;
    t1.set_time();
    t2.set_time();
    
    t3 = t1 + t2;
    t3.display();

    return 0;
}
