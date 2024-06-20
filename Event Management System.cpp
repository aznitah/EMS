#include <iostream>
#include <conio.h>
#include <iomanip>
#include <sstream>
#include <ctime>

#include "DBConnection.h"
#include "admin.h"
#include "client.h"
#include "menu.h"

using namespace std;

void registerAccount();
void roleMenu();
void loginAdmin();
void loginClient();
void home(admin user);
void home(client user);
void addPackageOrService();
void updatePackageOrService();
void deletePackageOrService();
void eventType();
void eventRate();
void monthlyReport();
void registerEvent(client user);
void updateEvent(client user);
void rateEvent(client user);
void deleteEvent(client user);
void paymentEvent(client user);

bool isNumeric(string input);
bool toInteger(string* input, int* valueholder);

int main() {
    Menu mainmenu;
    mainmenu.header = "------ Welcome to Event Management System ------";
    mainmenu.addOption("Login");
    mainmenu.addOption("Register");
    mainmenu.addOption("Exit");

    while (1) {
        switch (mainmenu.prompt())
        {
        case 1:
            roleMenu();
            break;
        case 2:
            registerAccount();
            break;
        case 3:
            return 0;
        default:
            break;
        }
    }
}

void roleMenu() {
    Menu roleMenu;
    roleMenu.addOption("Login as admin");
    roleMenu.addOption("Login as client");

    while (1) {
        switch (roleMenu.prompt())
        {
        case 1:
            loginAdmin();
            break;
        case 2:
            loginClient();
            break;
        case 3:
            return;
        default:
            break;
        }
    }
}

void registerAccount() {
    client newacc;

    Menu rgMenu;
    rgMenu.header = "Registration Menu";
    rgMenu.addOption("Name");
    rgMenu.addOption("Phone Number");
    rgMenu.addOption("Email");
    rgMenu.addOption("Username");
    rgMenu.addOption("Password");
    rgMenu.addOption("Register");
    rgMenu.addOption("Back");

    string tmpinput;
    bool valid = true;
    while (1) {
        switch (rgMenu.prompt()) {
        case 1:
            cout << "Insert Name:";
            cin >> newacc.clientName;
            rgMenu.setValue(0, newacc.clientName);
            break;
        case 2:
            cout << "Insert Phone Number:";
            cin >> newacc.clientPhoneNumber;
            rgMenu.setValue(1, newacc.clientPhoneNumber);
            break;
        case 3:
            cout << "Insert Email:";
            cin >> newacc.clientEmail;
            rgMenu.setValue(2, newacc.clientEmail);
            break;
        case 4:
            cout << "Insert Username:";
            cin >> newacc.clientUsername;
            rgMenu.setValue(3, newacc.clientUsername);
            break;
        case 5:
            cout << "Insert password:";
            cin >> tmpinput;
            if (tmpinput.length() < 6) {
                cout << "Password must be at least 6 characters long";
                _getch();
            }
            else {
                newacc.clientPassword = tmpinput;
                rgMenu.setValue(4, newacc.clientPassword);
            }
            break;
        case 6: {
            DBConnection dbConn;
            dbConn.prepareStatement("INSERT INTO client (clientName, clientPhoneNumber, clientEmail, clientUsername, clientPassword) VALUES (?, ?, ?, ?, ?)");
            dbConn.getStatement()->setString(1, newacc.clientName);
            dbConn.getStatement()->setString(2, newacc.clientPhoneNumber);
            dbConn.getStatement()->setString(3, newacc.clientEmail);
            dbConn.getStatement()->setString(4, newacc.clientUsername);
            dbConn.getStatement()->setString(5, newacc.clientPassword);
            dbConn.QueryStatement();
            cout << "Account registered successfully!" << endl;
            _getch();
            break;
        }
        case 7:
            return;
        default:
            break;
        }
    }
}

