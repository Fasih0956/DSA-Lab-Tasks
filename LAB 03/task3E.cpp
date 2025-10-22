//Task 3 extended version with multiple flights
#include <iostream>
#include <string>
using namespace std;
class Passenger {
public:
    string name;
    Passenger* next;
    Passenger(string name = "") {
        this->name = name;
        this->next = NULL;
    }
    ~Passenger() {
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};
class Flight {
public:
    string flightNumber;
    Passenger* passengerHead;
    Flight* next;
    Flight(string fn) {
        flightNumber = fn;
        passengerHead = NULL;
        next = NULL;
    }
    ~Flight() {
        if (passengerHead != NULL) {
            delete passengerHead;
            passengerHead = NULL;
        }
        if (next != NULL) {
            delete next;
            next = NULL;
        }
    }
};
Flight* findFlight(string fn , Flight* &flightHead) {
    Flight* curr = flightHead;
    while (curr != NULL) {
        if (curr->flightNumber == fn) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}
void addFlight(string fn , Flight*& flightHead) {
    if (findFlight(fn , flightHead)) {
        cout << "Flight " << fn << " already exists.\n";
        return;
    }
    Flight* newF = new Flight(fn);
    newF->next = flightHead;
    flightHead = newF;
    cout << "Flight " << fn << " added.\n";
}
void insertPassenger(Passenger*& head, string name) {
    Passenger* newP = new Passenger(name);

    if (head == NULL || name < head->name) {
        newP->next = head;
        head = newP;
        return;
    }
    Passenger* curr = head;
    while (curr->next != NULL && curr->next->name < name) {
        curr = curr->next;
    }
    if (curr->next != NULL && curr->next->name == name) {
        cout << "Reservation already exists for " << name << ".\n";
        delete newP;
        return;
    }
    newP->next = curr->next;
    curr->next = newP;
}
void cancelPassenger(Passenger*& head, string name) {
    if (head == NULL) {
        cout << "No passengers found.\n";
        return;
    }
    if (head->name == name) {
        Passenger* temp = head;
        head = head->next;
        delete temp;
        cout << name << " canceled.\n";
        return;
    }
    Passenger* curr = head;
    while (curr->next != NULL && curr->next->name != name) {
        curr = curr->next;
    }
    if (curr->next == NULL) {
        cout << "Passenger not found.\n";
        return;
    }
    Passenger* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    cout << name << " canceled.\n";
}
void reserveTicket(string fn, string name , Flight* &flightHead) {
    Flight* f = findFlight(fn , flightHead);
    if (!f) {
        cout << "Flight not found.\n";
        return;
    }
    insertPassenger(f->passengerHead, name);
    cout << name << " reserved on flight " << fn << ".\n";
}
void cancelReservation(string fn, string name , Flight* &flightHead) {
    Flight* f = findFlight(fn , flightHead);
    if (!f) {
        cout << "Flight not found.\n";
        return;
    }
    cancelPassenger(f->passengerHead, name);
}
void checkReservation(string fn, string name , Flight* &flightHead) {
    Flight* f = findFlight(fn, flightHead);
    if (!f) {
        cout << "Flight not found.\n";
        return;
    }
    Passenger* curr = f->passengerHead;
    while (curr != NULL) {
        if (curr->name == name) {
            cout << name << " has a reservation on " << fn << ".\n";
            return;
        }
        curr = curr->next;
    }
    cout << name << " has no reservation on " << fn << ".\n";
}
void displayPassengers(string fn , Flight* &flightHead) {
    Flight* f = findFlight(fn,flightHead);
    if (!f) {
        cout << "Flight not found.\n";
        return;
    }
    if (!f->passengerHead) {
        cout << "No passengers on flight " << fn << ".\n";
        return;
    }
    cout << "Passengers on flight " << fn << ":\n";
    Passenger* curr = f->passengerHead;
    while (curr != NULL) {
        cout << "- " << curr->name << endl;
        curr = curr->next;
    }
}
void displayFlights(Flight* &flightHead) {
    if (flightHead==NULL) {
        cout << "No flights available.\n";
        return;
    }
    cout << "Available Flights:\n";
    Flight* temp = flightHead;
    int count = 1;
    while (temp != NULL) {
        cout << count <<"."<< temp->flightNumber << endl;
        temp = temp->next;
        count++;
    }
}
int main() {
    int choice;
    string flight, name;
    Flight* flightHead = NULL;

    while (true) {
        cout << "<--- Airline Ticket Reservation (Multiple Flights) --->" << endl;
        cout << "1. Add flight."<<endl;
        cout << "2. Reserve a ticket."<<endl;
        cout << "3. Cancel a reservation."<<endl;
        cout << "4. Check reservation."<<endl;
        cout << "5. Display passengers."<<endl;
        cout << "6. Display all flights"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter flight number: ";
            cin >> flight;
            addFlight(flight , flightHead);
            break;
        case 2:
            cout << "Enter flight number: ";
            cin >> flight;
            cout << "Enter passenger name: ";
            cin.ignore();
            getline(cin, name);
            reserveTicket(flight, name , flightHead);
            break;
        case 3:
            cout << "Enter flight number: ";
            cin >> flight;
            cout << "Enter passenger name: ";
            cin.ignore();
            getline(cin, name);
            cancelReservation(flight, name , flightHead);
            break;
        case 4:
            cout << "Enter flight number: ";
            cin >> flight;
            cout << "Enter passenger name: ";
            cin.ignore();
            getline(cin, name);
            checkReservation(flight, name , flightHead);
            break;
        case 5:
            cout << "Enter flight number: ";
            cin >> flight;
            displayPassengers(flight , flightHead);
            break;
        case 6:
            displayFlights( flightHead);
            break;
        case 7:
        cout << "Good Bye!" << endl;
            return 0;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}
