#include<iostream>
#include<queue>
#include<math.h> //used in printTree function
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height = 1;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
int height(Node* node){
    if(node == NULL){
        return 0;
    }
    return node->height ;
}
void update_height(Node* node){
    if (node == NULL){
        return;
    }
    node -> height = 1 + max(height(node->left),height(node->right));
}
int getbalance(Node* node){
    if(node == NULL){
        return 0;
    }
    return (height(node->left)-height(node->right));
}
Node* rotate_right(Node* y){
    Node* x = y -> left;
    Node* T2 = x -> right ;

    x -> right = y;
    y -> left = T2;

    update_height(y);
    update_height(x);

    return x;
}
Node* rotate_left(Node* x){
    Node* y = x -> right ;
    Node* T2 = y -> left;

    y -> left = x;
    x -> right = T2;

    update_height(x);
    update_height(y);

    return y;
}
Node* balanceNode(Node* node){
    int balance = getbalance(node);
    if(balance > 1 && getbalance(node->left)>=0){
        return rotate_right(node);
    }
    if(balance < -1 && getbalance(node->right)<=0){
        return rotate_left(node);
    }
    if(balance > 1 && getbalance(node->left)<0){
        node -> left = rotate_left(node->left);
        return rotate_right(node);
    }
    if(balance < -1 && getbalance(node->right)>0){
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}
Node* insertNode(Node* node , int val){
    if(node == NULL){
        return new Node(val);
    }
    else if(val < node -> data){
        node -> left = insertNode(node->left,val);
    }
    else if(val > node -> data){
        node -> right = insertNode(node->right, val);
    }
    else {
        return node;
    }
    update_height(node);
    return balanceNode(node);
}
void levelorder(Node* root){
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
        for(int i = 0 ; i<curr->height+1 ; i++){
            cout<<" ";
        }
        cout<<curr->data<<" ";
        if(curr->left)q.push(curr->left);
        if(curr->right)q.push(curr->right);
        }
        cout<<endl;
    }
}
void printTree(Node* root) {
    if (!root) return;

    int h = height(root);
    queue<Node*> q;
    q.push(root);

    int level = 0;
    while (!q.empty() && level < h) {
        int size = q.size();
        int spacesBefore = pow(2, h - level) - 1;
        int spacesBetween = pow(2, h - level + 1) - 1;

        for (int i = 0; i < spacesBefore; i++) cout << " ";
        for (int i = 0; i < size; i++) {
            Node* curr = q.front(); 
            q.pop();
            if (curr)
                cout << curr->data;
            else
                cout << " ";
            for (int j = 0; j < spacesBetween; j++) cout << " ";
            if (curr) {
                q.push(curr->left);
                q.push(curr->right);
            } else {
                q.push(NULL);
                q.push(NULL);
            }
        }
        cout<<endl;
        level++;
   }
}
int main(){
    Node* root = NULL ;
    root = insertNode(root,10);
    root = insertNode(root,5);
    root = insertNode(root,15);
    root = insertNode(root,3);
    root = insertNode(root,7);

    cout<<"<---Final Balanced AVL Tree--->"<<endl;
    printTree(root);  //called it for a nicer look can aslo call levelorder(root) , implemented above
    cout<<endl;

    return 0;
}