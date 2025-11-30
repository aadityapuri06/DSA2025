#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int v):data(v),next(NULL){} };

bool isCircular(Node* head){
    if(!head) return false;
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true; // loop detected
    }
    return false;
}

int main(){
    // build example: 2->4->6->7->5 -> back to head
    Node* a = new Node(2);
    Node* b = new Node(4);
    Node* c = new Node(6);
    Node* d = new Node(7);
    Node* e = new Node(5);
    a->next=b; b->next=c; c->next=d; d->next=e; e->next=a; // circular

    cout << (isCircular(a) ? "True" : "False") << endl;

    // non-circular example
    Node* x = new Node(1);
    Node* y = new Node(2);
    x->next = y; y->next = NULL;
    cout << (isCircular(x) ? "True" : "False") << endl;

    cout << "\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
