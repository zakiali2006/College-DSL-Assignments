#include <iostream>
 #include <stack>
 using namespace std;
 struct Node {
    int data;
    Node* next;
 };
 class LinkedList {
 private:
    Node* head;
 public:
    LinkedList() {
        head = NULL;
    }
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverseUsingStack() {
        if (head == NULL) {
            cout << "List is empty. Nothing to reverse.\n";
            return;
        }
        stack<Node*> s;
        Node* temp = head;
        while (temp != NULL) {
            s.push(temp);
            temp = temp->next;
        }
        head = s.top();
        s.pop();
        temp = head;
        while (!s.empty()) {
            temp->next = s.top();
            s.pop();
            temp = temp->next;
        }
        temp->next = NULL;
        cout << "List reversed successfully\n";
    }
 };
 int main() {
    LinkedList list;
    int choice, value;
    do {
        cout << "\nMenu\n";
        cout << "1. Insert Node\n";
        cout << "2. Display List\n";
        cout << "3. Reverse using Stack\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insert(value);
            break;
        case 2:
            list.display();
            break;
        case 3:
            list.reverseUsingStack();
            break;
        case 0:
            cout << "Exiting";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
 }