#include<iostream>
#include<string>
using namespace std;
class Product {
    public:
    string name ;
    float price ;
    string desc ;
    bool availability ;
    Product (string n , float p , string d , bool a) {
        name = n ;
        price = p ;
        desc = d ;
        availability = a ;
    }
};
int findpivot(int s , int e , Product arr[]) {
    float pivot = arr[s].price ;
    int count = 0 ;
    for (int k = s+1 ; k <= e ; k++) {
        if (arr[k].price <= pivot) {
            count++ ;
        }
    }
    int pivotindex = s + count ;
    swap (arr[s] , arr[pivotindex]) ;
    int i = s ;
    int j = e ;
    while ( i < pivotindex && j > pivotindex ) {
        while ( arr[i].price < pivot) {
            i++ ;
        }
        while (arr[j].price > pivot ){
            j-- ;
        }
        if ( i < pivotindex && j > pivotindex  ){
            swap (arr[i++] , arr[j--]) ;
        }
    }
    return pivotindex ;
}
void sortquick(int start , int end , Product arr[]) {
    if ( start >= end ) {
        return ;
    }
    int pivot = findpivot ( start , end , arr) ;
    sortquick ( start , pivot - 1 , arr );
    sortquick(pivot + 1 , end , arr ) ;
}

int main() {
    Product product1("Product 1",10.99,"This is Product 1",true) ;
    Product product2("Product 2",5.99,"This is Product 1",false) ;
    Product product3("Product 3",2.99,"This is Product 1",true) ;

    Product products[] = {product1 , product2 , product3} ;
    int n = 3 ;//since 3 objects used

    sortquick( 0 , n - 1 , products) ;

    cout<<"Products sorted by price:"<<endl;
    for (int i = 0 ; i < n ; i++){
        cout<<products[i].name<<" - $"<<products[i].price<<endl;
    }
    return 0 ;
}
