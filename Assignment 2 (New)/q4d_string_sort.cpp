#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    sort(str.begin(), str.end());

    cout << "Sorted string: " << str << endl;

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
