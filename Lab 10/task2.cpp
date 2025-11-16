#include<iostream>
using namespace std;
class Heap{
public:
    int arr[100];
    int n;
    Heap(){
        n = 0;
    }
    void setInput(int a[], int size){
        n= size;
        for(int i = 0; i < n; i++) arr[i] = a[i];
    }
    bool isHeap(){
        for (int i= 0; i<= (n-2)/2; i++) {
            int l= 2*i + 1;
            int r= 2*i + 2;
            if(l < n && arr[i]< arr[l]) return false;
            if(r < n && arr[i]< arr[r]) return false;
        }
        return true;
    }
    void heapify(int i, int size){
        int largest= i;
        int l= 2*i + 1;
        int r= 2*i + 2;
        if (l< size && arr[l]> arr[largest]) largest = l;
        if (r< size && arr[r]> arr[largest]) largest = r;
        if (largest != i){
            int t= arr[i];
            arr[i]= arr[largest];
            arr[largest]= t;
            heapify(largest, size);
        }
    }
    void buildMaxHeap(){
        for (int i= n/2 - 1; i>= 0; i--)
            heapify(i, n);
    }
    void sortAscending(){
        buildMaxHeap();
        for (int i= n - 1; i>= 1; i--) {
            int t= arr[0];
            arr[0]= arr[i];
            arr[i]= t;
            heapify(0, i);
        }
    }
    void print(){
        for (int i= 0; i < n; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    int a[5]={8,7,6,5,4};  //given tree
    Heap h;
    h.setInput(a, 5);

    if (h.isHeap()) cout<<"YES"<<endl;   //check func
    else cout << "NO"<<endl;

    cout<<"<---Before Sort--->"<<endl;
    h.print();
    
    h.sortAscending();  //sort func
    cout<<"<---After Sort--->"<<endl;
    h.print();

    return 0;
}
