#include <iostream>
using namespace std;
double calculateTrace(int size, double matrix[10][10]) {
    double trace = 0.0;
    for (int i = 0; i < size; ++i) {
        trace += matrix[i][i];
    }
    return trace;
}

double calculateDeterminant2x2(double a, double b, double c, double d) {
    return a * d - b * c;
}

double calculateDeterminant(int size, double matrix[10][10]) {
    if (size == 1) {
        return matrix[0][0];
    } else if (size == 2) {
        return calculateDeterminant2x2(matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);
    } else {
        double determinant = 0.0;
        for (int i = 0; i < size; ++i) {
            double submatrix[10][10];
            int subSize = size - 1;

            for (int j = 1; j < size; ++j) {
                int subIndex = 0;
                for (int k = 0; k < size; ++k) {
                    if (k != i) {
                        submatrix[j - 1][subIndex++] = matrix[j][k];
                    }
                }
            }

            determinant += matrix[0][i] * calculateDeterminant(subSize, submatrix) * ((i % 2 == 0) ? 1 : -1);
        }
        return determinant;
    }
}

int main() {
    const int matrixSize = 3;
    double matrix[10][10];

    cout << "Enter the elements of the square matrix (" << matrixSize << "x" << matrixSize << "):\n";
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            cout << "Enter element at position (" << i + 1 << "," << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }

    double trace = calculateTrace(matrixSize, matrix);
    cout << "Trace of the matrix is: " << trace << endl;

    double determinant = calculateDeterminant(matrixSize, matrix);
    cout << "Determinant of the matrix is: " << determinant << endl;

    return 0;
}
