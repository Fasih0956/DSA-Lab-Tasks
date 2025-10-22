#include<iostream>
#include<string>
using namespace std;
int main(){
    const int dept=4;
    int courses[dept]={3,4,2,1};
    string deptNames[dept]={"SOftware Engineering (SE)","Artificial Intelligence (AI)","Computer Science (CS)","Data Science (DS)"};
    //Jagged Array
    double *gpa[dept];
    for(int i=0;i<dept;i++){
        gpa[i]=new double [courses[i]];
    }
    for(int i=0;i<dept;i++){
        cout<<"Enter GPA for "<<deptNames[i]<<" : "<<endl;
        for(int j=0;j<courses[i];j++){
            cout<<"Course "<<j+1<<": ";
            cin>>gpa[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<"<---Displaying GPA---> "<<endl;
    //Display GPA
    for(int i=0;i<dept;i++){
        cout<<"GPA for "<<deptNames[i]<<" : "<<endl;
        for(int j=0;j<courses[i];j++){
            cout<<"Course "<<j+1<<": "<<gpa[i][j]<<endl;
        }
        cout<<endl;
    }
    //Free memory
    for(int i=0;i<dept;i++){
        delete[] gpa[i];
    }   
    delete [] gpa;
    return 0;
}