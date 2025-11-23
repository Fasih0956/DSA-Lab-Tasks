#include<iostream>
#include<string>
#include<list>
using namespace std;
class Hash{
private:
    static const int TABLE_SIZE = 100;
    list<pair<string, string>> table[TABLE_SIZE];

    int hashFunction(const string& key){
        int sum = 0;
        for (char c : key)
            sum += int(c);
        return sum % TABLE_SIZE;
    }
public:
    void insert(const string& key, const string& value){
        int index = hashFunction(key);
        for(auto& p : table[index]){
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }
    void search(const string& key){
        int index = hashFunction(key);
        for(auto& p : table[index]){
            if(p.first == key){
                cout<<"Key: "<<key<<" | Value: "<<p.second<<endl;
                return;
            }
        }
        cout<<"Error: Key '"<<key<<"' not found!"<<endl;
    }
    void removeKey(const string& key){
        int index = hashFunction(key);

        for(auto it = table[index].begin(); it != table[index].end(); ++it){
            if(it->first == key){
                table[index].erase(it);
                cout<<"Key '"<<key<<"' deleted successfully!"<<endl;
                return;
            }
        }
        cout<<"Error: Key '"<<key<<"' not found!"<<endl;
    }
    void display(){
        for(int i= 0; i< TABLE_SIZE; i++){
            if (!table[i].empty()){
                cout<<"Index "<<i<<": ";
                for (auto& p : table[i]){
                    cout<<"("<<p.first<<", "<<p.second<<") ";
                }
                cout<<endl;
            }
        }
    }
};
int main(){
    Hash h;
    h.insert("Fasih", "24K-0956");   //inserting
    h.insert("Saad", "24K-0851");
    h.insert("Habib", "24K-0604");

    h.search("Fasih");  //searching

    h.removeKey("Habib");   //deleting

    h.display();  //displaying
    return 0;
}
