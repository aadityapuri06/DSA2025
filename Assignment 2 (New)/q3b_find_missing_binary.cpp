#include <iostream>

using namespace std;

int findMissing(int arr[], int size) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] != mid + 1 && (mid == 0 || arr[mid - 1] == mid)) {
            return mid + 1;
        }
        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int missing = findMissing(arr, n);
    
    if (missing != -1) {
        cout << "The missing number is: " << missing << endl;
    } else {
        cout << "No number is missing, or the array is not sorted correctly." << endl;
    }

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
