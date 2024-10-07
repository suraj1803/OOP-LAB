#include <iostream>
using namespace std;

class Matrix{
private:
    int m, n;
    int **arr;
public:

    // Search about shallow and deep copy
    
    Matrix() {
    }

    Matrix(int m, int n){
        this->m = m;
        this->n = n;
        create_matrix(m, n);
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

    void create_matrix(int m, int n) {
        arr = new int*[m];
        for (int i = 0; i < m; i++) {
            arr[i] = new int[n];
        }
    }
    
    Matrix* operator+(const Matrix &mat) {
        int m = this->m;
        int n = this->n;

        Matrix *res = new Matrix(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res->arr[i][j] = this->arr[i][j] + mat.arr[i][j];
            }
        }
        return res;
    }

    Matrix* operator*(const Matrix &mat) {
        int m = this->m;
        int n = mat.n;

        Matrix *res = new Matrix(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
            }
        }

        return res;
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
    Matrix *m3 = m1 + m2;
    cout << *m3;

    delete m3;

    return 0;
}
