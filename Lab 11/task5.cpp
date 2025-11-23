#include<iostream>
#include<string>
using namespace std;
class StudentHashTable{
private:
    struct Student{
        int roll;
        string name;
        bool occupied;
        bool deleted;
    };
    Student table[15];

    int hashFunction(int roll){
        return roll % 15;
    }
public:
    StudentHashTable(){
        for (int i = 0; i < 15; i++) {
            table[i].occupied = false;
            table[i].deleted = false;
        }
    }
    void InsertRecord(int roll, string name){
        int index = hashFunction(roll);
        int attempt = 0;
        while(attempt < 15){
            int newIndex = (index + attempt * attempt) % 15;   //quad probing
            if (!table[newIndex].occupied || table[newIndex].deleted){
                table[newIndex].roll = roll;
                table[newIndex].name = name;
                table[newIndex].occupied = true;
                table[newIndex].deleted = false;

                return;
            }
            attempt++;
        }
        cout<<"Hash Table is full! Cannot insert."<<endl;
    }
    void SearchRecord(int roll){
        int index = hashFunction(roll);
        int attempt = 0;
        while(attempt< 15) {
            int newIndex = (index + attempt * attempt) % 15;
            if (table[newIndex].occupied && !table[newIndex].deleted &&
                table[newIndex].roll == roll){
                cout<<"Record found: "<<table[newIndex].name<<endl;
                return;
            }
            if(!table[newIndex].occupied){
                break;
            }
            attempt++;
        }
        cout<<"Record not found"<<endl;
    }
};
int main(){
    StudentHashTable ht;
    ht.InsertRecord(20, "Fasih");  //insertion
    ht.InsertRecord(35, "Saad");
    ht.InsertRecord(50, "Habib");
    ht.InsertRecord(65, "Ali");

    ht.SearchRecord(35);   //found
    ht.SearchRecord(20);   //found
    ht.SearchRecord(99);   //Not found
    return 0;
}
