#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Node {
    public:
    string name ;
    int score ;
    Node* next ;
    Node(string name , int score) {
        this -> name = name ;
        this -> score = score ;
        this -> next = NULL ;
    }
    ~Node() {
        if ( this -> next != NULL) {
            this-> next = NULL ;
            delete next ;        }
    }
};
void addNode(Node* &head ,string n , int v) {
    if(v < 0 || v > 100) {
        cout<<"Enter marks between (0-100)"<<endl ;
        return ;
    }
    else {
    Node* newNode = new Node( n , v) ;
    if ( head == NULL) {
        head = newNode ;
        return ;
    }
    else {
        newNode -> next = head ;
        head = newNode ;
        return ;
    }
}
}
void sortRadix(Node* &head ) {
    if(head == NULL) return ;
    else {
        vector<Node*> bin[10] ;
            for(int e = 1 ; 100 / e > 0 ; e = e *10 ) {
                Node* temp = head ;
                while(temp != NULL) {
                    int digit = (temp -> score / e) % 10 ;
                    bin[digit].push_back(temp) ;
                    temp = temp -> next ;
            }
            Node* newHead = NULL ;
            Node* tail = NULL ;
                for ( int d = 0 ; d < 10 ; d++) {
                    for(Node* node : bin[d]) {
                        if ( newHead == NULL) {
                        newHead = node ;
                        tail = node ;
                    } else {
                        tail -> next = node ;
                        tail = node ;
                    }
                }    
            }
            if(tail != NULL) {
            head = newHead ;
            tail->next = NULL ;
            for (int i = 0; i < 10; i++) {
                     bin[i].clear();
            }

        }
    }
}
}
void print(Node* head) {
    while (head != NULL) {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}
void search(Node*& head, const string& n, int s) {
    vector<Node*> students;
    Node* temp = head;
    while (temp != NULL) {
        students.push_back(temp);
        temp = temp->next;
    }
    // since the list was already sorted in ascending order no need to sort , we apply direct binary search.
    int left = 0, right = students.size() - 1;
    bool found = false;
    int index ;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (students[mid]->score == s && students[mid]->name == n) {
            index = mid;
            found = true ;
            break;
        } else if (students[mid]->score < s) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (found == false) {
        cout << "Student not found!"<<endl;
        return;
    }
    Node* tempNode = students[index];
    if (head == tempNode) {
        head = head->next;
        tempNode -> next = NULL ;
        delete tempNode;
        return;
    }
    Node* curr = head ;
    Node* prev = NULL ;
    while (curr != tempNode && curr != NULL) {
        prev = curr;
        curr= curr->next;
    }
    prev->next = curr->next;
    curr -> next = NULL ;
    delete tempNode ;
}
int main() {
    Node* head = NULL ;
    int score ;
    string name ;
    addNode(head , "Ayan" , 90) ;
    addNode(head , "Zameer" ,60 ) ;
    addNode(head , "Sara" , 70) ;
    addNode(head , "Sohail" , 30) ;
    addNode(head , "Ahmed" , 20) ;

    sortRadix(head) ;
    print(head) ;

    cout<<"Enter name and score of the student:";
    cin>>name>>score ;

    search(head , name , score) ;
     print(head) ;

    return 0 ;
}


