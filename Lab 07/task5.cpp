#include<iostream>
class Node {
    public:
    int data ;
    Node* next ;
    Node(int data) {
        this-> data = data ;
        this-> next = NULL ;
    }
};
void insertAtTail(Node* &head , Node*&tail , int val) {
    Node* newNode = new Node (val) ;
    if (head == NULL) {
        head = newNode ;
        tail = newNode ;
        return ;
    }
    else {
        tail -> next = newNode ;
        tail = newNode ;
        return ;
    }
}
void swap (Node* &head , Node* &tail) {


}
Node* findpivot (Node* &head , Node* &tail ){
    Node* pivot = tail ;
    while ( head != NULL) {

    }
}
void sortquick(Node* &head , Node* &tail) {
    if (head >= tail) {
        return ;
    }
    Node* pivot = findpivot(head , tail) ;
    sortquick(head , pivot) ;
    sortquick ( pivot -> next , tail) ;
}