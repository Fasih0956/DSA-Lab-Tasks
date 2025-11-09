#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, int val) {
        if(!node) return new Node(val);
        if(val < node->data) node->left = insert(node->left, val);
        else if(val > node->data) node->right = insert(node->right, val);
        return node;
    }
    bool search(Node* node, int val) {
        if(!node) return false;
        if(node->data == val) return true;
        else if(val < node->data) return search(node->left, val);
        else return search(node->right, val);
    }
    void inorder(Node* node) {
        if(!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};
int main(){
    BST tree;
    int values[] = {50, 30, 70, 20, 40};
    int len = sizeof(values)/sizeof(int);
    for (int i = 0 ; i<len ; i++ ){
    for(int v: values) tree.root = tree.insert(tree.root, values[i]);
    }
    cout << "Initial BST: ";
    tree.inorder(tree.root); cout <<endl;
    int val;
    cout << "Enter value to search/insert: ";
    cin>>val;
    if(tree.search(tree.root, val)) cout << val << " already exists in BST."<<endl;
    else {
        tree.root =tree.insert(tree.root, val);
        cout<< val << " inserted into BST."<<endl;
    }
    cout << "Updated BST: ";
    tree.inorder(tree.root); 
    cout <<endl;;
    return 0;
}
