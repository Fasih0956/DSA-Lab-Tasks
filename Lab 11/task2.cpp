#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    string key;
    string value;
    Node* next;
    Node(string k, string v){
        key = k;
        value = v;
        next = nullptr;
    }
};
class Dictionary{
private:
    Node** table; 
    int buckets;  
public:
    Dictionary(){
        buckets = 100;
        table = new Node*[buckets];
        for (int i= 0; i< buckets; i++)
            table[i] = nullptr;
    }
    int hashFunction(const string& s){
        int sum = 0;
        for (char c : s)
            sum += int(c);
        return sum % 100;
    }
    void Add_Record(const string& key, const string& value){
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
    void Word_Search(const string& key){
        int idx = hashFunction(key);
        Node* curr = table[idx];
        while(curr != nullptr){
            if(curr->key == key){
                cout<<"search key "<<key<<": "<<curr->value<<endl;
                return;
            }
            curr = curr->next;
        }
        cout<<"Error: key "<<key<<" not found!"<<endl;
    }
    void Delete_Record(const string& key){
        int idx = hashFunction(key);
        Node* curr = table[idx];
        Node* prev = nullptr;
        while(curr != nullptr){
            if(curr->key == key){
                if(prev == nullptr)
                    table[idx] = curr->next;
                else
                    prev->next = curr->next;

                delete curr;
                cout<<"key "<<key<<" deleted successfully !"<<endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout<<"Error: key "<<key<<" not found!"<<endl;
    }
    void Print_Dictionary(){
        for (int i = 0; i < buckets; i++){
            Node* curr = table[i];
            if (curr != nullptr){
                cout<<"index "<<i<<": ";
                while(curr != nullptr){
                    cout<<"("<<curr->key<<", "<<curr->value<<") ";
                    curr = curr->next;
                }
                cout << endl;
            }
        }
    }
};
int main(){
    Dictionary dict;
    dict.Add_Record("AB", "FASTNU");
    dict.Add_Record("CD", "CS");
    dict.Add_Record("EF", "AI");

    dict.Word_Search("AB");  //searching

    dict.Delete_Record("EF");   //deleting

    dict.Print_Dictionary();   //printing
    return 0;
}
