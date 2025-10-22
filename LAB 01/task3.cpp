#include <iostream>
using namespace std;
class Box {
    int* n;   
public:
    Box(int value = 0) {
        n = new int(value);                // Default constructor
    }
    Box(const Box& other) {
        n = new int(*other.n);            // Copy constructor (deep copy)
    }
    Box& operator=(const Box& other) {
        if (this == &other)  
            return *this;                  // Copy assignment operator (deep copy)
        delete n;                        
        n = new int(*other.n);        
        return *this;
    }
    ~Box() {
        cout << "Freeing memory" <<endl;
        delete n;
    }
    void setValue(int v) { *n = v; }
    int getValue() const { return *n; }
};
int main() {
    Box box1(50);
    Box box2 = box1;   //Deep copy

    cout << "box1: " << box1.getValue() << endl;
    cout << "box2: " << box2.getValue() << endl;

    cout << "Changing box2 value" << endl;
    box2.setValue(20);

    cout << "box1: " << box1.getValue() << endl; 
    cout << "box2: " << box2.getValue() << endl;  

    cout << "Assignment Test" << endl;
    Box box3;
    box3 = box1;    // calls copy assignment operator
    cout << "b3: " << box3.getValue() << endl;

    return 0;
}

