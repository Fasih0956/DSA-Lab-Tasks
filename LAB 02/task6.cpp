#include<iostream>
#include<string>
using namespace std;
int main(){
    //Jagged Array with Row initialization
    const int rows = 5;
    string **seats=new string*[rows];
    int *size=new int[rows];
    for(int i=0;i<rows;i++){
        cout<<"Enter number of seats in row "<<i+1<<": ";
        cin>>size[i];
        seats[i]=new string[size[i]];
    }
    cout<<endl;
    cin.ignore();
    //Input Attendees
    for(int i=0;i<rows;i++){
        cout<<"Enter names of attendees in row "<<i+1<<": "<<endl;
        for(int j=0;j<size[i];j++){
            cout<<"Seat "<<j+1<<": ";
            getline(cin,seats[i][j]); // to take string input with spaces
        }
        cout<<endl;
    }
    cout<<endl;
    //Display Attendees
    cout<<"<---Displaying Attendees---> "<<endl;
    for(int i=0;i<rows;i++){
        cout<<"Attendees in row "<<i+1<<": "<<endl;
        for(int j=0;j<size[i];j++){
            cout<<"Seat "<<j+1<<": "<<seats[i][j]<<endl;
        }
        cout<<endl;
    }
    //Free memory
    for(int i=0;i<rows;i++){    
        delete[] seats[i];
    }   
    delete [] seats;
    delete[] size;
    return 0;
}