#include<iostream>
#include<string>
using namespace std;
class Runner {
    public:
    int time ;
    string name ;
    Runner(){
        name = "";
        time = 0 ;
    }
    Runner ( string name , int time) {
        this -> time = time ;
        this -> name = name ;
    }
};
void merge(int start , int end, Runner* arr) {
    int m = ( start + end ) / 2 ;
    int len1 = m - start + 1;
    int len2 = end - m;

    Runner *first = new Runner[len1] ;
    Runner *second = new Runner[len2] ;

    int mainindex = start ;
    for(int i = 0 ; i < len1 ; i++) {
        first[i] = arr[mainindex++] ;
    }
     mainindex = m + 1  ;
    for(int i = 0 ; i < len2 ; i++) {
        second[i] = arr[mainindex++] ;
    }
    int index1 = 0 ;
    int index2 = 0;
    mainindex = start;
    while (index1 < len1 && index2 < len2) {
        if(first[index1].time < second[index2].time) {
            arr[mainindex++] = first[index1++] ;
        }
        else {
            arr[mainindex++] = second[index2++] ;
        }
    }
    while(index1 < len1) {
        arr[mainindex++] = first[index1++] ;
    }
    while(index2 < len2) {
        arr[mainindex++] = second[index2++] ;
    }
    delete[] first ;
    delete[]second ;
}
void solve(int start , int end , Runner* arr) {
    if(start >= end) {
        return ;
    }
    int mid = (start + end ) / 2 ;

    solve(start , mid  , arr ) ;
    solve(mid + 1 , end , arr) ;
    merge(start , end , arr) ;

}
int main() {
    int time ;
    string name ;
    Runner* arr = new Runner[10];
    for ( int i = 0 ; i < 10 ; i++) {
        cout<<"Enter name and finish time for runner "<<i+1<<": ";
        cin>>arr[i].name>>arr[i].time ;
    }
    solve(0 , 9 , arr) ;
    cout<<endl;
    cout<<"Top 5 Fastest runners:"<<endl;
    for(int i = 0 ; i < 5 ; i++) {
        cout<<i+1<<". "<< arr[i].name<<" - "<<arr[i].time<<" seconds";
        cout<<endl;
    }
    delete []arr ;
    cout<<endl ;
    return 0 ;
}
