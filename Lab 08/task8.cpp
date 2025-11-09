#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int countInRange(Node* node, int a, int b) {
    if (!node) return 0;
    int count = 0;
    if (node->data >= a)
        count += countInRange(node->left, a, b);
    if (node->data >= a && node->data <= b) {
        cout << node->data << " "; // printing
        count++;
    }
    if (node->data <= b)
        count += countInRange(node->right, a, b);

    return count;
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int a = 5, b = 45;
    cout << "Nodes in range [" << a << ", " << b << "]: ";
    int cnt = countInRange(root, a, b);
    cout<<endl;
    cout << "Total count = " << cnt << endl;

    return 0;
}
