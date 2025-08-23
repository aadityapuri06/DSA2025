// Q4a: Reverse array
#include <iostream>
using namespace std;

int main() {
    int n, arr[100];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Reversed array: ";
    for (int i = n-1; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
