#include<iostream>
using namespace std;
class ConvertHeap{
public:
    int h[100];
    int n;
    ConvertHeap(int arr[],int size){
        n= size;
        for(int i = 0; i < n; i++) h[i] = arr[i];
    }
    void heapifyDownMax(int i){
        int largest= i;
        int l= 2*i + 1;
        int r= 2*i + 2;
        if(l< n && h[l]> h[largest]) largest = l;
        if(r< n && h[r]> h[largest]) largest = r;
        if(largest != i){
            int t= h[i]; h[i] = h[largest]; h[largest] = t;
            heapifyDownMax(largest);
        }
    }
    void convert(){
        for (int i= n/2 - 1; i>= 0; i--)
            heapifyDownMax(i);
    }
    void print(){
        for (int i= 0; i< n; i++){
            cout<<h[i]<<" ";
        }
    }
};
int main(){
    int arr[10]= {3,5,9,6,8,20,10,12,18,9};
    ConvertHeap hp(arr, 10);

    hp.convert();  //convert func
    hp.print();
}
