#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int countDistinct(const vector<int>& arr) {
    set<int> distinctElements;
    for (int x : arr) {
        distinctElements.insert(x);
    }
    return distinctElements.size();
}

int main() {
    vector<int> arr = {10, 20, 20, 10, 30, 10};
    
    cout << "Array: ";
    for(int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Number of distinct elements are " << countDistinct(arr) << endl;

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
