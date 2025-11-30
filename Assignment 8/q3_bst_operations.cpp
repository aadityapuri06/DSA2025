#include <iostream>
#include <algorithm>
using namespace std;

struct Node{int data; Node* left; Node* right; Node(int v):data(v),left(NULL),right(NULL){}
};

Node* insert(Node* r, int v){ if(!r) return new Node(v); if(v==r->data) return r; if(v<r->data) r->left = insert(r->left,v); else r->right = insert(r->right,v); return r; }

Node* findMin(Node* r){ if(!r) return NULL; while(r->left) r=r->left; return r; }

Node* removeNode(Node* r, int key){ if(!r) return NULL; if(key<r->data) r->left = removeNode(r->left,key);
 else if(key>r->data) r->right = removeNode(r->right,key);
 else { if(!r->left){ Node* t = r->right; delete r; return t;} else if(!r->right){ Node* t = r->left; delete r; return t; } else { Node* succ = findMin(r->right); r->data = succ->data; r->right = removeNode(r->right, succ->data); } }
 return r; }

int maxDepth(Node* r){ if(!r) return 0; int l = maxDepth(r->left); int ri = maxDepth(r->right); return 1 + (l>ri?l:ri); }
int minDepth(Node* r){
    if(!r) return 0;
    if(!r->left && !r->right) return 1;
    if(!r->left) return 1 + minDepth(r->right);
    if(!r->right) return 1 + minDepth(r->left);
    return 1 + min(minDepth(r->left), minDepth(r->right));
}

void inorder(Node* r){ if(!r) return; inorder(r->left); cout<<r->data<<" "; inorder(r->right); }

int main(){
    Node* root = NULL;
    int vals[] = {8,3,10,1,6,14,4,7,13};
    for(int v:vals) root = insert(root,v);

    cout<<"Inorder before delete: "; inorder(root); cout<<"\n";
    root = removeNode(root,6);
    cout<<"Inorder after delete 6: "; inorder(root); cout<<"\n";

    cout<<"Max depth: "<<maxDepth(root)<<"\n";
    cout<<"Min depth: "<<minDepth(root)<<"\n";

    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
