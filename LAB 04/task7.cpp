#include<iostream>
#include<string>
using namespace std;
class Search{
    public:
    string arr[10]={"Ahmed","Ali","Basit","Karim","Rizwan","Sarwar","Tariq","Taufiq","Yaseen","Zulfiqar"};
    int s = 10;
    int index;
    int count;

 pair<int , int> BinarySearch(string value) {
    int left = 0;
    int right = s-1;
    int count = 0;
    while (left <= right) {
        count++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            return {mid,count};
        }
        else if (arr[mid] < value) {
                   left = mid + 1;
        }
        else {
            right = mid - 1;
        }
}
        return {-1,count};
}

pair<int , int> linearSearch(string value){
    int count= 0;
    for(int i=0 ; i<s ; i++){
        if(arr[i]==value){
            count++;
            return {i,count};
        }
        count++;
    }
    return {-1,count};
}

void findAndAnalyze(string value) {
cout << "<---Searching for "<< value<<"--->"<<endl;

        auto lin = linearSearch(value);
        if (lin.first != -1)
            cout << "Linear Search: Found at index " << lin.first << " in " << lin.second << " steps" << endl;
        else
            cout << "Linear Search: Not found (checked " << lin.second << " steps)" << endl;

        auto bin = BinarySearch(value);
        if (bin.first != -1)
            cout << "Binary Search: Found at index " << bin.first << " in " << bin.second << " steps" << endl;
        else
            cout << "Binary Search: Not found (checked " << bin.second << " steps)" << endl;

        if(bin.second<lin.second){
            cout<<"Binary Search is better!"<<endl;
        }    
        else if(bin.second == lin.second){
            cout<<"Both are Equal!"<<endl;
        }
        else{
            cout<<"Linear Search is better!"<<endl;
        }
    }
};
int main(){
    Search search1;

    search1.findAndAnalyze("Aftab");
    search1.findAndAnalyze("Rizwan");
    search1.findAndAnalyze("Tariq");

    return 0;
}
