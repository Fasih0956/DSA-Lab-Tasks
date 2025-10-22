#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    ~Node(){
       int  value = this -> data;
        cout<<value<<" deleted successfully !"<<endl;
    }
};
void insertAtHead(Node* &head , Node* &tail , int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        temp->next = temp;
        cout<<d<<" inserted at Head successfully !"<<endl;
        return;
    }
    else{
        Node* curr = head;
        Node* prev = tail;
        prev -> next = temp;
        temp -> next = head;
        head = temp;
        cout<<d<<" inserted at Head successfully !"<<endl;
        return;
    }
}
void print(Node* & head){
    if(head == NULL){
        cout<<"List is Emprty !"<<endl;
        return;
    }
    Node* curr = head;
    do{
        cout<<curr->data<<" ";
        curr = curr -> next;
    }
    while(curr!=head);
    return;
}
int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,15);
    insertAtHead(head,tail,17);
    insertAtHead(head,tail,19);
    insertAtHead(head,tail,21);
    insertAtHead(head,tail,23);

    cout<<"<---Circular Linked List Elements--->"<<endl;
    print(head);
    
    return 0;
    
}