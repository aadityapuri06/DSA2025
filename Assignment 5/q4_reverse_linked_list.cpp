#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
};


void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}


void displayList(Node* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}


void reverseList(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;

    while (current != NULL) {
        
        next = current->next;
        
        current->next = prev;
        
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main() {
    Node* head = NULL;

    
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    cout << "Input: ";
    displayList(head);

    reverseList(&head);

    cout << "Output: ";
    displayList(head);

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
