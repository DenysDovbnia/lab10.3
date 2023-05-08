#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Route {
    string start;
    string end;
    int number;
};

const int MAX_ROUTES = 100;

int read_routes(Route routes[]) {
    ifstream file;
    string filename="t.txt";
    int count = 0;

    file.open(filename);

    if (!file) {
        cout << "Error opening file!" << endl;
        return 0;
    }

    while (count < MAX_ROUTES && file >> routes[count].start >> routes[count].end >> routes[count].number) {
        count++;
    }

    file.close();

    return count;
}

void display_routes(const Route routes[], int count) {
    if (count == 0) {
        cout << "No routes found!" << endl;
        return;
    }

    cout << "Routes:" << endl;

    for (int i = 0; i < count; i++) {
        cout << routes[i].start << " - " << routes[i].end << " (" << routes[i].number << ")" << endl;
    }
}

void find_routes(const Route routes[], int count, string location) {
    bool found = false;

    cout << "Routes starting or ending at " << location << ":" << endl;

    for (int i = 0; i < count; i++) {
        if (routes[i].start == location || routes[i].end == location) {
            cout << routes[i].start << " - " << routes[i].end << " (" << routes[i].number << ")" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No routes found!" << endl;
    }
}

void add_route(Route routes[], int& count) {
    if (count == MAX_ROUTES) {
        cout << "Maximum number of routes reached!" << endl;
        return;
    }

    cout << "Enter start location: ";
    getline(cin, routes[count].start);

    cout << "Enter end location: ";
    getline(cin, routes[count].end);

    cout << "Enter route number: ";
    cin >> routes[count].number;
    cin.ignore();

    count++;

    cout << "Route added successfully!" << endl;
}

int main() {
    Route routes[MAX_ROUTES];
    int count = read_routes(routes);
    int choice;
    string location;

    do {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Display routes" << endl;
        cout << "2. Find routes" << endl;
        cout << "3. Add route" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            display_routes(routes, count);
            break;
        case 2:
            cout << "Enter location: ";
            getline(cin, location);
            find_routes(routes, count, location);
            break;
        case 3:
            add_route(routes, count);
            break;
        case 4:
            cout << "Quitting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
