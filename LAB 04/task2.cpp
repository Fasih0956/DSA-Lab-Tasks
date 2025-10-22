#include <iostream>
using namespace std;
void insertionSort(int arr[], int s){
    for (int i=1; i<s; i++) {
        int value = arr[i];
        int j=i -1;
        while (j >=0 && arr[j]> value) {
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1] = value;
    }
}
int main(){
    int arr[] = {20,12,15,2,10,1,13,9,5};
    int size = sizeof(arr)/sizeof(int);

    // First sort 
    insertionSort(arr, size);

    int max= arr[size- 1];
    for(int i =size- 1; i > size / 2; i--){
        arr[i]= arr[i - 1];
    }
    arr[size/ 2]= max;

    cout<< "<---Sorted array--->"<<endl;
    for(int i =0; i< size; i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;
    return 0;
}
