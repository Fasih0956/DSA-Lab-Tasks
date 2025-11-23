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
};
void printL(Node* &head){
Node* temp = head;
    while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp -> next;
}
cout<<endl;
}
int findLen(Node* &head , int c){
    if(head == NULL){
    return c;
}
else findLen(head->next , c+1);
}
void insertAtTail(Node* &head , Node* &tail , int v ){
Node* temp = new Node(v);
if(head == NULL) {
head = temp;
tail = temp;
return;
}else{
tail -> next = temp ;
tail = temp;
return;
}
}
int main(){
Node* head = NULL;
Node* tail = NULL;
int count = 0;
insertAtTail(head,tail,10);
insertAtTail(head,tail,12);
insertAtTail(head,tail,15);
printL(head);
int len = findLen(head , count);
cout<<"Length of Linked List = "<<len<<endl;
return 0;
}