void loginAdmin() {
    Menu loginAdmin;
    loginAdmin.header = "LOGIN";
    loginAdmin.addOption("Username");
    loginAdmin.addOption("Password");
    loginAdmin.addOption("Login");
    loginAdmin.addOption("Back");

    admin user;

    while (1) {
        switch (loginAdmin.prompt())
        {
        case 1:
            cout << "Insert Username:";
            cin >> user.adminUsername;
            loginAdmin.setValue(0, user.adminUsername);
            break;
        case 2:
            cout << "Insert Password:";
            cin >> user.adminPassword;
            loginAdmin.setValue(1, user.adminPassword);
            break;
        case 3: {
            DBConnection dbConn;
            dbConn.prepareStatement("SELECT * FROM admin WHERE adminUsername = ? AND adminPassword = ?");
            dbConn.getStatement()->setString(1, user.adminUsername);
            dbConn.getStatement()->setString(2, user.adminPassword);
            dbConn.QueryResult();
            if (dbConn.getResult()->next()) {
                home(user);
            }
            else {
                cout << "Invalid Login" << endl;
                _getch();
            }
            break;
        }
        case 4:
            return;
        default:
            break;
        }
    }
}

void loginClient() {
    Menu loginClient;
    loginClient.header = "LOGIN";
    loginClient.addOption("Username");
    loginClient.addOption("Password");
    loginClient.addOption("Login");
    loginClient.addOption("Back");

    client user;

    while (1) {
        switch (loginClient.prompt())
        {
        case 1:
            cout << "Insert Username:";
            cin >> user.clientUsername;
            loginClient.setValue(0, user.clientUsername);
            break;
        case 2:
            cout << "Insert Password:";
            cin >> user.clientPassword;
            loginClient.setValue(1, user.clientPassword);
            break;
        case 3: {
            DBConnection dbConn;
            dbConn.prepareStatement("SELECT * FROM client WHERE clientUsername = ? AND clientPassword = ?");
            dbConn.getStatement()->setString(1, user.clientUsername);
            dbConn.getStatement()->setString(2, user.clientPassword);
            dbConn.QueryResult();
            sql::ResultSet* res = dbConn.getResult();

            if (res->next()) {
                user.clientID = res->getInt("clientID");
                user.clientName = res->getString("clientName");
                user.clientPhoneNumber = res->getString("clientPhoneNumber");
                user.clientEmail = res->getString("clientEmail");
                user.clientUsername = res->getString("clientUsername");
                user.clientPassword = res->getString("clientPassword");
                home(user);
            }

            else {
                cout << "Invalid Login" << endl;
                _getch();
            }
            break;
        }
        case 4:
            return;
        default:
            break;
        }
    }
}

void home(admin user) {
    Menu homeMenu;
    homeMenu.header = "ADMIN HOME";
    homeMenu.addOption("Add package or service");
    homeMenu.addOption("Update package or service");
    homeMenu.addOption("Delete package or service");
    homeMenu.addOption("View monthly report");
    homeMenu.addOption("Back");

    while (1) {
        switch (homeMenu.prompt())
        {
        case 1:
            addPackageOrService();
            break;
        case 2:
            updatePackageOrService();
            break;
        case 3:
            deletePackageOrService();
            break;
        case 4:
            monthlyReport();
            break;
        case 5:
            return;
        default:
            break;
        }
    }
}

