#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int r1 = A.size();
    int c1 = A[0].size();
    int c2 = B[0].size();
    vector<vector<int>> result(r1, vector<int>(c2, 0));
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

vector<vector<int>> transposeMatrix(const vector<vector<int>>& A) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int>> result(cols, vector<int>(rows));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = A[i][j];
        }
    }
    return result;
}

int main() {
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    cout << "Matrix A:" << endl;
    printMatrix(A);
    cout << "\nMatrix B:" << endl;
    printMatrix(B);

    cout << "\nAddition:" << endl;
    vector<vector<int>> C = addMatrices(A, B);
    printMatrix(C);

    cout << "\nMultiplication:" << endl;
    vector<vector<int>> D = multiplyMatrices(A, B);
    printMatrix(D);

    cout << "\nTranspose of A:" << endl;
    vector<vector<int>> T = transposeMatrix(A);
    printMatrix(T);

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
