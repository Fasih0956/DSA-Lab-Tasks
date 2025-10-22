#include<iostream>
#include<vector>
using namespace std ;
class Node {
    public:
     int val;
     Node* next;
      Node(int val) {
        this -> val = val ;
        this -> next = NULL ;
      }
 };
class Solution {
public:
    int numComponents(Node* &head, vector<int>& nums) {
        int count = 0 ;
        int n = nums.size() ;
        for(int i = 0 ; i < n; i++ ) {
            bool swapped = false ;
            for(int j = 0 ; j < n - i - 1 ; j++) {
                 if(nums[j] > nums[j + 1]) {
                    swap(nums[j] , nums[j + 1]) ;
                    swapped = true ;
                 }
            }
            if(!swapped){
                break ;
            }
            for(int k = 0 ; k < n ; k++ ) {
                cout<<nums[k]<<" ";
            }
            cout<<endl ;
        }
        int i = 0 ;
        while(head != NULL && i < n ) {
            if(head -> val == nums [i]) {
                while (head != NULL && i < n && head -> val == nums[i]) {
                head = head -> next ;
                i++ ;
                }
                count++ ;
            }
            else {
                head = head -> next ;
            }
        }
    return count ;
    }
};
int main(){
    Solution sol ;
    vector<int> nums = {0,3,1,4};
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    cout<<sol.numComponents(head, nums)<<endl;
    return 0 ;
}