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
    ~Node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
         
    }
    cout<<endl;
}
void insertAtTail(Node* &head , Node* &tail , int d){
    if (head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
    return;
}
// position based deletion
void deleteNodeP(int position , Node* &head){
    if(position == 1 && head != NULL){
        Node* curr = head;
        head= head -> next;
        curr -> next = NULL;
        delete curr;
        return;
    }
    else {
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < position && curr != NULL){
            prev = curr;
            curr = curr -> next ;
            count ++ ;
        }
        if(curr == NULL){
            cout<<"Position out of bounds!"<<endl;
            return;
        }else{
        prev -> next = curr -> next ;
        curr -> next = NULL;
        delete curr;
        return;
    }
}
}
// value based deletion
void deleteNodeV(int value , Node* &head) {
    Node* temp = head ;
    Node* prev = NULL;
    if(value == head -> data){
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    while(temp->data != value){
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = temp ->next ;
    temp -> next = NULL;
    delete temp;
}
    int main(){
        Node* tail = NULL;
        Node* head = NULL;
    int array[5]={3,1,2,5,8};
    for(int i=0;i<5;i++){
        insertAtTail(head,tail,array[i]);
    }
    cout<<"<---Linked List elements are--->"<<endl;
    print(head);
    cout<<"<---Deleting elements by position--->"<<endl;   //only tested for position , can also test for value based deletion
        deleteNodeP(1, head);
        cout<<"After deleting from position 1 (Head)"<<endl;
        print(head);
        deleteNodeP(3, head);
        cout<<"After deleting from position 3"<<endl;
        print(head);
        deleteNodeP(4, head);
        cout<<"After deleting from position 4 (Tail)"<<endl;
        print(head);
    cout<<endl;
    return 0;
}
 