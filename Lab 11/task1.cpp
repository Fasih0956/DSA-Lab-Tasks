#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    string key;
    string value;
    Node* next;
    Node(string k, string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};
class HashTable{
private:
    int buckets;
    Node** table;
public:
    HashTable(int n = 10){
        buckets = n;
        table = new Node*[buckets];
        for (int i = 0; i < buckets; i++)
            table[i] = nullptr;
    }
    int hashFunction(const string& s) {
        int sum = 0;
        for (char c : s)
            sum += int(c);
        return sum % buckets;
    }
    void insert(const string& key, const string& value) {
        int idx = hashFunction(key);
        Node* curr = table[idx];
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value = value; 
                return;
            }
            curr = curr->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = table[idx];
        table[idx] = newNode;
    }
    void print() {
        for (int i = 0; i < buckets; i++) {
            Node* curr = table[i];
            while (curr != nullptr) {
                cout<<curr->key<<" : " <<curr->value<<endl;
                curr = curr->next;
            }
        }
    }
};
int main(){
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");  //value of A is overwritten

    myhash.print();
    return 0;
}
