#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
int countNodes(Node* node) {
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}
void findMedianUtil(Node* node, int &count, int n, int &prev, double &median) {
    if (!node) return;
    findMedianUtil(node->left, count, n, prev, median);
    count++;
    if (n % 2 != 0 && count == (n + 1) / 2) median = node->data;
    else if (n % 2 == 0) {
        if (count == n / 2) prev = node->data;
        else if (count == n / 2 + 1) median = (prev + node->data) / 2.0;
    }
    findMedianUtil(node->right, count, n, prev, median);
}
double findMedian(Node* root) {
    int n = countNodes(root);
    int count = 0, prev = 0;
    double median = 0;
    findMedianUtil(root, count, n, prev, median);
    return median;
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    cout << "Median of BST: " << findMedian(root) <<endl;
    return 0;
}
