#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    ~Node() {
        cout << data << " deleted successfully!" << endl;
    }
};
void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}
void insertAtHead(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        temp->next = temp;
        head = tail = temp;
        cout<<d<<" inserted successfully!"<<endl;
        return;
    }
    temp->next = head;
    tail->next = temp;
    head = temp;
    cout<<d<<" inserted successfully!"<<endl;
}
void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        temp->next = temp;
        head = tail = temp;
        cout<<d<<" inserted successfully!"<<endl;
        return;
    }
    tail->next = temp;
    temp->next = head;
    tail = temp;
    cout<<d<<" inserted successfully!"<<endl;
}
void insertAtPosition(Node* &head, Node* &tail, int pos, int d) {
    if (pos == 1) {
        insertAtHead(head, tail, d);
        return;
    }
    Node* temp = new Node(d);
    Node* curr = head;
    int count = 1;
    while (count < pos - 1 && curr->next != head) {
        curr = curr->next;
        count++;
    }
    temp->next = curr->next;
    curr->next = temp;
    cout<<d<<" inserted successfully!"<<endl;
    if (curr == tail) {
        tail = temp;
    }
}
void deleteNode(Node* &head, Node* &tail, int val) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head == tail && head->data == val) {
        delete head;
        head = tail = NULL;
        return;
    }
    Node* curr = head;
    Node* prev = tail;
    do {
        if (curr->data == val) {
            if (curr == head) {
                head = head->next;
                tail->next = head;
            }
            else if (curr == tail) {
                tail = prev;
                tail->next = head;
            }
            else {
                prev->next = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    cout << "Value " << val << " not found!" << endl;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 27);  // in last
    print(head);
    insertAtHead(head, tail, 15);  // in beginning
    print(head);
    insertAtTail(head, tail, 28);
    print(head);
    insertAtTail(head, tail, 50);
    print(head);
    insertAtPosition(head, tail, 3, 12);  // at position
    print(head);
    deleteNode(head, tail, 50);  // deleting node
    cout << "After deleting 50: ";
    print(head);  // printing list

    return 0;
}