void addPackageOrService() {
    string packageName, packageDescription, packagePrice;
    int packageCapacity, venueID;

    cout << "Enter package/service name: ";
    cin.ignore(); // Ignore the leftover newline character from previous input
    getline(cin, packageName);

    cout << "Enter package/service description: ";
    getline(cin, packageDescription);

    cout << "Enter package/service price: ";
    getline(cin, packagePrice);

    cout << "Enter package/service capacity: ";
    while (!(cin >> packageCapacity)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Enter an integer for capacity: ";
    }
    cin.ignore(); // Ignore the leftover newline character

    DBConnection dbConn;
    dbConn.prepareStatement("SELECT * FROM venue");
    dbConn.QueryResult();
    sql::ResultSet* res = dbConn.getResult();

    cout << "Available Venues:" << endl;
    while (res->next()) {
        cout << "ID: " << res->getInt("venueID") << " - " << res->getString("venueLocation") << " (" << res->getString("venueCategory") << ")" << endl;
    }

    cout << "Enter venue ID: ";
    while (!(cin >> venueID)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Enter an integer for venue ID: ";
    }

    dbConn.prepareStatement("SELECT COUNT(*) AS count FROM venue WHERE venueID = ?");
    dbConn.getStatement()->setInt(1, venueID);
    dbConn.QueryResult();
    res = dbConn.getResult();

    if (res->next() && res->getInt("count") == 1) {
        dbConn.prepareStatement("INSERT INTO event (eventName, eventDescription, eventPrice, eventCapacity, venueID) VALUES (?, ?, ?, ?, ?)");
        dbConn.getStatement()->setString(1, packageName);
        dbConn.getStatement()->setString(2, packageDescription);
        dbConn.getStatement()->setString(3, packagePrice);
        dbConn.getStatement()->setInt(4, packageCapacity);
        dbConn.getStatement()->setInt(5, venueID);
        dbConn.QueryStatement();

        cout << "Package/service added successfully!" << endl;
    }
    else {
        cout << "Invalid venue ID." << endl;
    }

    _getch();
}




void updatePackageOrService() {
    DBConnection dbConn;
    dbConn.prepareStatement("SELECT eventID, eventName FROM event");
    dbConn.QueryResult();
    sql::ResultSet* res = dbConn.getResult();

    cout << "Available Packages/Services:" << endl;
    while (res->next()) {
        cout << "ID: " << res->getInt("eventID") << " - " << res->getString("eventName") << endl;
    }

    int packageID;
    cout << "Enter package/service ID to update: ";
    cin >> packageID;

    dbConn.prepareStatement("SELECT * FROM event WHERE eventID = ?");
    dbConn.getStatement()->setInt(1, packageID);
    dbConn.QueryResult();
    res = dbConn.getResult();

    if (!res->next()) {
        cout << "Invalid package/service ID." << endl;
        _getch();
        return;
    }

    string packageName = res->getString("eventName");
    string packageDescription = res->getString("eventDescription");
    string packagePrice = res->getString("eventPrice");
    int packageCapacity = res->getInt("eventCapacity");
    int venueID = res->getInt("venueID");

    cout << "Package/Service Details:" << endl;
    cout << "1. Name: " << packageName << endl;
    cout << "2. Description: " << packageDescription << endl;
    cout << "3. Venue ID: " << venueID << endl;
    cout << "4. Price: " << packagePrice << endl;
    cout << "5. Capacity: " << packageCapacity << endl;
    cout << "Enter the number of the detail you want to change (0 to finish): ";

    int choice;
    cin >> choice;

    while (choice != 0) {
        switch (choice) {
        case 1:
            cout << "Enter new package/service name: ";
            cin.ignore();
            getline(cin, packageName);
            break;
        case 2:
            cout << "Enter new package/service description: ";
            cin.ignore();
            getline(cin, packageDescription);
            break;
        case 3:
            cout << "Available Venues:" << endl;
            dbConn.prepareStatement("SELECT * FROM venue");
            dbConn.QueryResult();
            res = dbConn.getResult();
            while (res->next()) {
                cout << "ID: " << res->getInt("venueID") << " - " << res->getString("venueLocation") << " (" << res->getString("venueCategory") << ")" << endl;
            }
            cout << "Enter new venue ID: ";
            cin >> venueID;
            dbConn.prepareStatement("SELECT COUNT(*) AS count FROM venue WHERE venueID = ?");
            dbConn.getStatement()->setInt(1, venueID);
            dbConn.QueryResult();
            res = dbConn.getResult();
            if (!(res->next() && res->getInt("count") == 1)) {
                cout << "Invalid venue ID." << endl;
                _getch();
                return;
            }
            break;
        case 4:
            cout << "Enter new package/service price: ";
            cin >> packagePrice;
            break;
        case 5:
            cout << "Enter new package/service capacity: ";
            cin >> packageCapacity;
            break;
        default:
            cout << "Invalid choice. Please enter a valid number." << endl;
            break;
        }
        cout << "Enter the number of the detail you want to change (0 to finish): ";
        cin >> choice;
    }

    dbConn.prepareStatement("UPDATE event SET eventName = ?, eventDescription = ?, eventPrice = ?, eventCapacity = ?, venueID = ? WHERE eventID = ?");
    dbConn.getStatement()->setString(1, packageName);
    dbConn.getStatement()->setString(2, packageDescription);
    dbConn.getStatement()->setString(3, packagePrice);
    dbConn.getStatement()->setInt(4, packageCapacity);
    dbConn.getStatement()->setInt(5, venueID);
    dbConn.getStatement()->setInt(6, packageID);
    dbConn.QueryStatement();

    cout << "Package/service updated successfully!" << endl;
    _getch();
}


