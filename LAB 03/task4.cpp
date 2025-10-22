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
void insertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp ;
}
void deleteNode(int value , Node* &head){
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
void ModifyList(Node* &head , Node* &tail){
    if(head == NULL){
        return;
    }
    Node* evenHead = NULL;
    Node* evenTail = NULL;
    Node* oddHead = NULL;
    Node* oddTail = NULL;
    Node* temp = head;
    int count=1;
    while(temp !=NULL){
        if(temp->data % 2 == 0){
            insertAtTail(evenHead,evenTail,temp->data);
        }
        else{
            insertAtTail(oddHead,oddTail,temp->data);
        }
        temp = temp -> next;
        count++;
    }
    if(evenHead != NULL){
        head = evenHead;
        evenTail->next = oddHead;
        if(oddTail != NULL){
            tail = oddTail;
        }else{
            tail = evenTail;
        }
        return;
    }
    else {
        head = oddHead;
        tail = oddTail;
        return;
    }
}
int main(){
    int array[3]={8,12,10};  //change array size and values to test
    cout<<endl;
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0 ; i<3 ; i++){   // also change loop limit , otherwise it will give garbage values
        insertAtTail(head,tail,array[i]);
    }
    cout<<"<---Linked List elements are--->"<<endl;
    print(head);
    cout<<endl;
    cout<<"<---After Modification--->"<<endl;
    ModifyList(head,tail);
    print(head);
    cout<<endl;
    return 0;
}