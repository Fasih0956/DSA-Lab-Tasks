#include<iostream>
#include<string>
using namespace std;
class Stack {
public:
    char arr[50];
    int top;
    const int size = 50;
    Stack() { top = -1; }
    void push(char c) {
        if (top >= size - 1) return;
        arr[++top] = c;
    }
    void pop() {
        if (top == -1) return;
        top--;
    }
    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
};
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char c : infix) {
        if (isalpha(c)) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.peek();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                if (c == '^' && s.peek() == '^') break;
                postfix += s.peek();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.peek();
        s.pop();
    }
    return postfix;
}
int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    string postfix = infixToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    return 0;
}
