#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
};

Node* head = NULL;


void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Node inserted at the beginning." << endl;
}


void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Node inserted at the end." << endl;
}


void insertAfterNode(int searchValue, int newValue) {
    Node* temp = head;
    while (temp != NULL && temp->data != searchValue) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with value " << searchValue << " not found." << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Node " << newValue << " inserted after " << searchValue << "." << endl;
}


void insertBeforeNode(int searchValue, int newValue) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    if (head->data == searchValue) {
        insertAtBeginning(newValue);
        cout << "Node " << newValue << " inserted before " << searchValue << "." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != searchValue) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Node with value " << searchValue << " not found." << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = newValue;
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Node " << newValue << " inserted before " << searchValue << "." << endl;
}



void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Node deleted from the beginning." << endl;
}


void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Node deleted from the end." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    cout << "Node deleted from the end." << endl;
}


void deleteSpecificNode(int value) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    if (head->data == value) {
        head = head->next;
        delete temp;
        cout << "Node with value " << value << " deleted." << endl;
        return;
    }
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    cout << "Node with value " << value << " deleted." << endl;
}


void searchNode(int value) {
    Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << "Node with value " << value << " found at position " << position << "." << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Node with value " << value << " not found in the list." << endl;
}


void displayList() {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    cout << "Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int choice, value, searchValue, newValue;

    do {
        cout << "\n--- Singly Linked List Menu ---" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert after a node" << endl;
        cout << "4. Insert before a node" << endl;
        cout << "5. Delete from the beginning" << endl;
        cout << "6. Delete from the end" << endl;
        cout << "7. Delete a specific node" << endl;
        cout << "8. Search for a node" << endl;
        cout << "9. Display all node values" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(value);
                break;
            case 3:
                cout << "Enter the value of the node to insert after: ";
                cin >> searchValue;
                cout << "Enter the new value to insert: ";
                cin >> newValue;
                insertAfterNode(searchValue, newValue);
                break;
            case 4:
                cout << "Enter the value of the node to insert before: ";
                cin >> searchValue;
                cout << "Enter the new value to insert: ";
                cin >> newValue;
                insertBeforeNode(searchValue, newValue);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cout << "Enter value of the node to delete: ";
                cin >> value;
                deleteSpecificNode(value);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;
            case 9:
                displayList();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