void deletePackageOrService() {
    DBConnection dbConn;
    dbConn.prepareStatement("SELECT eventID, eventName FROM event");
    dbConn.QueryResult();
    sql::ResultSet* res = dbConn.getResult();

    cout << "Available Packages/Services:" << endl;
    while (res->next()) {
        cout << "ID: " << res->getInt("eventID") << " - " << res->getString("eventName") << endl;
    }

    int packageID;
    cout << "Enter package/service ID to delete: ";
    cin >> packageID;

    dbConn.prepareStatement("SELECT COUNT(*) AS count FROM event WHERE eventID = ?");
    dbConn.getStatement()->setInt(1, packageID);
    dbConn.QueryResult();
    res = dbConn.getResult();

    if (res->next() && res->getInt("count") == 1) {
        dbConn.prepareStatement("DELETE FROM event WHERE eventID = ?");
        dbConn.getStatement()->setInt(1, packageID);
        dbConn.QueryStatement();

        cout << "Package/service deleted successfully!" << endl;
    }
    else {
        cout << "Invalid package/service ID." << endl;
    }

    _getch();
}



void home(client user) {
    Menu homeMenu;
    homeMenu.header = "CLIENT HOME - Welcome " + user.clientUsername;
    homeMenu.addOption("Register event");
    homeMenu.addOption("Update event");
    homeMenu.addOption("Rate event");
    homeMenu.addOption("Delete event");
    homeMenu.addOption("Payment event");
    homeMenu.addOption("Back");

    while (1) {
        switch (homeMenu.prompt())
        {
        case 1:
            registerEvent(user);
            break;
        case 2:
            updateEvent(user);
            break;
        case 3:
            rateEvent(user);
            break;
        case 4:
            deleteEvent(user);
            break;
        case 5:
            paymentEvent(user);
            break;
        case 6:
            return;
        default:
            break;
        }
    }
}

void eventType() {
    DBConnection dbConn;
    dbConn.prepareStatement("SELECT * FROM event");
    dbConn.QueryResult();
    sql::ResultSet* res = dbConn.getResult();

    cout << "Event Types:" << endl;
    while (res->next()) {
        cout << res->getInt("eventID") << ". " << res->getString("eventName") << endl;
    }
    _getch();
}

void eventRate() {
    DBConnection dbConn;
    dbConn.prepareStatement("SELECT * FROM event");
    dbConn.QueryResult();
    sql::ResultSet* res = dbConn.getResult();

    cout << "Event Rates:" << endl;
    while (res->next()) {
        cout << res->getInt("eventID") << ". " << res->getString("eventName") << ": " << res->getString("eventPrice") << endl;
    }
    _getch();
}

