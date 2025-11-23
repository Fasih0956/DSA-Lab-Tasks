#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int randomNumber;
void guessNumber(int player){
    int guess;
    cout<<"Player "<<player<< ", enter your guess (1-100): ";
    cin>>guess;
    if(guess==randomNumber){
        cout<<" Player " << player << " wins ! "<<endl;
        return;
    } 
    else if(guess<randomNumber) {
        cout<<"Too low! Try again."<<endl;
    } 
    else{
        cout<<"Too high! Try again."<<endl;
    }
    guessNumber(player %2 + 1);
}
int main(){
    srand(time(0));  
    randomNumber = rand() % 100 + 1;
    cout<<"<---Number Guessing Game--->"<<endl;
    
    guessNumber(2);
    return 0;
}
