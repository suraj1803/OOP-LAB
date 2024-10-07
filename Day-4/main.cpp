#include <iostream>
using namespace std;

class Complex{
    public:
        int x, y;
        Complex(){}
        Complex(int x, int y) {
            this->x = x;
            this->y = y;
        }

        void set_data(int x, int y) {
            this->x = x;
            this->y = y;
        }

        void display() {
            cout << x << " + " << y << "i" << endl;
        }
};

int main() {
    Complex c1;
    int Complex:: *p1 = &Complex::x;
    int Complex:: *p2 = &Complex::y;

    void (Complex:: *pf)(int, int) = &Complex::set_data;
    c1.*p1 = 1;
    c1.*p2 = 2;
    c1.display();
    (c1.*pf)(4, 5);
    c1.display();


    return 0;
}
