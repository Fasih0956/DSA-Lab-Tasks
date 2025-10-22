#include<iostream>
using namespace std;
int* bubbleSort(int arr[],int s){
    for (int i =0; i<s-1; i++) {
        for (int j =0;j<s-i-1; j++) {
            if (arr[j] > arr[j + 1]) {
                 swap(arr[j], arr[j+1]);
            }
        }
    }
    return arr;
}
bool findDuplicate(int arr[],int s){
     for(int i = 0 ; i < s-1 ; i++){
        if(arr[i]==arr[i+1]){
            return true;
        }
        
    }
    return false;
}
int main(){
    int arr[]={10,16,19,2,89,0,2,5,6};
    int size = sizeof(arr)/sizeof(int);

    // First sorted the array
    bubbleSort(arr , size);

    bool found=findDuplicate(arr , size);

    if(!found){
        cout<<"Array has no duplicates !"<<endl;
    }
    else{
        cout<<"Duplicate Found !"<<endl;
    }
    return 0;
}    


    