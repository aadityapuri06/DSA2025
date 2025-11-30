#include <iostream>
using namespace std;

// Simple circular linked list and doubly linked list menu programs

// Circular single linked list (simple, beginner style)
struct CNode{int data; CNode* next; CNode(int v):data(v),next(NULL){}};
CNode* cHead = NULL;

void cInsertEnd(int v){ CNode* n=new CNode(v); if(!cHead){ cHead=n; n->next=n; return;} CNode* t=cHead; while(t->next!=cHead) t=t->next; t->next=n; n->next=cHead; }
void cInsertBegin(int v){ CNode* n=new CNode(v); if(!cHead){ cHead=n; n->next=n; return;} CNode* t=cHead; while(t->next!=cHead) t=t->next; n->next=cHead; t->next=n; cHead=n; }
void cInsertAfter(int after,int v){ if(!cHead) return; CNode* t=cHead; do{ if(t->data==after){ CNode* n=new CNode(v); n->next=t->next; t->next=n; return;} t=t->next;} while(t!=cHead); }
void cDeleteValue(int v){ if(!cHead) return; CNode* cur=cHead; CNode* prev=NULL; do{ if(cur->data==v){ if(cur==cHead && cur->next==cHead){ delete cur; cHead=NULL; return;} if(cur==cHead){ // find last
 prev=cHead; while(prev->next!=cHead) prev=prev->next; prev->next = cHead->next; cHead = cHead->next; delete cur; return;} prev->next = cur->next; delete cur; return; } prev=cur; cur=cur->next; } while(cur!=cHead);
}
void cDisplay(){ if(!cHead){ cout<<"Empty\n"; return;} CNode* t=cHead; do{ cout<<t->data<<" "; t=t->next;} while(t!=cHead); cout<<"\n"; }

// Doubly linked list (simple)
struct DNode{int data; DNode* prev; DNode* next; DNode(int v):data(v),prev(NULL),next(NULL){} };
DNode* dHead = NULL;

void dInsertFront(int v){ DNode* n = new DNode(v); n->next = dHead; if(dHead) dHead->prev = n; dHead = n; }
void dInsertEnd(int v){ DNode* n = new DNode(v); if(!dHead){ dHead=n; return;} DNode* t=dHead; while(t->next) t=t->next; t->next=n; n->prev=t; }
void dInsertAfter(int after,int v){ DNode* t=dHead; while(t){ if(t->data==after){ DNode* n=new DNode(v); n->next = t->next; n->prev = t; if(t->next) t->next->prev = n; t->next = n; return;} t=t->next; } }
void dDeleteValue(int v){ DNode* t=dHead; while(t){ if(t->data==v){ if(t->prev) t->prev->next = t->next; else dHead = t->next; if(t->next) t->next->prev = t->prev; delete t; return;} t=t->next; } }
void dDisplay(){ DNode* t=dHead; while(t){ cout<<t->data<<" "; t=t->next; } cout<<"\n"; }

int main(){
    int choice= -1;
    do{
        cout<<"\nMenu: 1-Circular insertEnd 2-Circular insertBegin 3-Circular insertAfter 4-Circular delete 5-cDisplay\n";
        cout<<"6-DLL insertFront 7-DLL insertEnd 8-DLL insertAfter 9-DLL delete 10-dDisplay 0-exit\n";
        cout<<"choice: "; cin>>choice;
        int v,after;
        switch(choice){
            case 1: cout<<"val: "; cin>>v; cInsertEnd(v); break;
            case 2: cout<<"val: "; cin>>v; cInsertBegin(v); break;
            case 3: cout<<"after val and new val: "; cin>>after>>v; cInsertAfter(after,v); break;
            case 4: cout<<"val to delete: "; cin>>v; cDeleteValue(v); break;
            case 5: cDisplay(); break;
            case 6: cout<<"val: "; cin>>v; dInsertFront(v); break;
            case 7: cout<<"val: "; cin>>v; dInsertEnd(v); break;
            case 8: cout<<"after val and new val: "; cin>>after>>v; dInsertAfter(after,v); break;
            case 9: cout<<"val to delete: "; cin>>v; dDeleteValue(v); break;
            case 10: dDisplay(); break;
            case 0: break;
            default: cout<<"Invalid\n";
        }
    } while(choice!=0);

    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
