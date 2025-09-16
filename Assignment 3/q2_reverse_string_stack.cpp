#include <iostream>
#include <string>
#include <stack> 
using namespace std;

int main() {
    string input_str;
    stack<char> char_stack;

    cout << "Enter a string: ";
    getline(cin, input_str);

    
    for (char c : input_str) {
        char_stack.push(c);
    }

    string reversed_str = "";
    
    while (!char_stack.empty()) {
        reversed_str += char_stack.top();
        char_stack.pop();
    }

    cout << "Original string: " << input_str << endl;
    cout << "Reversed string: " << reversed_str << endl;

    return 0;
}
