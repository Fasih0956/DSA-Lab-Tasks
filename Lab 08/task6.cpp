#include<iostream>
using namespace std;
class Product {
    public:
    int id;
    int quantity;
    Product(int pid, int qty) : id(pid), quantity(qty) {}
};
class Node {
    public:
    Product* product;
    Node* left;
    Node* right;
    Node(Product* p) : product(p), left(nullptr), right(nullptr) {}
};
class InventoryBST {
public:
    Node* root;
    InventoryBST() { root = nullptr; }

    Node* insert(Node* node, int id, int quantity) {
        if (!node) return new Node(new Product(id, quantity));
        if (id < node->product->id) node->left = insert(node->left, id, quantity);
        else if (id > node->product->id) node->right = insert(node->right, id, quantity);
        else node->product->quantity = quantity;
        return node;
    }
    Node* search(Node* node, int id) {
        if (!node) return nullptr;
        if (node->product->id == id) return node;
        if (id < node->product->id) return search(node->left, id);
        return search(node->right, id);
    }
    void findMaxQuantity(Node* node, int &maxQty, int &maxID) {
        if (!node) return;
        if (node->product->quantity > maxQty) {
            maxQty = node->product->quantity;
            maxID = node->product->id;
        }
        findMaxQuantity(node->left, maxQty, maxID);
        findMaxQuantity(node->right, maxQty, maxID);
    }
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << "ID: " << node->product->id << ", Qty: " << node->product->quantity << endl;
        inorder(node->right);
    }
};
int main(){
    InventoryBST inventory;
    inventory.root = inventory.insert(inventory.root, 101, 50);
    inventory.root = inventory.insert(inventory.root, 102, 30);
    inventory.root = inventory.insert(inventory.root, 103, 70);
    inventory.root = inventory.insert(inventory.root, 104, 40);

    cout << "Inventory List:"<<endl;
    inventory.inorder(inventory.root);

    inventory.root = inventory.insert(inventory.root, 102, 60);
    cout << "After updating quantity of ID 102:"<<endl;
    inventory.inorder(inventory.root);

    int searchID = 103;
    Node* found = inventory.search(inventory.root, searchID);
    if (found) cout << "Product ID " << searchID << " found with quantity: " << found->product->quantity << endl;
    else cout << "\nProduct ID " << searchID << " not found."<<endl;

    int maxQty = -1; // least initialization
    int maxID = -1; //least possible to avoid crashes
    inventory.findMaxQuantity(inventory.root, maxQty, maxID);
    cout << "Product with max quantity: ID " << maxID << ", Qty " << maxQty <<endl;

    return 0;
}
