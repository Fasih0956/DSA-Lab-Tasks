//AVL Tree is a modification of Binary Serach Tree where it reduces the time complexity to O(logh) and h is height . In some cases of BST it becomes skewed and time complexity
//jumps to O(n) , thus AVL tree is better in such cases as it is self balancing binary search tree.
#include<iostream>
#include<queue>  //for BFS
using namespace std;
class Node {   //Node class to store nodes with its following attributes
    public:
    int data;
    Node* left ;   //left pointer to store left subtrees  ,values < root
    Node* right;  // right pointer to stroe right subtrees ,values > root
    int height = 1;  //height to calculate balance factor BF = LEFT(HEIGHT)-RIGHT(HEIGHT)
    Node(int val){    // constructor for node creation
        data = val ;
        left = NULL;
        right = NULL ;
    }
};
int height(Node* node){   //utility function to calculate height of each node after evry insertion to check BF
    if(node == NULL){
        return 0;
    }
    return node->height ;
}
void update_height(Node* node){   //function to assist height
    if(node == NULL){
        return;
    }
    node -> height =  1 + max(height(node -> left),height(node->right));  //height increases on each recursive call
}
int getbalance(Node* node){  //utility function to get balance factor of nodes at each insertion to check for imbalance 
    if(node== NULL){
        return 0;
    }
    return (height(node->left)-height(node->right));   //imbalanced if BF > 1 || BF < -1
}
Node* rotate_left(Node* x){  //function to perform left rotation if imabalance node appears
    Node* y = x -> right ;  // y is the child of imbalanced x node
    Node* T2 = y -> left ;  // T2 is the pointer node to store any subtree that is at left of y since after balancing y becomes parent and y -> left is lost

    y -> left = x ;    // rotation performed on x now y is parent and x is child
    x -> right = T2 ; 
    update_height(x);   //updating height to check for imabalance again
    update_height(y);   //if imbalance persist repeat the process

    return y;     // return new parent balanced node
}
Node* rotate_right(Node* y){    // similar to rotate left function with y as parent and x as child
    Node* x = y -> left ;
    Node* T2 = x -> right ;

    x -> right = y ;
    y -> left = T2 ;

    update_height(y);
    update_height(x);

    return x;   // after right rotation return new balanced node 
}
Node* balanceNode(Node* node){
    int balance = getbalance(node);   //call getbalance to check for Balance Factor
    // LL case
    if(balance>1 && getbalance(node->left)>=0){
        return rotate_right(node);
    }
    //RR case
    if(balance < -1 && getbalance(node->right) <=0){
        return rotate_left(node);
    }
    // Left Right Case
    if(balance > 1 && getbalance(node->left) < 0){
        node -> left = rotate_left(node->left);
        return rotate_right(node); 
    }
    //Right Left Case
    if(balance < -1 && getbalance(node->right) > 0){
        node -> right = rotate_right(node->right);
        return rotate_left(node);
    }    
    return node;
}
Node* insertNode(Node* node, int data) {  //insertion function to insert nodes at right places and balance them if imbalanced
    if(node == NULL){
        return new Node(data);
    }
    if(data < node->data){     //left subtree
        node->left=insertNode(node->left,data);
    }
    else if(data > node -> data){
        node->right = insertNode(node->right,data);   //right subtree
    }  
    else {
        return node;
    }    
    update_height(node);
    return balanceNode(node);
}
void levelorder(Node* root){    //level order traversal or BFS to output final tree
    if(root == NULL){
        return ;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
        Node* curr = q.front();
        q.pop();
        cout<<" "<<curr->data<<" ";
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
        }
        cout<<endl;
    }
}
int main(){
    Node* rootA = NULL; //rootA for A AVL Tree
    Node * rootB = NULL;//rootB for B AVL Tree
    rootA = insertNode(rootA,10);  //Hardcoded
    rootA = insertNode(rootA,6);
    rootA = insertNode(rootA,4);
    rootA = insertNode(rootA,8);
    cout<<"<---BFS TRAVERSAL OF AVL TREE (A)--->"<<endl;
    levelorder(rootA);  //Tree A Traversal
    cout<<endl;    

    rootB = insertNode(rootB,10);   //Hardcoded
    rootB = insertNode(rootB,16);
    rootB = insertNode(rootB,12);
    rootB = insertNode(rootB,18);
    cout<<"<---BFS TRAVERSAL OF AVL TREE (B)--->"<<endl;
    levelorder(rootB);  //Tree B Traversal
    cout<<endl;
    return 0;   //end
}
