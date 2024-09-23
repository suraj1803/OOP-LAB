#include <iostream>
using namespace std;

class Complex {
    int x, y;
    public:
        void getData() {
            int a, b;
            cout << "Enter real part: ";
            cin >> a;
            cout << "Enter imaginary part: ";
            cin >> b;

            x = a;
            y = b;
        }

        void Display() {
            cout << "Complex number : " << x << " + "<< y << "i" << endl;
        }

        friend Complex sum(Complex a, Complex b);
};

Complex sum(Complex a, Complex b) {
    Complex c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;

    return c;
}

int main() {

    Complex a, b, c;
    a.getData();
    b.getData();
    c = sum(a, b);
    c.Display();

    return 0;
}