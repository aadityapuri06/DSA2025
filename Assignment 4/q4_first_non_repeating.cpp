#include <iostream>
#include <string>
#include <queue>
using namespace std;

void findFirstNonRepeating() {
    const int MAX_CHAR = 26;
    int charCount[MAX_CHAR] = {0};
    queue<char> q;
    string stream = "aabc";

    cout << "Input Stream: " << stream << endl;
    cout << "Output: ";

    for (char c : stream) {
       
        q.push(c);
        charCount[c - 'a']++;

        
        while (!q.empty()) {
            if (charCount[q.front() - 'a'] > 1) {
                q.pop();
            } else {
                cout << q.front() << " ";
                break;
            }
        }

        if (q.empty()) {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main() {
    findFirstNonRepeating();
    return 0;
}
