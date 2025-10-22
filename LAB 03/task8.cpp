#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if (head == NULL){
        head = tail = newNode;
    } else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void concatenateLists(Node* &Lhead, Node* &Ltail, Node* Mhead, Node* Mtail){
    if (Mhead == NULL){
        return;
    }
    if (Lhead == NULL){
        Lhead = Mhead;
        Ltail = Mtail;
        return;
    }
    Ltail->next = Mhead;
    Mhead->prev = Ltail;
    Ltail = Mtail;
}
void printList(Node* head){
    Node* curr = head;
    while (curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main() {
    Node* Lhead = NULL;
    Node* Ltail = NULL;
    Node* Mhead = NULL;
    Node* Mtail = NULL;

    int Larr[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        insertAtTail(Lhead, Ltail, Larr[i]);
    }

    int Marr[3] = {4, 5, 6};
    for (int i = 0; i < 3; i++) {
        insertAtTail(Mhead, Mtail, Marr[i]);
    }
    cout << "List L: ";
    printList(Lhead);
    cout<<endl;
    
    cout << "List M: ";
    printList(Mhead);
    cout<<endl;

    concatenateLists(Lhead, Ltail, Mhead, Mtail);
    
    cout << "Concatenated list (L followed by M): ";
    printList(Lhead);

    return 0;
}