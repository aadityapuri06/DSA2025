#include <iostream>
using namespace std;

struct Node{int data; Node* next; Node(int v):data(v),next(NULL){}};

int main(){
    Node* a=new Node(20);
    Node* b=new Node(100);
    Node* c=new Node(40);
    Node* d=new Node(80);
    Node* e=new Node(60);
    a->next=b; b->next=c; c->next=d; d->next=e; e->next=a; // circular

    Node* t=a;
    if(t){
        cout<<t->data<<" ";
        t=t->next;
        while(t!=a){ cout<<t->data<<" "; t=t->next; }
        // repeat head at end
        cout<<a->data<<"\n";
    } else cout<<"Empty\n";

    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
