#include <iostream>
using namespace std;

class Complex{
private:
    int x, y;
public:
    Complex() {}
    Complex(int x, int y) {
        this->x = x;
        this->y = y;
    }

    friend ostream& operator<<(ostream& out, const Complex& c);
};
ostream &operator<<(ostream &out, const Complex &c) {
    out << c.x << " " << "+ " << c.y << "i";
    return out;
}

int main() {
    Complex c1(1, 2), c2(2, 3);
    cout << c1 << endl;
    cout << c2 << endl;

    return 0;
}