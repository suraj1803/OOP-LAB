#include <iostream>
using namespace std;

class Array{
private:
    int *arr;
    int size;
    int capacity;
public:
    Array() {
        arr = NULL;
        size = 0;
    }

    Array(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }

    Array(const Array& a) {
        this->capacity = a.capacity;
        arr = new int[this->capacity];
        this-> size = a.size;
        for (int i = 0; i < size; i++) {
            arr[i] = a.arr[i];
        }
    }

    void push_back(int n) {
        if (size == capacity) {
            return;
        }
        arr[size++] = n;
    }

    int operator[](int idx) {
        if (idx < 0 || idx >= size) {
            return -1;
        }

        return arr[idx];
    }

    friend ostream& operator<<(ostream& out, const Array& a);
    friend istream& operator>>(istream& in, Array& a);

    ~Array() {
        delete[] arr;
    }
};

ostream& operator<<(ostream& out, const Array& a) {
    for (int i = 0; i < a.size; i++) {
        out << a.arr[i] << " ";
    }
    return out;
}

istream& operator>>(istream& in, Array& a) {
    for (int i = 0; i < a.capacity; i++) {
        in >> a.arr[i];
        a.size++;
    }
    return in;
}

int main() {
    Array arr(3);
    cin >> arr;
    cout << arr << endl;
    cout << arr[2] << endl;
    return 0;
}
