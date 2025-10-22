#include<iostream>
#include<cstring>
using namespace std;
class Exam{
    char* name;
    char* date;
    int score;
    public:
    Exam(){
        name=new char[50];               //default constructor
        date=new char[50];
        score=0;
    }
    Exam(char* n,char* d,int s){
        name=new char[strlen(n)+1];
        strcpy(name,n);
        date=new char[strlen(d)+1];
        strcpy(date,d);                    //parametrized constructor
        score=s;
    }
    void input(){
        cout<<"Enter Student Name: ";
        cin>>name;
        cout<<endl;
        cout<<"Enter Date of Exam: ";     // DD/MM/YY
        cin>>date;       
        cout<<endl;
        cout<<"Enter Student Score: ";
        cin>>score;
        cout<<endl;

    }
    void display(){
        cout<<"Name:"<< name<<endl;
        cout<<"Date:"<< date<<endl;
        cout<<"Score:"<< score<<endl;
    }
    ~Exam(){
        cout<<"Freeing memory for date and name: "<<endl;
        delete[]name;
        delete[]date;
    }
};
int main(){

    Exam student1;
    student1.input();
    Exam student2=student1;              // shallow copy 
    student2.input();

    student1.display();
    student2.display();
    
    return 0;
}