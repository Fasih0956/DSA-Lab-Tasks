#include<iostream>
using namespace std;
class MaxHeap{
public:
    int h[100];
    int n;
    MaxHeap(int arr[], int size){
        n= size;
        for(int i = 0; i < n; i++) h[i] = arr[i];
        build();
    }
    void heapifyDown(int i){
        int largest= i;
        int l= 2*i + 1;
        int r= 2*i + 2;
        if (l< n && h[l]> h[largest]) largest = l;
        if (r< n && h[r]> h[largest]) largest = r;
        if (largest != i){
            int t= h[i]; h[i] = h[largest]; h[largest] = t;
            heapifyDown(largest);
        }
    }
    void build() {
        for (int i = n/2 - 1; i >= 0; i--) heapifyDown(i);
    }
    int extractMax(){
        int root = h[0];
        h[0] = h[n-1];
        n--;
        heapifyDown(0);
        return root;
    }
    int kthLargest(int k){
        for(int i= 1; i< k; i++) extractMax();
        return h[0];
    }
};
int main() {
    int arr1[7]= {1,23,12,9,30,2,50};   //first case
    MaxHeap hp1(arr1, 7);
    int k1= 3;
    cout<<hp1.kthLargest(k1);  //passing k1 and k2 because redeclaration not allowed
    cout<<endl;

    int arr2[5]= {12,3,5,7,19};   //second case
    MaxHeap hp2(arr2, 5);
    int k2= 2;
    cout<<hp2.kthLargest(k2);

    return 0;
}
