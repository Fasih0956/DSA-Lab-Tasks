#include <iostream>
using namespace std;

int recursiveArraySum(int* arr[], int sizes[], int dim){
    if (dim == 1){
        int sum = 0;
        for (int i = 0; i < sizes[0]; i++){
            sum += ((int*)arr)[i];
        }
        return sum;
    }
    int sum= 0;
    for (int i = 0; i < sizes[0]; i++){
        sum += recursiveArraySum((int**)arr[i], sizes + 1, dim - 1);
    }
    return sum;
}
int main(){
    int* row1= new int[3]{1, 2, 3};
    int* row2= new int[3]{4, 5, 6};
    
    int** arr2d= new int*[2]{row1, row2};
    int sizes[]= {2, 3};
    
    int sum = recursiveArraySum(arr2d, sizes, 2);
    cout<<"Sum Of Jgged Array is: "<<sum<<endl;
    
    delete[] row1;
    delete[] row2;
    delete[] arr2d;
    
    return 0;
}