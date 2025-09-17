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
    if (node == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}


void countAndDeleteOccurrences(Node** head_ref, int key) {
    int count = 0;
    Node* current = *head_ref;
    Node* prev = NULL;

    
    while (current != NULL) {
        if (current->data == key) {
            count++;
           
            if (prev == NULL) {
                *head_ref = current->next;
                delete current;
                current = *head_ref;
            } else { 
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
    cout << "Count: " << count << endl;
}

int main() {
    Node* head = NULL;

    
    append(&head, 1);
    append(&head, 2);
    append(&head, 1);
    append(&head, 2);
    append(&head, 1);
    append(&head, 3);
    append(&head, 1);

    cout << "Original Linked List: ";
    displayList(head);

    int key = 1;
    cout << "\nDeleting all occurrences of key: " << key << endl;
    countAndDeleteOccurrences(&head, key);

    cout << "Updated Linked List: ";
    displayList(head);

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
