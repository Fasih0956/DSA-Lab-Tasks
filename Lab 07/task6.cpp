#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return ;
    } else {
        tail->next = newNode;
        tail = newNode;
        return ;
    }
}
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL;
    Node* cur = head;
    Node* tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;

            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;
    return pivot;
}
Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;
    Node* newHead = NULL;
    Node* newEnd = NULL;
    Node* pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        Node* tail = newHead;
        while (tail->next)
            tail = tail->next;
        tail->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}
// void quickSort(Node*& head) {
//     Node* tail = head;
//     while (tail && tail->next)
//         tail = tail->next;
//     head = quickSortRecur(head, tail);
// }
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 8);
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 3);

    cout << "Before sorting: ";
    printList(head);

    quickSortRecur(head,tail);

    cout << "After sorting: ";
    printList(head);

    return 0;
}
