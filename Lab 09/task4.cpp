#include<iostream>
#include<queue>
#include<math.h>
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
    if ( node == NULL){
        return 0;
    }
    return node->height;
}
void update_height(Node* node){
    if(node == NULL){
        return ;
    }
    node -> height = 1 + (max(height(node->left),height(node->right)));
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

    x-> right = y;
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
    if(balance > 1 && getbalance(node->left) >=0 ){
        return rotate_right(node);
    }
    if(balance < 1 && getbalance(node->right)<=0){
        return rotate_left(node);
    }
    if(balance > 1 && getbalance(node->left)< 0){
        node -> left = rotate_left(node->left);
        return rotate_right(node);
    }
    if(balance< 1 && getbalance(node->right)>0){
        node -> right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}
Node* insertNode(Node* node , int val){
    if(node == NULL){
        return new Node(val);
    }
    else if(val < node->data){
        node -> left = insertNode(node->left,val);
    }
    else if(val > node -> data){
        node -> right = insertNode(node->right,val);
    }
    else {
        return node;
    }
    update_height(node);
    return balanceNode(node);
}
void printTree(Node* root){
    if(!root) return;
    int h = height(root);
    queue<Node*> q;
    q.push(root);
    int l = 0;
    while(!q.empty() && l < h){
        int size = q.size();
        int sbf = pow(2,h-l)-1;
        int sbt = pow(2,h-l+1)-1;
        for(int i=0 ; i< sbf ; i++)cout<<" ";
        for(int i=0 ; i< size ; i++){
            Node* curr = q.front();
            q.pop();
            if(curr){
                cout<<curr->data;
            }else {
                cout<<" ";
            }
            for(int j =0 ; j < sbt ; j++)cout<<" ";
            if(curr){
                q.push(curr->left);
                q.push(curr->right);
            }else{
                q.push(NULL);
                q.push(NULL);
            }
        }
        cout<<endl;
        l++;
    }
}
void kthsmallest(Node* root , int k , int &count , int &key){
    if(!root)return ;
    kthsmallest(root->left,k,count,key);
    count++;
    if(count == k){
        key = root->data;
    }
    kthsmallest(root->right,k,count,key);
}
void kthlargest(Node* root , int k , int &count , int &key){
    if(!root)return ;
    kthlargest(root->right,k,count,key);
    count++;
    if(count == k){
        key = root->data;
    }
    kthlargest(root->left,k,count,key);
}
int main(){
    Node* root = NULL;
    root = insertNode(root,50);
    root = insertNode(root,20);
    root = insertNode(root,70);
    root = insertNode(root,10);
    root = insertNode(root,30);
    root = insertNode(root,60);
    root = insertNode(root,80);
    root = insertNode(root,25);
    root = insertNode(root,40);
    root = insertNode(root,35);

    cout<<"<---BFS Traversal of AVL Tree--->"<<endl;
    printTree(root);
    cout<<endl;

    int k;
    cout<<"Enter kth value to find smallest and laregst element in tree: ";
    cin>>k;
    cout<<endl;

    int count = 0;
    int smallest = -1 ;
    int largest = -1 ; 

    cout<<"<---Kth Smallest Element in tree--->"<<endl;
    kthsmallest(root,k,count,smallest);
    cout<<smallest<<endl;
    cout<<endl;

    count = 0;
    cout<<"<---Kth Largest Element in tree--->"<<endl;
    kthlargest(root,k,count,largest);
    cout<<largest<<endl;
    cout<<endl;

    cout<<"<---Height of Left subtree--->"<<endl;
    cout<<height(root->left)<<endl;
    cout<<endl;

    cout<<"<---Height of Right subtree--->"<<endl;
    cout<<height(root->right)<<endl;
    cout<<endl;

    return 0;
}