#include<iostream>
using namespace std;
class Pair{
    public:
    int a, b;
};
class Node{
    public:
    Pair p;
    Node* next;
};
const int TABLE_SIZE = 1000;  //size can be increased

Node* hashTable[TABLE_SIZE];
int myHash(int sum){
    if (sum< 0) sum = -sum;
    return sum % TABLE_SIZE;
}
void insertPair(int sum, int a, int b){
    int index = myHash(sum);

    Node* newNode = new Node;
    newNode->p = {a, b};
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
}
bool checkAndInsert(int a, int b){
    int sum = a + b;
    int index = myHash(sum);
    Node* temp = hashTable[index];

    while(temp != nullptr){
        int x = temp->p.a;
        int y = temp->p.b;

        if (x != a && x != b && y != a && y != b){
            cout<<"("<<x<<", "<<y<<") and ("<<a<<", "<<b<<")\n";
            return true;
        }
        temp = temp->next;
    }
    insertPair(sum, a, b);
    return false;
}
bool findPairs(int arr[], int n){
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = nullptr;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if(checkAndInsert(arr[i], arr[j])){
                return true;
            }
        }
    }
    cout<<"No pairs found"<<endl;
    return false;
}
int main(){
    int arr1[7] = {3,4,7,1,2,9,8};
    findPairs(arr1, 7);

    int arr2[6] = {3,4,7,1,12,9};
    findPairs(arr2, 6);

    int arr3[7] = {65,30,7,90,1,9,8};
    findPairs(arr3, 7);
    return 0;
}
