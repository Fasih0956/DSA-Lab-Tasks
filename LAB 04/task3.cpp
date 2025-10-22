#include<iostream>
#include<string>
using namespace std;
int main(){
    string arr[]={"banana","apple","cherry","date","grape"};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0 ; i< size -1 ; i++){
        for(int j = 0 ; j< size - i -1 ; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"<---Sorted Array--->"<<endl;
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}