void monthlyReport() {
    int currentYear = 2024;

    DBConnection dbConn;
    dbConn.prepareStatement(
        "SELECT MONTH(e.eventDate) AS month, COUNT(e.eventID) AS totalEvents, SUM(p.paymentAmount) AS totalRevenue FROM event e JOIN client_event ce ON e.eventID = ce.eventID JOIN payment p ON ce.paymentID = p.paymentID WHERE YEAR(e.eventDate) = ? GROUP BY MONTH(e.eventDate) ORDER BY MONTH(e.eventDate);"
    );
    dbConn.getStatement()->setInt(1, currentYear);
    dbConn.QueryResult();
    sql::ResultSet* res = dbConn.getResult();
    cout << "Monthly Report for " << currentYear << ":" << endl;

    while (res->next()) {
        int month = res->getInt("month");
        string monthName;
        switch (month) {
        case 1: monthName = "January"; break;
        case 2: monthName = "February"; break;
        case 3: monthName = "March"; break;
        case 4: monthName = "April"; break;
        case 5: monthName = "May"; break;
        case 6: monthName = "June"; break;
        case 7: monthName = "July"; break;
        case 8: monthName = "August"; break;
        case 9: monthName = "September"; break;
        case 10: monthName = "October"; break;
        case 11: monthName = "November"; break;
        case 12: monthName = "December"; break;
        default: monthName = "Unknown"; break;
        }
        cout << monthName << ":" << endl;
        cout << "  Total Events: " << res->getInt("totalEvents") << endl;
        cout << "  Total Revenue: RM " << res->getDouble("totalRevenue") << endl;
    }

    _getch();
}

void registerEvent(client user) {
    DBConnection dbConn;
    dbConn.prepareStatement("SELECT eventID, eventName, eventDescription, eventVenue, eventPrice, eventCapacity FROM event");
    dbConn.QueryResult();
    sql::ResultSet* res = dbConn.getResult();

    cout << "Available Events:" << endl;
    while (res->next()) {
        cout << "ID: " << res->getInt("eventID") << endl;
        cout << "Name: " << res->getString("eventName") << endl;
        cout << "Description: " << res->getString("eventDescription") << endl;
        cout << "Venue: " << res->getString("eventVenue") << endl;
        cout << "Price: " << res->getString("eventPrice") << endl;
        cout << "Capacity: " << res->getString("eventCapacity") << endl;
        cout << "---------------------------------" << endl;
    }

    int eventID;
    cout << "Enter event ID to book: ";
    cin >> eventID;

    dbConn.prepareStatement("SELECT COUNT(*) AS count FROM event WHERE eventID = ?");
    dbConn.getStatement()->setInt(1, eventID);
    dbConn.QueryResult();
    res = dbConn.getResult();

    if (res->next() && res->getInt("count") == 1) {
        dbConn.prepareStatement("INSERT INTO client_event (clientID, eventID) VALUES (?, ?)");
        dbConn.getStatement()->setInt(1, user.clientID);
        dbConn.getStatement()->setInt(2, eventID);
        dbConn.QueryStatement();

        cout << "Event booked successfully!" << endl;
    }
    else {
        cout << "Invalid event ID." << endl;
    }

    _getch();
}


