#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    for (char &c : str) {
        if (islower(c)) {
            c = toupper(c);
        } else if (isupper(c)) {
            c = tolower(c);
        }
    }

    cout << "Converted case string: " << str << endl;

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
