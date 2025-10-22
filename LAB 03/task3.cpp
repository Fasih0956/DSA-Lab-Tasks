// Simpler Version 
#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    string name;
    Node* next;
    Node( string name){
        this -> name = name;
        this -> next = NULL;
    }
    ~Node(){
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    }
};
void insertAtHead(Node* &head ,Node* &tail,  string n){
    Node* temp = new Node(n);
     if (head == NULL){
        head = temp;
        tail = temp;
        cout<<n<<" has Reserved a ticket Successfully!"<<endl;
        return;
    }
    else{
    temp -> next = head;
    head = temp ;
    cout<<n<<" has Reserved a ticket Successfully!"<<endl;
    return;
    }
}
void insertAtPosition(Node* &head , Node* &tail , string n){
    Node* temp = new Node(n);
    Node* curr =head;
    if (head == NULL){
        head = temp;
        tail = temp;
        cout<<n<<" has reserved a ticket successfully!"<<endl;
        return;
    }
    while(curr ->next != NULL && curr->next->name < n){
        curr = curr ->next;

    }
    temp ->next = curr -> next;
    curr -> next = temp;
    cout<< n<<" has reserved a ticket successfully!"<<endl;
    return;
}
void ReserveTicket(Node* &head , Node* &tail , string n){
        if(head == NULL || n < head->name){
            insertAtHead(head,tail,n);
        }
        else{
            insertAtPosition(head ,tail , n);
        }
    }
void CancelReservation(Node* &head , Node* &tail , string n) { 
    Node* curr = head;
    Node* prev = NULL;
    if(curr != NULL && curr->name == n) {
        head = curr -> next;
        curr -> next = NULL;
        delete curr;
        cout<<"Reservation deleted for "<<n<<endl;
        return;
    }
while (curr != NULL && curr->name != n) {
    prev = curr;
    curr = curr->next;
}
if (curr == NULL) { 
    cout<<"Reservation Not found"; 
    return;
 }
if (curr->name == n && prev == NULL) {
     head = curr->next; // deleting head
     curr->next = NULL;
     delete curr;
     cout<<"Reservation deleted for "<<n<<endl;
        return;
} else {
 prev->next = curr->next;
 curr->next = NULL;
 delete curr;
    cout<<"Reservation deleted for "<<n<<endl;
    return;
}
}
void CheckReservation(Node* &head , string n){
    Node* temp = head;
    while(temp !=NULL ){
        if (temp->name == n){
            cout<<"Reservation found for "<<n<<endl;
            return;
        } 
        else {
            temp = temp ->next;
        }
    }
    cout<<"No Reservation Found!"<<endl;
}
void DisplayPassengers(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->name<<endl;
        temp = temp ->next;
    }
}

int main(){
    int choice;
    string name;
    Node* head = NULL;
    Node* tail = NULL;

    while(5) {
    cout<<"<--- MENU --->"<<endl;
    cout<<"1.Reserve a Ticket."<<endl;
    cout<<"2.Cancel a Reservation."<<endl;
    cout<<"3.Check Reservation."<<endl;
    cout<<"4.Display Passengers."<<endl;
    cout<<"5.Exit."<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

    switch(choice) {
        case 1:
        cout<<"Enter Passenger Name to reserve a ticket: ";
        cin.ignore();
        getline(cin,name);
        ReserveTicket(head,tail,name);
        break;
        case 2: 
        cout<<"Enter Passenger Name to cancel a ticket: ";
        cin.ignore();
        getline(cin,name);
        CancelReservation(head,tail,name);
        break;
        case 3: 
        cout<<"Enter Passenger Name to check reservation: ";
        cin.ignore();
        getline(cin,name);
        CheckReservation(head,name);
        break;
        case 4: 
        DisplayPassengers(head);
        break;
        case 5: 
        cout<<"GOOD BYE!"<<endl;
        return 0;
        break;
        default:
        cout<<"Invalid Choice!"<<endl;
    }
}
    cout<<endl;
    return 0;
}

