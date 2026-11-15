/*
 * Lab Experiment: Week 4 - DIY 1
 * Problem: Dynamic Matrix with Deep Copy & Destructor
 * Description: Allocates an m x n grid with new, provides a deep copy constructor,
 *              and frees dynamically allocated memory in destructor.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int **data;

    void allocate() {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]();
        }
    }

    void deallocate() {
        if (data) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }

public:
    Matrix(int r, int c) : rows(r), cols(c), data(nullptr) {
        allocate();
    }

    // Deep Copy Constructor
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), data(nullptr) {
        allocate();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
        cout << "[Copy Constructor] Deep copy performed (" << rows << "x" << cols << ")\n";
    }

    // Destructor
    ~Matrix() {
        deallocate();
        cout << "[Destructor] Matrix memory freed (" << rows << "x" << cols << ")\n";
    }

    void set(int r, int c, int val) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = val;
        }
    }

    int get(int r, int c) const {
        return (r >= 0 && r < rows && c >= 0 && c < cols) ? data[r][c] : 0;
    }

    void display(const string &title) const {
        cout << title << " (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << "\t";
            }
            cout << "\n";
        }
    }
};

int main() {
    cout << "===== Week 4 DIY 1: Dynamic Matrix =====\n";
    {
        Matrix m1(2, 3);
        m1.set(0, 0, 10); m1.set(0, 1, 20); m1.set(0, 2, 30);
        m1.set(1, 0, 40); m1.set(1, 1, 50); m1.set(1, 2, 60);
        m1.display("Matrix M1");

        // Copy constructor deep copy test
        Matrix m2 = m1;
        m2.display("Matrix M2 (Copy of M1)");

        // Modify M2 to verify M1 is unaffected (deep copy verification)
        m2.set(0, 0, 999);
        cout << "After modifying M2[0][0] to 999:\n";
        cout << "M1[0][0]: " << m1.get(0, 0) << " (should still be 10)\n";
        cout << "M2[0][0]: " << m2.get(0, 0) << " (modified)\n";
    } // M1 and M2 destroyed here

    return 0;
}
