#include <iostream>
using namespace std;

class Matrix{
private:
    int m, n;
    int **arr;
public:
    Matrix() {}

    Matrix(int m, int n){
        this->m = m;
        this->n = n;
        create_matrix(m, n);
    }

    /*

    ---- Important -- 
    copy constructor to perform deep copy not shallow copy
    otherwise it will copies only the pointer not the actuall 2d array that
    is in the heap memory

    */

    Matrix(const Matrix& arr) {
        this->m = arr.m;
        this->n = arr.n;
        create_matrix(m, n);
    }

    void create_matrix(int m, int n) {
        arr = new int*[m];
        for (int i = 0; i < m; i++) {
            arr[i] = new int[n];
        }
    }

    void set_elements() {
        int m, n;
        cout << "Enter size of Matrix: ";
        cin >> m >> n;
        this->m = m;
        this->n = n;
        cout << "Enter elements: " << endl;

        create_matrix(m, n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
    }

    
    Matrix operator+(const Matrix &mat) {
        int m = this->m;
        int n = this->n;

        Matrix res(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res.arr[i][j] = this->arr[i][j] + mat.arr[i][j];
            }
        }
        return res;
    }


    Matrix operator*(const Matrix &mat) {
        int m = this->m;
        int n = mat.n;

        Matrix res (m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res.arr[i][j] = 0;
                for (int k = 0; k < this->n; k++) {
                    res.arr[i][j] += this->arr[i][k] * mat.arr[k][j];
                }
            }
        }

        return res;
    }

    Matrix inverse() {

    }

    friend ostream& operator<<(ostream& output , Matrix &m);

    ~Matrix() {
        for (int i = 0; i < m; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};

ostream& operator<<(ostream& output , Matrix &matrix) {
    for (int i = 0; i < matrix.m; i++) {
        for (int j = 0; j < matrix.n; j++) {
            output << matrix.arr[i][j] << " ";
        }
        output << "\n";
    }
    return  output;
}

int main() {
    Matrix m1, m2;
    m1.set_elements();
    m2.set_elements();
    Matrix m3 = m1 * m2;
    cout << m3 << m1 << m2;


    return 0;
}
