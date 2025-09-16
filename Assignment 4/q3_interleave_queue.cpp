#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue must have an even number of elements." << endl;
        return;
    }

    stack<int> s;
    int halfSize = q.size() / 2;

    
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

   
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Original queue: 4 7 11 20 5 9" << endl;

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
