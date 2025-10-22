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
            this->next == NULL;
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
void deleteNode(Node* &head , Node* &tail , int position){
    if(position == 1){
    Node * curr = head;
    head = head -> next;
    curr -> next = NULL;
    delete curr; 
    return ;   
    }
    else{
        Node*curr = head;
        Node*prev = NULL;
        int count = 1;
        while ( count < position){
            prev = curr;
            curr = curr -> next;
            count++;

        }
        prev -> next = curr -> next ;
        curr -> next = NULL;
        delete curr;
    }

}
int main(){
    int size;
    int val;
    int m;
    cout<<"Enter size of Linked List: ";
    cin>>size;
    cout<<endl;
    Node* head = NULL;
    Node* tail = NULL;
    for(int i=0; i<size ; i++){
        cout<<"Enter value of Node "<<i+1<<":";
        cin>>val;
        insertAtTail(head,tail,val);
    }
    cout<<endl;
    cout<<"<---List before moving Elements--->"<<endl;
    print (head);
    cout<<endl;
    cout<<"Enter how many elements you want to move to the end: ";
    cin>>m;
    cout<<endl;
    for(int j=0 ; j<m ;j++){
        insertAtTail(head , tail , head->data);
        deleteNode(head , tail , 1);
    }
    cout<<"<---List after moving Elements--->"<<endl;
    print(head);
    cout<<endl;
    return 0;
}