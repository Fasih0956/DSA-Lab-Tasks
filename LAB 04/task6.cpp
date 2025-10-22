#include<iostream>
using namespace std;
void printArray(int arr[], int s){
    for(int i = 0 ; i< s ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int* SortArray( int arr[], int s){
    int temp;
    for(int i = 0; i < s-1  ; i++){
        for(int j = i +1 ; j < s ; j++ ){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i]= arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}
int BinarySearch(int arr[],int s ,int value) {
    int left = 0;
    int right = s-1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        else if (arr[mid] < value) {
                   left = mid + 1;
        }
        else {
            right = mid - 1;
        }
}
        return -1;
}
int main(){
    int array[]={10,20,30,40,50,60,56,70,80,90,100};   //since 56 is last two digits of my roll number
    int size = sizeof(array)/sizeof(int);
    int value;

    cout<<"<---Array elements before sorting--->"<<endl;
    printArray(array , size);
    cout<<endl;

    cout<<"<---Array elements after sorting--->"<<endl;
    SortArray(array , size);
    printArray(array , size);
    cout<<endl;

    cout<<"Enter the last two digits of your roll number: ";
    cin>>value;
    cout<<endl;

    int found = BinarySearch(array , size , value );

    if(found==-1){
        cout<<"Entered value Not found!"<<endl;
     }
     else{
        cout<<value<<" found at index "<<found<<endl;
     }
     cout<<endl;
     return 0;
}