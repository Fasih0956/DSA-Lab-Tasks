#include<iostream>
#include<string>
using namespace std;
void rabinkarp(string text , string pattern){
    int n = text.length();
    int m = pattern.length();
    if( m==0 || m > n){
        cout<<"Invalid Pattern !"<<endl;
    }
    int d = 256 ;
    int q = 101 ;
    long long h = 1 ;
    long long p = 0;
    long long t = 0;

    for(int i=0 ; i<m-1 ; i++){
        h = (h * d) % q;
    }
    for(int i=0 ; i<m ;i++){
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q ;
    }
    for(int i = 0 ; i <= n - m ; i++){
        if(p == t) {
            bool match = true ;
            for(int j=0 ; j < m ; j++){
                if ( (text[i+j]) != (pattern[j]) ){    //extra challenge to check pattern
                    match = false;
                    break;
                }
            }
            if(match){
                cout<<i<<" ";
            } else {
                cout<<"False positive hash match at index "<<i
                <<" same hash value but different strings. "<<i<<" discarded"<<endl;
            }
        }
        if ( i < n-m) {
            t = (d * (t - (text[i])*h) + (text[m+i])) % q;
            if(t<0){
                t+=q ;
            }
        }
    }
}
int main(){
    string text = "Data structures and algorithms are fun.Algorithms make tasks easier.";
    for (char &c : text) {
    c = tolower(c);
    }
    string pattern = "Algorithms";
    for (char &c : pattern){
        c = tolower(c);
    }
    rabinkarp(text,pattern);
    cout<<endl;

    cout<<"<---Demonstrating the effect of hash collissions--->"<<endl;
    string newt = "A2";
    string newp = "Ba";
    rabinkarp(newt,newp);
    return 0;
}