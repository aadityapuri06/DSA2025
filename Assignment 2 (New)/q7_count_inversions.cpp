#include <iostream>
#include <vector>

using namespace std;

int countInversions(const vector<int>& arr) {
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<int> arr = {8, 4, 2, 1};
    
    cout << "Array: ";
    for(int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Number of inversions are " << countInversions(arr) << endl;

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
