#include<iostream>
#include<string>
#include<vector>  //used for efficiency and simplicity
using namespace std;
class Student{
    public:
    string name;
    int roll;
    int score;
    Student(string n, int r, int s) : name(n), roll(r), score(s) {}
};
class Node {
    public:
    Student* s;
    Node* left;
    Node* right;
    Node(Student* student) : s(student), left(nullptr), right(nullptr) {}
};
class BST {
public:
    Node* root;
    BST() { root = nullptr; }

    Node* insert(Node* node, Student* s) {
        if(!node) return new Node(s);
        if(s->name < node->s->name) node->left = insert(node->left, s);
        else node->right = insert(node->right, s);
        return node;
    }
    Node* minNode(Node* node) {
        Node* current = node;
        while(current && current->left) current = current->left;
        return current;
    }
    Node* deleteNode(Node* node, string name) {
        if(!node) return node;
        if(name < node->s->name) node->left = deleteNode(node->left, name);
        else if(name > node->s->name) node->right = deleteNode(node->right, name);
        else {
            if(!node->left) { Node* temp = node->right; delete node->s; delete node; return temp; }
            else if(!node->right) { Node* temp = node->left; delete node->s; delete node; return temp; }
            Node* temp = minNode(node->right);
            node->s = temp->s;
            node->right = deleteNode(node->right, temp->s->name);
        }
        return node;
    }
    void inorder(Node* node) {
        if(!node) return;
        inorder(node->left);
        cout << node->s->name << "(" << node->s->score << ") ";
        inorder(node->right);
    }
    void deleteLowScore(Node* node, BST &tree) {
        if(!node) return;
        deleteLowScore(node->left, tree);
        deleteLowScore(node->right, tree);
        if(node->s->score < 10) tree.root = tree.deleteNode(tree.root, node->s->name);
    }
    Node* maxScore(Node* node) {
        if(!node) return nullptr;
        Node* leftMax = maxScore(node->left);
        Node* rightMax = maxScore(node->right);
        Node* maxNode = node;
        if(leftMax && leftMax->s->score > maxNode->s->score) maxNode = leftMax;
        if(rightMax && rightMax->s->score > maxNode->s->score) maxNode = rightMax;
        return maxNode;
    }
};
int main() {
    BST tree;
    vector<Student*> students = {
        new Student("Ali", 1, 12),
        new Student("Sara", 2, 8),
        new Student("Fasih", 3, 15),
        new Student("Hassan", 4, 20),
        new Student("Ahmed", 5, 5),
        new Student("Saad", 6, 18),
        new Student("Rehan", 7, 9),
        new Student("Nadia", 8, 14),
        new Student("Bilal", 9, 11),
        new Student("Faisal", 10, 7)
    };
    for(int i=0; i<7; i++) tree.root = tree.insert(tree.root, students[i]);

    cout << "BST Inorder: ";
    tree.inorder(tree.root);
    cout <<endl;

    tree.deleteLowScore(tree.root, tree);
    cout << "After deleting score<10: ";
    tree.inorder(tree.root);
    cout <<endl;

    Node* maxNode = tree.maxScore(tree.root);
    if(maxNode) cout << "Student with max score: " << maxNode->s->name << "(" << maxNode->s->score << ")\n";

    return 0;
}
