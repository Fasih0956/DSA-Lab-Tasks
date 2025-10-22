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
        int value = this -> data;
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory freed for value "<<value<<endl;
    }
};
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}
void insertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp ;
}
void insertAtTail(Node* &head ,Node* &tail , int d){
    if (head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
        return ;
    }
    Node* temp = new Node(d);
    tail -> next = temp ;
    tail =  temp;
}
void insertAtPosition(Node* &tail , Node* &head , int position , int d){
    Node* nodeInsert = new Node (d);
    Node* temp = head; 
    int count = 1;
       if(position == 1){
        insertAtHead(head, d);
        return ; 
    }
    while(count<position - 1){
        temp = temp -> next ;
        count++;
        if(temp -> next == NULL){
            insertAtTail(head ,tail , d);
            return ;
        }
    }
    nodeInsert ->next = temp -> next ; 
    temp -> next = nodeInsert;
}
// pass by node position , node position update after each deletion cannot do simultaneously 
/*void deleteNode(int position , Node* &head){
    if(position == 1){
        Node* curr = head;
        head= head -> next;
        curr -> next = NULL;
        delete curr;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr -> next ;
            count ++ ;
        }
        prev -> next = curr -> next ;
        curr -> next = NULL;
        delete curr;
    }*/
   // generic code not implemeneted for error values 

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
int main(){
    int array[5]={3,1,2,5,8};
    cout<<"<---Array elements are--->"<<endl;
    for (int i = 0 ; i<5 ; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0 ; i<5 ; i++){
        insertAtTail(head,tail,array[i]);
    }
    cout<<"<---Linked List elements are--->"<<endl;
    print(head);
    cout<<endl;
    cout<<"<---After Insertion--->"<<endl;
    insertAtTail(head, tail , 9);
    insertAtPosition(tail , head , 3 , 11);
    insertAtHead(head,4);
    print(head);
    cout<<endl;

    cout<<"<---Node Deletion--->"<<endl;
    deleteNode(1,head);  // pass by value
    deleteNode(2,head);
    deleteNode(5,head);
    print(head);

    cout<<endl;
}
