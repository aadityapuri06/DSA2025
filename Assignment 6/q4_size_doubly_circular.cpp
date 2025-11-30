#include <iostream>
using namespace std;

// Doubly linked list size and circular linked list size (simple)
struct DNode{int data; DNode* prev; DNode* next; DNode(int v):data(v),prev(NULL),next(NULL){}};

int sizeDoubly(DNode* head){ int c=0; DNode* t=head; while(t){ c++; t=t->next; } return c; }

struct CNode{int data; CNode* next; CNode(int v):data(v),next(NULL){} };
int sizeCircular(CNode* head){ if(!head) return 0; int c=1; CNode* t=head->next; while(t!=head){ c++; t=t->next; } return c; }

int main(){
    // doubly list: 1 <-> 2 <-> 3
    DNode* d1=new DNode(1); DNode* d2=new DNode(2); DNode* d3=new DNode(3);
    d1->next=d2; d2->prev=d1; d2->next=d3; d3->prev=d2;

    cout<<"Size of doubly linked list: "<<sizeDoubly(d1)<<"\n";

    // circular list: 10->20->30->10
    CNode* c1=new CNode(10); CNode* c2=new CNode(20); CNode* c3=new CNode(30);
    c1->next=c2; c2->next=c3; c3->next=c1;
    cout<<"Size of circular linked list: "<<sizeCircular(c1)<<"\n";

    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
