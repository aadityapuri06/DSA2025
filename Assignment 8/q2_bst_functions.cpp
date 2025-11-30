#include <iostream>
using namespace std;

struct Node{int data; Node* left; Node* right; Node(int v):data(v),left(NULL),right(NULL){}
};

Node* insert(Node* r, int v){ if(!r) return new Node(v); if(v<r->data) r->left = insert(r->left,v); else if(v>r->data) r->right = insert(r->right,v); return r; }

Node* searchRec(Node* r, int key){ if(!r) return NULL; if(r->data==key) return r; if(key<r->data) return searchRec(r->left,key); return searchRec(r->right,key); }
Node* searchItr(Node* r, int key){ while(r){ if(r->data==key) return r; r = (key<r->data)? r->left: r->right; } return NULL; }

Node* findMin(Node* r){ if(!r) return NULL; while(r->left) r=r->left; return r; }
Node* findMax(Node* r){ if(!r) return NULL; while(r->right) r=r->right; return r; }

Node* inorderSuccessor(Node* root, int key){ Node* curr = root; Node* succ = NULL; while(curr){ if(key<curr->data){ succ = curr; curr = curr->left; } else if(key>curr->data) curr = curr->right; else { if(curr->right) succ = findMin(curr->right); break; } } return succ; }
Node* inorderPredecessor(Node* root, int key){ Node* curr = root; Node* pred = NULL; while(curr){ if(key>curr->data){ pred = curr; curr = curr->right; } else if(key<curr->data) curr = curr->left; else { if(curr->left) pred = findMax(curr->left); break; } } return pred; }

int main(){
    Node* root = NULL;
    int vals[] = {8,3,10,1,6,14,4,7,13};
    for(int v: vals) root = insert(root,v);

    cout<<"searchRec(6): "; cout<<(searchRec(root,6)?"found":"not found")<<"\n";
    cout<<"searchItr(5): "; cout<<(searchItr(root,5)?"found":"not found")<<"\n";

    cout<<"Min: "<<findMin(root)->data<<"  Max: "<<findMax(root)->data<<"\n";

    Node* s = inorderSuccessor(root,6); cout<<"Successor of 6: "<<(s?to_string(s->data):string("none"))<<"\n";
    Node* p = inorderPredecessor(root,6); cout<<"Predecessor of 6: "<<(p?to_string(p->data):string("none"))<<"\n";

    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
