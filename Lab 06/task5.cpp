#include<iostream>
using namespace std;
class Queue {
public:
    int arr[10];
    int front, rear, size;
    Queue(){
        front= -1;
        rear= -1;
        size= 10;
    }
    bool isEmpty(){
        return (front == -1 || front > rear);
    }
    bool isFull(){
        return (rear == size - 1);
    }
    void enqueue(int id){
        if(isFull()){
            cout<< "Queue is full! No new customer can be added ! "<<id<<endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear]= id;
        cout<<"Customer "<<id<<" joined the queue."<<endl;
    }
    void dequeue(){
        if (isEmpty()){
            cout<<"No customers to checkout !"<<endl;
            return;
        }
        cout<<"Customer "<<arr[front]<<" checked out."<<endl;
        front++;
    }
    void display(){
        if (isEmpty()){
            cout<<"Queue is empty!"<<endl;
            return;
        }
        cout<< "Current Queue: ";
        for (int i = front; i <= rear; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue checkoutQueue;
    int customers[] = {13, 7, 4, 1, 6, 8, 10};
    int n = 7;
    for (int i = 0; i < n; i++) {
        checkoutQueue.enqueue(customers[i]);
    }cout<<endl;
    checkoutQueue.display();
    cout<<endl;

    checkoutQueue.dequeue();
    checkoutQueue.dequeue();
    checkoutQueue.dequeue();
    cout<<endl;

    checkoutQueue.display();
    cout<<endl;
    return 0;
}
