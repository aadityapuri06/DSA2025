#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    reverse(str.begin(), str.end());

    cout << "Reversed string: " << str << endl;

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
