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
void insertAtTail(Node* &head , Node* &tail , int d){
    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp ;
        return;
    }
}
bool search(Node*head, int val){
    if(head==NULL){
         return false;
    }
    else{
        bool found = search(head->next, val);
        if(head->data == val){
            found = true;
        }
        return found;
    }
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,15);
    insertAtTail(head,tail,21);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,45);

    bool found = search(head,31);
    if(found){
        cout<<"FOUND"<<endl;
    }else{
        cout<<"NOT FOUND"<<endl;
    }
    return 0;
}