#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insert(node->left, val);
        else if (val > node->data) node->right = insert(node->right, val);
        return node;
    }
    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        else if (val < node->data) return search(node->left, val);
        else return search(node->right, val);
    }
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) current = current->left;
        return current;
    }
    Node* deleteNode(Node* node, int val) {
        if (!node) return node;
        if (val < node->data) node->left = deleteNode(node->left, val);
        else if (val > node->data) node->right = deleteNode(node->right, val);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};
int main() {
    BST tree;
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 80);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root); 
    cout <<endl;

    cout << "Searching 40: " << (tree.search(tree.root, 40) ? "Found" : "Not Found") << "\n";

    tree.root = tree.deleteNode(tree.root, 20);
    cout << "After deleting 20, inorder: ";
    tree.inorder(tree.root);
    cout <<endl;
    return 0;
}
