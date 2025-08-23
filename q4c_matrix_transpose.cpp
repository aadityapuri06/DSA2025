// Q4c: Transpose of matrix
#include <iostream>
using namespace std;

int main() {
    int a[10][10], t[10][10];
    int n, m;
    cout << "Enter rows and cols of matrix: ";
    cin >> n >> m;
    cout << "Enter matrix: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    // Transpose
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            t[j][i] = a[i][j];
    cout << "Transpose: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << t[i][j] << " ";
        cout << endl;
    }
    return 0;
}
