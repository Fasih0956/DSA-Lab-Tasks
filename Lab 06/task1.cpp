#include<iostream>
using namespace std;
class stack {
    public:
    string arr[10];
    const int size = 10; //can be increased to manage more tasks
    int top ;
    stack() {
        top = -1 ;
    }
    void addItem(const string &s){
    if(top >= size - 1) {
        cout<<"Stack is full!"<<endl ;
        return ;
    }
    else {
        arr[++top] = s;
        cout<<"Task "<<s<<" added successfully"<<endl;
    }
}
    bool isempty() {
    if(top<0) {
        return true ;
    }
    else {
        return false ;
    }
}
    void removeItem(){
        if(isempty()) {
            return ;
        }
        else {
            string str = arr[top] ;
            top -- ;
            cout<<"Task "<<str<<" removed successfully ! "<<endl ;
        }
    }
    void displayAll() const {
        if (top < 0) {
            cout << "No tasks to display." << endl;
            return;
        }
        cout << "<---All tasks in stack--->" << endl;
        for (int i = top; i >= 0; i--) {
            cout << i << ": " << arr[i] << endl;
        }
    }
};
int main() {
    stack stack1 ;
    stack1.addItem("DSA Lab Tasks");
    stack1.addItem("DIS Assignment");
    stack1.addItem("TOA Assignemnt");
    cout<<endl ;

    stack1.displayAll() ;
    cout<<endl;

    bool empty = stack1.isempty() ;
    if(empty) {
        cout<<"Stack is empty !"<<endl;
    }
    else {
        cout<<"Stack is not empty !"<<endl ;
    }
    cout<<endl;
    stack1.removeItem();
    cout<<endl;

    stack1.displayAll() ;
    return 0;
}