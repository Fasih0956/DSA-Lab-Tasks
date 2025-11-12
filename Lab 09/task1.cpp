#include<iostream>
#include<queue>
#include<string>
using namespace std;
class Node{ //Node class to store nodes with its following attributes
    public:
    string name ;
    int roll;
    int height = 1;   //height to calculate balance factor BF = LEFT(HEIGHT)-RIGHT(HEIGHT)
    Node* left;    //left pointer to store left subtrees  ,values < root
    Node* right;   // right pointer to stroe right subtrees ,values > root
    Node(string n , int s){   // constructor for student creation with name and roll no.
        name = n ;
        roll = s;
        left = NULL;
        right = NULL; 
    }
};
int height(Node* node){  //utility function to calculate height of each node after evry insertion to check BF
    if(node == NULL){
        return 0;
    }
    return node->height;
}
void update_height(Node* node){  //function to assist height
    if(node == NULL){
        return;
    }
    node -> height = 1 + max(height(node->left),height(node->right));  //height increases on each recursive call
}
int getbalance(Node* node){  //utility function to get balance factor of nodes at each insertion to check for imbalance 
    if(node==NULL){
        return 0;
    }
    return (height(node->left)-height(node->right));  //imbalanced if BF > 1 || BF < -1
}
Node* rotate_right(Node* y){   // similar to rotate left function with y as parent and x as child
    Node* x = y -> left;
    Node* T2 = x -> right ;

    x -> right = y ;
    y -> left = T2 ;

    update_height(y);
    update_height(x);

    return x;
}
Node* rotate_left(Node* x){  //function to perform left rotation if imabalance node appears
    Node* y = x -> right;   // y is the child of imbalanced x node
    Node* T2 = y -> left ;  // T2 is the pointer node to store any subtree that is at left of y since after balancing y becomes parent and y -> left is lost

    y -> left = x ;  // rotation performed on x now y is parent and x is child
    x-> right = T2 ;

    update_height(x);  //updating height to check for imabalance again
    update_height(y);  //if imbalance persist repeat the process

    return y;  // return new parent balanced node
}
Node* balanceNode(Node* node){
    int balance = getbalance(node);    //call getbalance to check for Balance Factor
    //LL Case
    if(balance > 1 && getbalance(node->left)>=0){
        return rotate_right(node);
    }
    //RR Case
    if(balance < -1 && getbalance(node->right)<=0){
        return rotate_left(node);
    }
    //LR Case
    if(balance > 1 && getbalance(node->left)<0){
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    //RL Case
    if(balance < -1 && getbalance(node->right) > 0){
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;   //balanced
}
Node* insertNode(Node* node, string n , int s){  //insertion function to insert nodes at right places and balance them if imbalanced
    if(node==NULL){
        return new Node(n,s);
    }
    if(s < node->roll){     //left subtree
        node->left=insertNode(node->left,n,s);
    }
    else if(s > node -> roll){
        node->right = insertNode(node->right,n,s);   //right subtree
    }  
    else{
        return node;
    }    
    update_height(node);
    return balanceNode(node);
}
void levelorder(Node* root){   //levelorder traversal or BFS to output final tree
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
        cout<<" "<<curr->name<<"="<<curr->roll<<" ";
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
    }
    cout<<endl;
  }
}
int main(){
    Node* root = NULL;
    root = insertNode(root,"Student 1",10);   //Hardcoded
    root = insertNode(root,"Student 2",20);
    root = insertNode(root,"Student 3",30);
    root = insertNode(root,"Student 4",40);
    root = insertNode(root,"Student 5",50);

    int h = height(root);
    cout<<"<---Height before insertion--->"<<endl;
    cout<<h<<endl;
    cout<<"<---Tree Before Insertion--->"<<endl;
    levelorder(root);
    cout<<endl;

    root = insertNode(root,"New Student",15);   // since it will add to the right of node 10 and the tree is already balanced , it still remains balanced after insertion

    int nh = height(root);
    cout<<"<---Height After insertion--->"<<endl;  //no change in height
    cout<<nh<<endl;
    cout<<"<---Tree After Insertion--->"<<endl;
    levelorder(root);
    cout<<endl;

    return 0;
}