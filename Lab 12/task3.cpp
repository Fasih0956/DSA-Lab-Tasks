//bad charachter heuristic
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void badheuristic(const string pattern , vector<int> &badchar){
    int m = pattern.length();
    for (int i = 0 ; i < 256 ; i++){
        badchar[i] = -1 ;
    }
    for(int i = 0 ; i < m; i++){
        badchar[(int)pattern[i]] = i;
    }
}
void boyermoore(string text , string pattern){
    int n = text.length();
    int m = pattern.length();
    vector<int>badchar (256);
    badheuristic(pattern , badchar);
    int s = 0;
    cout<<"[ ";
    while( s <= n-m){
        int j = m-1 ;
        while ( j>=0 && pattern[j] == text[s+j] ){
            j-- ;
        }
        if(j < 0){
                cout<<s<<" ";   //bad heuristic
                if( s+m < n ){
                    s +=  m - badchar[text[s+m]] ;
                }else{
                    s+=1 ;
                }
        }else {
            int shift = max(1 , j - badchar[text[s+j]]);    //good suffix   , both implemented as extra challenge
            s+=shift ;
        }
    }
    cout<<"]"<<endl;
}
int main(){
    string text= "ACGTACGTGACG";
    string pattern = "ACG";
    boyermoore(text , pattern);
    return 0;
}