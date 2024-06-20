#include "client.h"
#include <ctime>
#include "DBConnection.h" 
using namespace std;

client::client() {
	//initialize
	clientID = 0;
	clientName = "";
	clientPhoneNumber = "";
	clientUsername = "";
	clientPassword = "";
	clientEmail = "";
}
client::client(int clientID, std::string clientName, std::string clientPhoneNumber, std::string clientEmail, std::string clientUsername, std::string clientPassword) {
	this->clientID = clientID;
	this->clientName = clientName;
	this->clientPhoneNumber = clientPhoneNumber;
	this->clientEmail = clientEmail;
	this->clientUsername = clientUsername;
	this->clientPassword = clientPassword;
}
bool client::loginClient() {

	DBConnection db;
	db.prepareStatement("SELECT * FROM client WHERE clientUsername=? AND clientPassword=?");
	db.stmt->setString(1, clientUsername);
	db.stmt->setString(2, clientPassword);
	db.QueryResult();
	if (db.res->rowsCount() == 1) {
		while (db.res->next()) {
			clientID = db.res->getInt("clientID");
			clientName = db.res->getString("clientName");
			clientPhoneNumber = db.res->getString("clientPhoneNumber");
			clientEmail = db.res->getString("clientEmail");
			clientUsername = db.res->getString("clientUsername");
			clientPassword = db.res->getString("clientPassword");
		}
		db.~DBConnection();
		return true;
	}
	else {

		db.~DBConnection();
		return false;
	}
}
void client::insert() {

	// Nanti untuk client, kau tukar query dia ikut attribute dalam database

	DBConnection db;//instantiate
	db.prepareStatement("Insert into client (clientName,clientPhoneNumber,clientEmail,clientUsername,clientPassword) VALUES (?,?,?,?,?)"); // <-- Ni nama dia query
	db.stmt->setString(1, clientName);
	db.stmt->setString(2, clientPhoneNumber);
	db.stmt->setString(3, clientEmail);
	db.stmt->setString(4, clientUsername);
	db.stmt->setString(5, clientPassword);
	db.QueryStatement();
	db.~DBConnection();
}
void client::update() {

	DBConnection db;
	db.prepareStatement("UPDATE client SET clientName=?, clientPhoneNumber=?, clientEmail=?, clientUsername=?, clientPassword=?, WHERE clientID=?");
	db.stmt->setString(1, clientName);
	db.stmt->setString(2, clientPhoneNumber);
	db.stmt->setString(3, clientEmail);
	db.stmt->setString(4, clientUsername);
	db.stmt->setString(5, clientPassword);
	db.stmt->setInt(6, clientID);
	db.QueryStatement();
	db.~DBConnection();

}
void client::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM client WHERE clientID=?");
	db.stmt->setInt(1, clientID);
	db.QueryStatement();
	db.~DBConnection();
}

client::~client() {

}
