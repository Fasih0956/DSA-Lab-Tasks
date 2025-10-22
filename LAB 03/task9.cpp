#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node( int data){
        this -> data = data;
        this ->next = NULL;
    }
};
void insertAtHead(Node* &head ,Node* &tail, int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        temp -> next = head;
        head = temp ;
        return;
    }
}
void insertAtTail(Node* &head , Node* &tail , int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else {
        tail -> next = temp ;
        tail = temp;
        return;
    }

}
void ModifyList(Node* &head , Node* &tail){
    if(head == NULL){
    return;
    }
    Node* alterhead = NULL;
    Node* altertail = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int pos = 1;
    while(curr != NULL){
        Node* nextNode = curr->next;
        if(pos % 2 == 0){
            if(prev != NULL){
                prev->next = curr->next;
            }
            if(curr == tail){
                tail = prev;
            }
            curr->next = NULL;
            insertAtHead(alterhead,altertail,curr->data);
        } else {
            prev = curr; // only advance prev if not removed
        }
        curr = nextNode;
        pos++;
    }
    // Appending
    if(alterhead != NULL){
        tail->next = alterhead;
        tail = altertail;
    }
}
void print(Node* &head){
    Node* temp = head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    return;
}
int main(){
    int arr[8]={10 , 4 , 9 , 1 , 3 , 5 , 9 ,4};   // Linked list elements stored in a array
    Node* head = NULL;
    Node* tail = NULL;
    for (int i=0 ; i<8 ;i++){
        insertAtTail(head,tail,arr[i]);    // Creation of linked list
    };

    cout<<"<---Linked List elements are--->"<<endl;
    print(head);   
    cout<<endl;

    ModifyList(head,tail);

    cout<<"<---Modified List--->"<<endl;
    print(head);
    cout<<endl;

    return 0;
}