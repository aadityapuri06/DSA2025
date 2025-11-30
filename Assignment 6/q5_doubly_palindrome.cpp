#include <iostream>
using namespace std;

struct Node{ char data; Node* prev; Node* next; Node(char c):data(c),prev(NULL),next(NULL){} };

bool isPalindrome(Node* head){
    if(!head) return true;
    Node* tail = head;
    while(tail->next) tail = tail->next;
    while(head!=tail && head->prev!=tail){
        if(head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main(){
    // build L E V E L
    Node* a=new Node('L'); Node* b=new Node('E'); Node* c=new Node('V'); Node* d=new Node('E'); Node* e=new Node('L');
    a->next=b; b->prev=a; b->next=c; c->prev=b; c->next=d; d->prev=c; d->next=e; e->prev=d;

    cout << (isPalindrome(a) ? "True" : "False") << endl;

    // not palindrome: A B C
    Node* x=new Node('A'); Node* y=new Node('B'); Node* z=new Node('C');
    x->next=y; y->prev=x; y->next=z; z->prev=y;
    cout << (isPalindrome(x) ? "True" : "False") << endl;

    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
