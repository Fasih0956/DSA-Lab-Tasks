#include <iostream>
using namespace std;
int main(){
    // Creating and initializing array
    bool arr[5][5]={
        {false,true,false,true,true},
        {true,false,true,false,true},
        {false,true,false,false,false},
        {true,false,false,false,true},
        {true,true,false,true,false}
    };
    int a,b;
    cout<<"Enter two persons to check common friends (0-4): ";
    cin>>a>>b;
    bool found=false;  //to avoid undesired output

    for (int k=0; k<5; k++) {
            if((arr[a][k]&&arr[b][k])==true){
                cout<<a<<" and "<<b<<" are both friends with "<<k<<endl;
                found=true;
            }
        }

    if (!found) {
        cout<<a<< " and "<<b<<" have no common friends."<<endl;
    }
    cout << endl;
    return 0;
}
