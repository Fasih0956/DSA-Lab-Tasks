#include<iostream>
using namespace std;
int main(){
    int arr[10];   // since only 10 elements are needed
    cout<< "Enter 10 elements: "<<endl;
    for (int i=0; i<10; i++){
        cin>>arr[i];
    }
    for (int i =0; i<4; i++) {  // since four elements needed we run loop 4 times
        int min=i;
        for (int j =i+1;j<10; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    cout << "<---Four minimum elements are---> "<<endl;
    for (int i =0; i<4; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
