#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    Node(string d) : data(d), next(0) {}
};
class Stack {
    public:
    Node* top;
    Stack() : top(0) {}
    void push(string item){
        Node* node = new Node(item);
        node->next = top;
        top = node;
    }
    string pop(){
        if (!top) return "";
        string item = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return item;
    }
    string peek(){
        return top ? top->data : "";
    }
    void print(){
        Node* curr = top;
        while (curr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
int main(){
    Stack stack;
    stack.push("x");
    stack.push("=");
    stack.push("12");
    stack.push("+");
    stack.push("13");
    stack.push("-");
    stack.push("5");
    stack.push("*");
    stack.push("(");
    stack.push("0.5");
    stack.push("+");
    stack.push("0.5");
    stack.push(")");
    stack.push("+");
    stack.push("1");

    double parenVal = 0.5 + 0.5;
    double result = 12 + 13 - 5 * parenVal + 1; // result = 21 not 20

    while(stack.peek() != "=") stack.pop();

    stack.push(to_string((int)result));
    stack.print();
    return 0;
}