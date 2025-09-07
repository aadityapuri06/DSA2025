// 5. Write a program for the evaluation of a Postfix expression.
#include <iostream>
#include <string>
#include <stack>
#include <cmath> // For pow
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // If the scanned character is an operand (number),
        // push it to the stack.
        if (isdigit(c)) {
            st.push(c - '0');
        }
        // If the scanned character is an operator,
        // pop two elements from stack and apply the operator.
        else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            switch (c) {
            case '+':
                st.push(val2 + val1);
                break;
            case '-':
                st.push(val2 - val1);
                break;
            case '*':
                st.push(val2 * val1);
                break;
            case '/':
                st.push(val2 / val1);
                break;
            case '^':
                st.push(pow(val2, val1));
                break;
            }
        }
    }
    return st.top();
}

int main() {
    string exp;
    cout << "Enter a postfix expression (single digit numbers only): ";
    cin >> exp;
    cout << "Result: " << evaluatePostfix(exp) << endl;
    return 0;
}
