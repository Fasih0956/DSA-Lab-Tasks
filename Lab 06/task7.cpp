#include<iostream>
#include<string>
using namespace std;

class Queue {
public:
    string patrons[20];
    int front, rear, size;
    Queue() {
        front = -1;
        rear = -1;
        size = 20;
    }
    bool isEmpty(){
        return (front == -1 || front > rear);
    }
    bool isFull(){
        return (rear == size - 1);
    }
    void enqueue(string name){
        if (isFull()){
            cout<<"Queue is full! Cannot add "<<name<<" right now."<<endl;
            return;
        }
        if (front == -1) front = 0;
        patrons[++rear] = name;
        cout << name << " has joined the queue."<<endl;
    }
    void dequeue(){
        if (isEmpty()){
            cout << "No patrons to serve!"<<endl;
            return;
        }
        cout<<patrons[front]<<" has completed their book transaction."<<endl;
        front++;
    }
    void display(){
        if (isEmpty()){
            cout<<"Queue is empty! No patrons waiting."<<endl;
            return;
        }
        cout<<"Current Queue (front → rear): ";
        for (int i = front; i <= rear; i++) {
            cout<<patrons[i];
            if (i < rear) cout<<" → ";
        }
        cout << endl;
    }
};
int main() {
    Queue libraryQueue;
    int choice;
    string name;

    cout << "<---Library Book Transaction Queue--->"<<endl;;

    while (true){
        cout<<endl;
        cout<<"1. Add Patron to Queue (Borrow/Return)"<<endl;
        cout<<"2. Handle Patron"<<endl;
        cout<<"3. Display Queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
        case 1:
            cout<<"Enter Patron Name: ";
            cin>>name;
            libraryQueue.enqueue(name);
            break;
        case 2:
            libraryQueue.dequeue();
            break;
        case 3:
            libraryQueue.display();
            break;
        case 4:
            cout<<"Good Bye !"<<endl;
            return 0;
        default:
            cout << "Invalid choice! Try Again !"<<endl;
        }
    }
    return 0;
}
