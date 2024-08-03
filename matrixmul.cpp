#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> inputMatrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

vector<vector<int>> matrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();

    vector<vector<int>> C(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter the number of rows and columns of matrix A: ";
    cin >> rowsA >> colsA;
    vector<vector<int>> A = inputMatrix(rowsA, colsA);
    cout << "Matrix A" <<endl;
    printMatrix(A);

    cout << "Enter the number of rows and columns of matrix B: ";
    cin >> rowsB >> colsB;
    vector<vector<int>> B = inputMatrix(rowsB, colsB);
    cout << "Matrix B" <<endl;
    printMatrix(B);

    if (colsA != rowsB) {
        cout << "Number of columns in A must be equal to the number of rows in B" << endl;
        return 1;
    }

    vector<vector<int>> C = matrixMultiplication(A, B);

    cout << "Resultant matrix C after multiplication:" << endl;
    printMatrix(C);
    cout <<endl;

    return 0;
}
