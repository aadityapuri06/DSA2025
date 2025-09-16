#include <iostream>
#include <queue>
using namespace std;


class StackWithTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.push(x);
        
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        cout << x << " pushed to stack (2 queues)." << endl;
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << q1.front() << " popped from stack (2 queues)." << endl;
        q1.pop();
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }
};


class StackWithOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int s = q.size();
        q.push(x);
        
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed to stack (1 queue)." << endl;
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << q.front() << " popped from stack (1 queue)." << endl;
        q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
};

int main() {
    cout << "--- Stack using two queues ---" << endl;
    StackWithTwoQueues s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.pop();
    cout << "Top element is: " << s1.top() << endl;
    s1.pop();

    cout << "\n--- Stack using one queue ---" << endl;
    StackWithOneQueue s2;
    s2.push(10);
    s2.push(20);
s2.push(30);
    s2.pop();
    cout << "Top element is: " << s2.top() << endl;
    s2.pop();

    return 0;
}
