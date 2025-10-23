#include<iostream>
using namespace std;
class Node{
    public:
    string url;
    Node* next;
    Node(string u) : url(u), next(nullptr) {}
};
class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    void push(const string& url) {
        Node* newNode = new Node(url);
        newNode->next = top;
        top = newNode;
    }
    void pop() {
        if (top == nullptr) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    string peek() {
        if (top == nullptr) return "No pages left.";
        return top->url;
    }
    bool isEmpty() {
        return top == nullptr;
    }
};
class LinkedList{
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    void addFront(const string& url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
    }
    void removeFront() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void display() const {
        cout << "Browsing History: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->url;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};
void goBack(Stack& s, LinkedList& list, int steps) {
    for (int i = 0; i < steps; i++) {
        if (!s.isEmpty()) {
            s.pop();
            list.removeFront();
        } else break;
    }
    cout << "Now at page: " << s.peek() << endl;
}
int main() {
    Stack historyStack;
    LinkedList historyList;
    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (int i = 0; i < 5; i++) {
        historyStack.push(sites[i]);
        historyList.addFront(sites[i]);
    }
    historyList.display();
    goBack(historyStack, historyList, 3); //needed to go back thrice not twice to access facebook
    historyList.display();
    return 0;
}
