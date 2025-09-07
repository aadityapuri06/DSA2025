// 3. Write a program that checks if an expression has balanced parentheses.
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool areParenthesesBalanced(string expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false; // Closing bracket with no opening
            }
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }
    return s.empty(); // Stack should be empty if all brackets are matched
}

int main() {
    string expression;
    cout << "Enter an expression with parentheses: ";
    getline(cin, expression);

    if (areParenthesesBalanced(expression)) {
        cout << "The expression has balanced parentheses." << endl;
    } else {
        cout << "The expression does not have balanced parentheses." << endl;
    }

    return 0;
}
