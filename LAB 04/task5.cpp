// done using bubblesort because in best case its time complexity is O(n) and we were not asked to implement certain algorithm 
#include<iostream>
using namespace std;
int main(){
    int arr[6]={2022,2023,2024,2022,2023,2024};
    for (int i =0; i<5; i++) {
        for (int j =0;j<6-i-1; j++) {
            if (arr[j] > arr[j + 1]) {
                 swap(arr[j], arr[j+1]);
            }
        }
    }
    cout << "<---Sorted Array---> "<<endl;
    for (int i =0; i<=5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}