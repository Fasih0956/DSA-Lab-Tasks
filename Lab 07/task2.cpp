#include<iostream>
#include<vector>
using namespace std;
int main() {
    int arr[] = { 36, 987, 654, 2, 20,99 ,456, 957, 555 , 420 , 66, 3};
    int n = sizeof(arr) / sizeof(int) ;
    vector<int> bin [10] ;
    int max = arr[0] ;
    for  ( int i = 0 ; i < n ; i++) {
        if( arr[i] > max ) {
            max = arr[i] ;
        }
    }
    for ( int i = 1 ; max / i > 0 ; i = i *10) {
        for( int j = 0 ; j < n ; j ++) {
            int digit =  ( arr[j] / i ) % 10 ;
            bin[digit].push_back(arr[j]) ;
        }
    int k = 0 ;
    for(int d = 0 ;d < 10 ; d++) {
        for(int val : bin[d]) {
            arr[k++] = val ;
        }
        bin[d].clear() ;
    }
}
    for(int x = 0 ; x < n ; x++) {
        cout<<arr[x]<<" ";
    }
    cout<<endl ;
    return 0 ;
}