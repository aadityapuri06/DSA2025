#include <iostream>
#include <numeric>

using namespace std;

int findMissingNumber(int arr[], int n) {
    int total_sum = (n + 1) * (n + 2) / 2;
    int arr_sum = 0;
    for (int i = 0; i < n; i++) {
        arr_sum += arr[i];
    }
    return total_sum - arr_sum;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int missing = findMissingNumber(arr, n);
    
    cout << "The missing number is: " << missing << endl;

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();
    
    return 0;
}
