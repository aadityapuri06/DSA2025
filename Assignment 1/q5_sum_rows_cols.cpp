// Q5: Sum of every row and column in 2D array
#include <iostream>
using namespace std;

int main() {
    int a[10][10], n, m;
    cout << "Enter rows and cols: ";
    cin >> n >> m;
    cout << "Enter matrix: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    // Row sums
    cout << "Row sums: ";
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++)
            sum += a[i][j];
        cout << sum << " ";
    }
    cout << endl;
    // Column sums
    cout << "Column sums: ";
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i][j];
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}
