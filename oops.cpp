#include <iostream>
#include <string> 

using namespace std;

class Event {
    string name;
    string time;
    string date;
    string venue;

public:
    Event() {}

    Event(string n, string d, string t, string v) : name(n), date(d), time(t), venue(v) {}

    void display() const {
        cout << "Event: " << name << "\nDate: " << date << "\nTime: " << time << "\nVenue: " << venue << endl;
    }

    string getDate() const {
        return date;
    }
};

int main() {
    const int MaxEvents = 100;
    Event events[MaxEvents]; // Array to store events
    int count = 0;
    string data;
    int choice;
    cout << "Enter today's date (DD/MM/YYYY): ";
    cin >> data;

    do {
        cout << "---------------------------" << endl;
        cout << "Event Management System" << endl;
        
        cout << "1. Add Event" << endl;
        cout << "2. Display All Events" << endl;
        cout << "3. Today's Events" << endl;
        cout << "4. Upcoming Events" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                if (count < MaxEvents) {
                    string eventName, eventDate, eventTime, eventVenue;
                    
                    cout << "Enter event name: ";
                    cin.ignore(); // Ignore newline character
                    getline(cin, eventName);

                    cout << "Enter event date (DD/MM/YYYY): ";
                    getline(cin, eventDate);

                    cout << "Enter time of the event: ";
                    getline(cin, eventTime);

                    cout << "Enter event venue: ";
                    getline(cin, eventVenue);

                    events[count] = Event(eventName, eventDate, eventTime, eventVenue);
                    cout << "Event added successfully!" << endl;
                    count++;
                } else {
                    cout << "Cannot add more events. Maximum limit reached." << endl;
                }
                break;

            case 2: 
                if (count == 0) {
                    cout << "No events available." << endl;
                } else {
                    cout << "\nList of all events:" << endl;
                    for (int i = 0; i < count; i++) {
                        events[i].display();
                        cout << "---------------------" << endl;
                    }
                }
                break;
            
            case 3:
                cout << "\nToday's Events:" << endl;
                {
                    bool foundTodayEvent = false;
                    for (int i = 0; i < count; i++) {
                        if (events[i].getDate() == data) {
                            events[i].display();
                            cout << "---------------------" << endl;
                            foundTodayEvent = true;
                        }
                    }
                    if (!foundTodayEvent) {
                        cout << "No events scheduled for today." << endl;
                    }
                }
                break;

            case 4:
                cout << "\nUpcoming Events:" << endl;
                {
                    bool foundUpcomingEvent = false;
                    for (int i = 0; i < count; i++) {
                        if (events[i].getDate() > data) {
                            events[i].display();
                            cout << "---------------------" << endl;
                            foundUpcomingEvent = true;
                        }
                    }
                    if (!foundUpcomingEvent) {
                        cout << "No upcoming events." << endl;
                    }
                }
                break;

            case 5: 
                cout << "Exiting!" << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
