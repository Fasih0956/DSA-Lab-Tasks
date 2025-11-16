#include<iostream>
using namespace std;
class MaxHeap{
public:
    int arr[100];
    int size;
    MaxHeap(){
        size= 0;
    }
    void insertKey(int x){
        arr[size]= x;
        int i= size;
        size++;
        while(i!=0 && arr[(i-1)/2] < arr[i]){
            int t= arr[i];
            arr[i]= arr[(i-1)/2];
            arr[(i-1)/2]= t;
            i = (i-1)/2;
        }
    }
    void heapify(int i){
        int l= 2*i+1;
        int r= 2*i+2;
        int largest = i;
        if (l< size && arr[l]> arr[largest]) largest = l;
        if (r< size && arr[r]> arr[largest]) largest = r;
        if (largest != i){
            int t= arr[i];
            arr[i]= arr[largest];
            arr[largest] = t;
            heapify(largest);
        }
    }
    void update_key(int i,int new_val){
        arr[i]= new_val;
        while(i!=0 && arr[(i-1)/2] < arr[i]){
            int t= arr[i];
            arr[i]= arr[(i-1)/2];
            arr[(i-1)/2]= t;
            i = (i-1)/2;
        }
        heapify(i);
    }
    void delete_index(int i){
        arr[i]= arr[size-1];
        size--;
        while(i !=0 && arr[(i-1)/2]< arr[i]){
            int t= arr[i];
            arr[i]= arr[(i-1)/2];
            arr[(i-1)/2]= t;
            i = (i-1)/2;
        }
        heapify(i);
    }
    void printHeap(){
        for (int i= 0; i< size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    MaxHeap h;
    h.insertKey(8);
    h.insertKey(7);
    h.insertKey(6);
    h.insertKey(5);
    h.insertKey(4);

    cout<<"<---Initial Max Heap--->"<<endl;
    h.printHeap();

    h.update_key(2, 10);  //update func
    cout<<"<---After updating--->"<<endl;
    h.printHeap();

    h.delete_index(1); //deletion 
    cout<<"<---After deletion--->"<<endl;
    h.printHeap();

    return 0;
}
