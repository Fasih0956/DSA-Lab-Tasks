#include<iostream>
using namespace std;
int main(){
    int stu,sub,sum=0,highest=0,topper=-1;
    double total=0.0;
    cout<<"Enter no. of Students: ";
    cin>>stu;
    cout<<"Enter no. of Subjects: ";
    cin>>sub;
    //Dynamic 2D Array
    int **arr=new int *[stu];
    for(int i=0; i<stu;i++){
        arr[i]=new int [sub];
    }
    // Storing Subject Marks for each student 
    for(int i=0;i<stu;i++){
        for(int j=0;j<sub;j++){
            cout<<"Enter marks of Student "<<i+1<<" for Subject "<<j+1<<": ";
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    //Displaying Total marks of each student
    for(int i=0;i<stu;i++){
        sum=0;
        for(int j=0;j<sub;j++){
            sum+=arr[i][j];
        }
        if(sum>highest){
            highest=sum;
            topper=i+1;
        }
        cout<<"Total Marks of Student "<<i+1<<"= "<<sum<<endl;
    }
    cout<<endl;
    //Average Marks of all Subjects
    for(int i=0;i<sub;i++){
        total=0;
        for(int j=0;j<stu;j++){
            total+=arr[j][i];
        }
        double avg=static_cast<double>(total/stu);
        cout<<"Average Marks for Subject "<<i+1<<" = "<<avg<<endl;
    }
    cout<<endl;
    // Displaying Topper Student and Highest Marks
    cout<<"Topper Student is Student "<<topper<<" with highest marks "<<highest<<endl;
    //Freeing Memory
    for(int i=0;i<stu;i++){
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}