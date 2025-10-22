#include<iostream>
using namespace std;
int main(){
    int rows,cols;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    cout<<"Enter the number of columns: ";
    cin>>cols;
    // Dynamic 2D Matrix creation
    int **arr=new int*[rows];
    for(int i=0;i<rows;i++){
        arr[i]=new int [cols];
    }
    //Taking Input from user
    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"Enter element for position ("<<i+1<<","<<j+1<<"): ";
            cin>>arr[i][j];
        }
    }
    //Displaying the matrix
    cout<<"The Original 2D matrix is: "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //Resizing the matrix
    int newRows,newCols;
    cout<<"\nEnter the new number of rows: ";
    cin>>newRows;   
    cout<<"Enter the new number of columns: ";
    cin>>newCols;
    int **newArr=new int*[newRows];
    for(int i=0;i<newRows;i++){
        newArr[i]=new int [newCols];
    }
    //if size is smaller
    for(int i=0;i<min(rows,newRows);i++){
        for(int j=0;j<min(cols,newCols);j++){
            newArr[i][j]=arr[i][j];
        }
    }
    //if size is larger
    for(int i=rows;i<newRows;i++){
        for (int j=cols;j<newCols;j++){
            cout<<"Enter new element for position ("<<i+1<<","<<j+1<<"): ";
            cin>>newArr[i][j];
        }
    }
    // Deallocating old array memory
    for(int i=0;i<rows;i++) {
        delete[] arr[i];
    }
    delete[] arr;
    // Update arr
    arr = newArr;
    rows = newRows;     
    cols = newCols;
    // Displaying the resized matrix
    cout<<"The Resized 2D matrix is: "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    //Transpose of the resized Mtrix
    cout<<"The Transpose of the Resized 2D matrix is: "<<endl;
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    //Adding 2 to odd entries
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j]%2!=0){
                arr[i][j]+=2;
            }
        }
    }
    // Displaying the matrix after adding 2 to odd entries
    cout<<"The matrix after adding 2 to odd entries is: "<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // Deallocating new array memory
    for(int i=0;i<rows;i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}