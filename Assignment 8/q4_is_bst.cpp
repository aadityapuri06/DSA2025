#include <iostream>
#include <climits>
using namespace std;

struct Node{int data; Node* left; Node* right; Node(int v):data(v),left(NULL),right(NULL){}
};

bool isBSTUtil(Node* r, int minv, int maxv){ if(!r) return true; if(r->data < minv || r->data > maxv) return false; return isBSTUtil(r->left, minv, r->data-1) && isBSTUtil(r->right, r->data+1, maxv); }

int main(){
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);

    cout << (isBSTUtil(root, INT_MIN, INT_MAX) ? "This is a BST\n" : "Not a BST\n");

    // make a non-BST by violating left < root rule
    root->right->left = new Node(9);
    root->right->right = new Node(5); // 5 < 10 but 5 is in right subtree of 8 -> breaks BST

    cout << (isBSTUtil(root, INT_MIN, INT_MAX) ? "This is a BST\n" : "Not a BST\n");

    cout<<"\nPress Enter to exit..."; cin.ignore(); cin.get();
    return 0;
}
