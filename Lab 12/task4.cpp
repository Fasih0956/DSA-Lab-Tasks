#include<iostream>
#include<vector>
#include<string>
using namespace std;
void lpsarray(string pattern , vector<int> &lps){
    int m = pattern.length();
    lps[0] = 0;
    int len = 0;
    int i = 1 ;

    while ( i < m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        } else {
            if(len != 0){
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void kmpalgo(string text , string pattern){
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m) ;
    lpsarray(pattern , lps);
    cout<<"LPS array used: [ ";    //extra challenge
    for(int k = 0; k < m; k++) {
        cout<<lps[k]<<" ";
    }
    cout << "]" << endl;
    int i = 0;
    int j = 0;
    cout<<"[ ";
    
    while(i < n){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == m){
            cout<<i - j<<" ";
            j= lps[j - 1];
        }else if(i < n && pattern[j] != text[i]){
            if(j != 0){
                j = lps[j - 1];
            } else{
                i++;
            }
        }
    }
    cout<<"]"<<endl;
}
int main(){
    string text="ABAAABCDBBABCDDEBCABC";
    string pattern = "ABC";
    kmpalgo(text , pattern);
    return 0;
}