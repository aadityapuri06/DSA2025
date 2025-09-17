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


void findMiddle(Node* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head;

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    cout << "The middle element is: " << slow_ptr->data << endl;
}

int main() {
    Node* head = NULL;

    
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    cout << "Input: ";
    displayList(head);

    findMiddle(head);

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
