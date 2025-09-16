#include <iostream>
#include <string>
#include <stack>
#include <cmath> 
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        
        if (isdigit(c)) {
            st.push(c - '0');
        }
        
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
