// 4. Write a program to convert an Infix expression into a Postfix expression.
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1; // for '('
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the scanned character is an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an '(', push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ')', pop and add to output from the stack
        // until an '(' is encountered.
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // Pop '('
        }

        // If an operator is scanned
        else {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string exp;
    cout << "Enter an infix expression: ";
    cin >> exp;
    cout << "Postfix expression: " << infixToPostfix(exp) << endl;
    return 0;
}
