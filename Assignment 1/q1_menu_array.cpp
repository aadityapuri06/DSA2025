
#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX], n = 0;

void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void display() {
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insert() {
    int pos, val;
    cout << "Enter position (0-based): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;
    for (int i = n; i > pos; i--)
        arr[i] = arr[i-1];
    arr[pos] = val;
    
    n++;
}

void del() {
    int pos;
    cout << "Enter position to delete (0-based): ";
    cin >> pos;
    for (int i = pos; i < n-1; i++)
        arr[i] = arr[i+1];
    n--;
}

void linear_search() {
    int val, found = 0;
    cout << "Enter value to search: ";
    cin >> val;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Found at position " << i << endl;
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "Not found" << endl;
}

int main() {
    int ch;
    do {
        cout << "\nMENU\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: linear_search(); break;
        }
    } while(ch != 6);
    return 0;
}