void updateEvent(client user) {
    DBConnection dbConn;
    dbConn.prepareStatement("SELECT e.eventID, e.eventName, e.eventDescription, e.eventVenue, e.eventPrice, e.eventCapacity FROM event e JOIN client_event ce ON e.eventID = ce.eventID WHERE ce.clientID = ?");
    dbConn.getStatement()->setInt(1, user.clientID);
    dbConn.QueryResult();
    sql::ResultSet* res = dbConn.getResult();

    cout << "Your Booked Events:" << endl;
    while (res->next()) {
        cout << "ID: " << res->getInt("eventID") << endl;
        cout << "Name: " << res->getString("eventName") << endl;
        cout << "Description: " << res->getString("eventDescription") << endl;
        cout << "Venue: " << res->getString("eventVenue") << endl;
        cout << "Price: " << res->getString("eventPrice") << endl;
        cout << "Capacity: " << res->getString("eventCapacity") << endl;
        cout << "---------------------------------" << endl;
    }

    int eventID;
    cout << "Enter the ID of the event you want to modify: ";
    cin >> eventID;

    dbConn.prepareStatement("SELECT * FROM client_event WHERE clientID = ? AND eventID = ?");
    dbConn.getStatement()->setInt(1, user.clientID);
    dbConn.getStatement()->setInt(2, eventID);
    dbConn.QueryResult();
    res = dbConn.getResult();

    if (!res->next()) {
        cout << "You have not registered for this event or invalid event ID." << endl;
        _getch();
        return;
    }

    dbConn.prepareStatement("SELECT eventID, eventName, eventDescription, eventVenue, eventPrice, eventCapacity FROM event");
    dbConn.QueryResult();
    res = dbConn.getResult();

    cout << "Available Events:" << endl;
    while (res->next()) {
        cout << "ID: " << res->getInt("eventID") << endl;
        cout << "Name: " << res->getString("eventName") << endl;
        cout << "Description: " << res->getString("eventDescription") << endl;
        cout << "Venue: " << res->getString("eventVenue") << endl;
        cout << "Price: " << res->getString("eventPrice") << endl;
        cout << "Capacity: " << res->getString("eventCapacity") << endl;
        cout << "---------------------------------" << endl;
    }

    int newEventID;
    cout << "Enter the ID of the new event you want to register for: ";
    cin >> newEventID;

    dbConn.prepareStatement("SELECT COUNT(*) AS count FROM event WHERE eventID = ?");
    dbConn.getStatement()->setInt(1, newEventID);
    dbConn.QueryResult();
    res = dbConn.getResult();

    if (res->next() && res->getInt("count") == 1) {
        dbConn.prepareStatement("UPDATE client_event SET eventID = ? WHERE clientID = ? AND eventID = ?");
        dbConn.getStatement()->setInt(1, newEventID);
        dbConn.getStatement()->setInt(2, user.clientID);
        dbConn.getStatement()->setInt(3, eventID);
        dbConn.QueryStatement();

        cout << "Event modified successfully!" << endl;
    }
    else {
        cout << "Invalid new event ID." << endl;
    }

    _getch();
}

void rateEvent(client user) {
    DBConnection dbConn;
    dbConn.prepareStatement("SELECT e.eventID, e.eventName FROM event e JOIN client_event ce ON e.eventID = ce.eventID WHERE ce.clientID = ?");
    dbConn.getStatement()->setInt(1, user.clientID);
    dbConn.QueryResult();
    sql::ResultSet* res = dbConn.getResult();

    cout << "Your Booked Events:" << endl;
    while (res->next()) {
        cout << "ID: " << res->getInt("eventID") << " - " << res->getString("eventName") << endl;
    }

    int eventID;
    cout << "Enter event ID to rate: ";
    cin >> eventID;

    // Check if payment is done for the selected event
    dbConn.prepareStatement("SELECT COUNT(*) AS count FROM client_event WHERE clientID = ? AND eventID = ? AND paymentID IS NOT NULL");
    dbConn.getStatement()->setInt(1, user.clientID);
    dbConn.getStatement()->setInt(2, eventID);
    dbConn.QueryResult();
    res = dbConn.getResult();

    if (res->next() && res->getInt("count") == 1) {
        string comments;
        cout << "Enter your comments: ";
        cin.ignore();
        getline(cin, comments);

        dbConn.prepareStatement("INSERT INTO rate (eventID, comments, clientID) VALUES (?, ?, ?)");
        dbConn.getStatement()->setInt(1, eventID);
        dbConn.getStatement()->setString(2, comments);
        dbConn.getStatement()->setInt(3, user.clientID);
        dbConn.QueryStatement();

        cout << "Event rated successfully!" << endl;
    }
    else {
        cout << "You can only rate events after payment is done." << endl;
    }

    _getch();
}



