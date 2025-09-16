
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // Remove duplicates
    int temp[100], k = 0;
    for (int i = 0; i < n; i++) {
        bool unique = true;
        for (int j = 0; j < k; j++) {
            if (arr[i] == temp[j]) {
                unique = false;
                break;
            }
        }
        if (unique) {
            temp[k++] = arr[i];
        }
    }
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++)
        cout << temp[i] << " ";
    cout << endl;
    return 0;
}
