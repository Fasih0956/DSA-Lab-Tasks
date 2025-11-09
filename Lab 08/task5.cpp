//considiering only positive values for nodes in this task
#include<iostream>
#include<climits>  // for int_min
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
bool check(Node* node, int minVal, int maxVal) {
    if (!node) return true; // Empty tree is BST
    if (node->data <= minVal || node->data >= maxVal) return false;
    return check(node->left, minVal, node->data) &&
           check(node->right, node->data, maxVal);
}
bool isBST(Node* root) {
    return check(root, 0, INT_MAX);  //conaidering least and max possible values
}
int main() {
    //case 1
    Node* root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(20);
    root1->right->left = new Node(9);
    root1->right->right = new Node(25);

    if (isBST(root1)) cout << "Tree 1 is a BST"<<endl;
    else cout << "Tree 1 is NOT a BST"<<endl;

    //case 2
    Node* root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(3);
    root2->right->right = new Node(5);

    if (isBST(root2)) cout << "Tree 2 is a BST"<<endl;
    else cout << "Tree 2 is NOT a BST"<<endl;

    return 0;
}