void deleteEvent(client user) {
    DBConnection dbConn;
    dbConn.prepareStatement("SELECT e.eventID, e.eventName FROM event e JOIN client_event ce ON e.eventID = ce.eventID WHERE ce.clientID = ?");
    dbConn.getStatement()->setInt(1, user.clientID);
    dbConn.QueryResult();
    sql::ResultSet* res = dbConn.getResult();

    cout << "Your Booked Events:" << endl;
    while (res->next()) {
        cout << "ID: " << res->getInt("eventID") << " - " << res->getString("eventName") << endl;
    }

    int eventID;
    cout << "Enter event ID to delete: ";
    cin >> eventID;

    dbConn.prepareStatement("DELETE FROM client_event WHERE clientID = ? AND eventID = ?");
    dbConn.getStatement()->setInt(1, user.clientID);
    dbConn.getStatement()->setInt(2, eventID);
    dbConn.QueryStatement();

    cout << "Event deleted successfully!" << endl;
    _getch();
}

#include <regex>

void paymentEvent(client user) {
    DBConnection dbConn;
    dbConn.prepareStatement("SELECT e.eventID, e.eventName, e.eventPrice FROM event e JOIN client_event ce ON e.eventID = ce.eventID WHERE ce.clientID = ?");
    dbConn.getStatement()->setInt(1, user.clientID);
    dbConn.QueryResult();
    sql::ResultSet* res = dbConn.getResult();

    cout << "Your Booked Events:" << endl;
    while (res->next()) {
        cout << "ID: " << res->getInt("eventID") << " - " << res->getString("eventName") << " - Price: " << res->getString("eventPrice") << endl;
    }

    int eventID;
    cout << "Enter event ID to pay for: ";
    cin >> eventID;

    // Check if payment is already done for the selected event
    dbConn.prepareStatement("SELECT e.eventPrice FROM event e JOIN client_event ce ON e.eventID = ce.eventID WHERE ce.clientID = ? AND ce.eventID = ? AND ce.paymentID IS NULL");
    dbConn.getStatement()->setInt(1, user.clientID);
    dbConn.getStatement()->setInt(2, eventID);
    dbConn.QueryResult();
    res = dbConn.getResult();

    if (res->next()) {
        string priceStr = res->getString("eventPrice");
        // Extract numeric value from price string
        float price = stof(regex_replace(priceStr, regex("[^0-9.]"), ""));

        cout << "Event Price: " << price << endl;

        float amount;
        cout << "Enter payment amount: ";
        cin >> amount;

        if (amount < price) {
            cout << "The payment amount is less than the event price. Please pay the full amount." << endl;
            _getch();
            return;
        }

        dbConn.prepareStatement("INSERT INTO payment (paymentAmount, clientID) VALUES (?, ?)");
        dbConn.getStatement()->setDouble(1, amount);
        dbConn.getStatement()->setInt(2, user.clientID);
        dbConn.QueryStatement();

        int paymentID = dbConn.getGeneratedId();

        dbConn.prepareStatement("UPDATE client_event SET paymentID = ? WHERE clientID = ? AND eventID = ?");
        dbConn.getStatement()->setInt(1, paymentID);
        dbConn.getStatement()->setInt(2, user.clientID);
        dbConn.getStatement()->setInt(3, eventID);
        dbConn.QueryStatement();

        cout << "Payment processed successfully!" << endl;
    }
    else {
        cout << "You can only pay for events that have not been paid for yet." << endl;
    }

    _getch();
}

bool isNumeric(string input) {
    for (char c : input) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool toInteger(string* input, int* valueholder) {
    stringstream ss(*input);
    ss >> *valueholder;
    return !ss.fail();
}
