#include <iostream>
#include <vector>

using namespace std;

int main() {
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int size = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                size++;
            }
        }
    }

    vector<vector<int>> compactMatrix(3, vector<int>(size));
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    cout << "Sparse Matrix Representation:" << endl;
    cout << "Row:    ";
    for (int i = 0; i < size; i++) cout << compactMatrix[0][i] << " ";
    cout << endl;
    cout << "Column: ";
    for (int i = 0; i < size; i++) cout << compactMatrix[1][i] << " ";
    cout << endl;
    cout << "Value:  ";
    for (int i = 0; i < size; i++) cout << compactMatrix[2][i] << " ";
    cout << endl;

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
