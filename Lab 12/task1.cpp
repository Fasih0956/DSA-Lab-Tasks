#include<iostream>
#include<string>
using namespace std;
void bruteforce(string text , string pattern , int &count){
    int m = text.length();
    int n = pattern.length();
    cout<<"[ ";
    for (int i = 0 ;i <= m-n; i++){
        int j = 0;
        count++;    // extra challenge to count no. of comparisons
        while ( j < n && text[i+j] == pattern[j]){
            j++ ;
            count++;
        }
        if(n == j){
            cout<<i<<" ";
        }
    }
    cout<<"]"<<endl;
    return ;
}
int main(){
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";
    int count = 0;
    bruteforce(text, pattern,count);
    cout<<"Total no. of comparisons made by algorithm = "<<count<<endl;
    return 0;
}