#include <iostream>
#include <string>
using namespace std;
class Product {
    string name;
    double price;
    int stock;
public:
    Product(string n="unknown", double p=0.0, int s=0) {
        name = n;
        price = p;
        stock = s;
    }
    Product(const Product& other) {
        name = other.name;
        price = other.price;              // Copy Constructor
        stock = other.stock;
    }
    Product& operator=(const Product& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;            // Assignment Operator
            stock = other.stock;
        }
        return *this;
    }
    void applyDiscount(int discount) {
        price -= (price * discount / 100.0);
    }
    void display() {
        cout << "Product: " << name
             << " | Price: PKR " << price
             << " | Stock: " << stock << endl;
    }
};
class Bundle {
    Product* products;
    int size;
    int capacity;
    int discount;
    bool ownsMemory;   //prevents double free for shallow copies

public:
    Bundle(int c = 10, int d = 0) {
        capacity = c;
        size = 0;
        discount = d;
        products = new Product[capacity];
        ownsMemory = true;
    }
    Bundle(const Bundle& other, bool shallow) {
        discount = other.discount;
        capacity = other.capacity;
        size = other.size;

        if (shallow) {
            products = other.products; //shallow copy
            ownsMemory = false;    
        } else {
            products = new Product[capacity]; // deep copy
            for (int i = 0; i < size; i++) {
                products[i] = other.products[i];
            }
            ownsMemory = true;
        }
    }
    Bundle(const Bundle& other) {
        discount = other.discount;
        capacity = other.capacity;
        size = other.size;
        products = new Product[capacity];
        for (int i = 0; i < size; i++) {
            products[i] = other.products[i];
        }
        ownsMemory = true;
    }
    Bundle& operator=(const Bundle& other) {
        if (this != &other) {
            if (ownsMemory) delete[] products;

            discount = other.discount;
            capacity = other.capacity;
            size = other.size;

            products = new Product[capacity];
            for (int i = 0; i < size; i++) {
                products[i] = other.products[i];
            }
            ownsMemory = true;
        }
        return *this;
    }

    void addProduct( Product& p) {
        if (size < capacity) {
            products[size++] = p;
        } else {
            cout << "Capacity Full!";
        }
    }

    void applyDiscount() {
        for (int i = 0; i < size; i++) {
            products[i].applyDiscount(discount);
        }
    }

    void display() const {
        cout << "Bundle (Discount: " << discount << "%)";
        for (int i = 0; i < size; i++) {
            products[i].display();
        }
    }

    ~Bundle() {
        if (ownsMemory) { 
            delete[] products;
        }
    }
};

int main() {
    Bundle b1(5, 20);
    b1.addProduct(Product("Laptop", 50000, 5));
    b1.addProduct(Product("Mouse", 2500, 50));
    b1.addProduct(Product("Keyboard", 4500, 30));

    cout << "Original Bundle:";
    b1.display();

    Bundle shallowCopy(b1, true);   // Shallow
    Bundle deepCopy(b1, false);     // Deep

    cout << "\nApplying discount to Bundle 1";
    b1.applyDiscount();

    cout << "After Discount:";
    cout << "Original:";
    b1.display();

    cout << "Shallow Copy (affected):";
    shallowCopy.display();

    cout << "Deep Copy (independent):";
    deepCopy.display();

    return 0;
}
