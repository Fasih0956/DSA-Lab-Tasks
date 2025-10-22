#include<iostream>
#include<string>
using namespace std;
template<typename T>
class Node{
    public:
    T data;
    Node* next;
    Node(T data){
        this ->data = data;
        this -> next = NULL;
    }
};
template<typename T>
void insertAtTail(Node<T>* &head ,Node<T>* &tail , T d){
    Node<T>* newNode = new Node<T>(d);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return ;
    }
    else {
        tail -> next = newNode;
        tail = newNode;
        return;
    }
}
template <typename T>
void print(Node<T>* &head){
    Node<T>* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
}
template <typename T>
    Node<T>* findMiddle(Node<T>* &head){
        Node<T>* slow = head ;
        Node<T>* fast = head -> next;
        while( fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next ;
        }
        return slow;
    }
template< typename T>
Node<T>* reverse(Node<T>* temp){
    Node<T>* curr = temp;
    Node<T>* prev = NULL;
    Node<T>* next = NULL;

    while(curr!=NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}    
template <typename T>
bool checkPalindrome(Node<T>* &head){
    if(head == NULL){
        cout<<"List is empty!"<<endl;
        return 0;
    }
    else if( head -> next == NULL){
        return true;
    }
    else{
        Node<T>* middle = findMiddle(head);
        Node<T>* temp = middle -> next;
        middle -> next = reverse(temp);
        Node<T>* head1= head;
        Node<T>* head2 =middle -> next;
        while(head2!=NULL){
        if(head1->data != head2 -> data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}
}
int main(){
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    int arr[5]={1,0,2,0,1};  // for integers
    for(int x:arr){
        insertAtTail(head,tail,x);
    }
    cout<<"<---Linked List Elements (Integers)--->"<<endl;
    print(head);
    cout<<endl;

    bool found=checkPalindrome(head);
if(!found){
    cout<<"Linked List is not a Palindrome."<<endl;
}
else{
    cout<<"Linked List is a Palindrome."<<endl;
}
cout<<endl;

    Node<char>* headc = NULL;
    Node<char>* tailc = NULL;
string word = "borroworrob";  // for string
for(char c:word){
    insertAtTail(headc,tailc,c);
}
cout<<"<---Linked List Elements (string)--->"<<endl;
print(headc);
cout<<endl;

 found=checkPalindrome(headc);
if(!found){
    cout<<"Linked List is not a Palindrome."<<endl;
}
else{
    cout<<"Linked List is a Palindrome."<<endl;
}
cout<<endl;
return 0;
}