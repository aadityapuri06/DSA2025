#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2;

    cout << "Enter the first string: ";
    getline(cin, str1);

    cout << "Enter the second string: ";
    getline(cin, str2);

    string result = str1 + str2;

    cout << "Concatenated string: " << result << endl;

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
