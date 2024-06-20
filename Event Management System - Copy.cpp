#include <iostream>  
#include <conio.h>
#include <iomanip>
#include <sstream>
// advanced
// include our custom class
#include "admin.h" 
#include "client.h"
#include "menu.h"
#include "event.h"

using namespace std;

//identifier
void registerAccount();
void roleMenu();
void loginAdmin();
void loginClient();
void registerEvent(client user);
void updateEvent(client user);
void rateEvent(client user);
void deleteEvent(client user);
void paymentEvent(client user);
void display();// CONTOH

void home(admin user);
void home(client user);
//
//
////utility functions
//bool isNumeric(string input);
//
//// extras
//bool toInteger(string* input, int* valueholder);

int main() {

	Menu mainmenu;
	mainmenu.header = "------ Welcome to Event Management System ------";
	mainmenu.addOption("Login");
	mainmenu.addOption("Register");
	mainmenu.addOption("Exit");
	//mainmenu.addOption("CONTOH");

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
		case 4:
			display();
		}
	}
}

void roleMenu() {
	Menu roleMenu;
	roleMenu.addOption("Login as admin");
	roleMenu.addOption("Login as client");
	roleMenu.addOption("Back");

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
			break;
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
				cout << "Password must be at least 6 character long";
				_getch();
			}
			else {
				newacc.clientPassword = tmpinput;
				rgMenu.setValue(4, newacc.clientPassword);
			}
			break;
		case 6:
			newacc.insert();
			cout << "Congratulations, your registration is successful";
			_getch();
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
		case 3:
			if (user.loginAdmin()) {
				home(user);
			}
			else {
				cout << "Invalid Login";
				_getch();
			}
			break;
		case 4:
			return;
			break;
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
		case 3:
			if (user.loginClient()) {
				home(user);
			}
			else {
				cout << "Invalid Login";
				_getch();
			}
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}


void home(admin user) {
	Menu homeMenu;
	homeMenu.header = "VIEW ONLY";
	homeMenu.addOption("Event Type");
	homeMenu.addOption("Event Rate");
	homeMenu.addOption("Monthly Report");
	homeMenu.addOption("Back");


	while (1) {
		switch (homeMenu.prompt())
		{
		case 1:
			//eventType();
			break;
		case 2:
			//eventRate();
			break;
		case 3:
			//monthlyReport();
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}

void home(client user) {
	Menu homeMenu;
	homeMenu.addOption("Register Event");
	homeMenu.addOption("Update Event");
	homeMenu.addOption("Rate Event");
	homeMenu.addOption("Delete Event");
	homeMenu.addOption("Payment Event");
	homeMenu.addOption("Back");

	while (1) {
		homeMenu.header = "Welcome " + user.clientUsername;
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
			break;
		default:
			break;
		}
	}
}

void registerEvent(client user) {

	Menu registerEvent;
	registerEvent.header = "--------- EVENT LIST ---------";
	registerEvent.addOption("Search Event");
	registerEvent.addOption("Back");

	while (1) {
		switch (registerEvent.prompt())
		{
		case 1:
			cout << " BIRTHDAY PARTY, ENGAGEMENT PARTY ";
			cout << " Insert Event Category : ";
			break;
		case 2:
			return;
			break;
		default:
			break;
		}
	}
}

void updateEvent(client user) {
	Menu updateEvent;
	updateEvent.addOption("Back");

	while (1) {
		switch (updateEvent.prompt())
		{
		case 1:
			return;
			break;
		default:
			break;
		}
	}
}

void rateEvent(client user) {
	Menu rateEvent;
	rateEvent.addOption("Star (1-5):");
	rateEvent.addOption("Comment:");
	rateEvent.addOption("Done");
	rateEvent.addOption("Back");

	while (1) {
		switch (rateEvent.prompt())
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}

void deleteEvent(client user) {
	Menu deleteEvent;
	deleteEvent.addOption("Are you sure to cancel the booking ?");
	deleteEvent.addOption("Back");

	while (1) {
		switch (deleteEvent.prompt())
		{
		case 1:
			break;
		case 2:
			return;
			break;
		default:
			break;
		}
	}
}

void paymentEvent(client user) {
	Menu paymentEvent;
	paymentEvent.addOption(".");
	paymentEvent.addOption("Back");

	while (1) {
		switch (paymentEvent.prompt())
		{
		case 1:
			break;
		case 2:
			return;
			break;
		default:
			break;
		}
	}
}

void display() {
	cout << "Hello world";
}
