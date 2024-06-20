#include "admin.h"
#include <ctime>
#include "DBConnection.h" 
using namespace std;

admin::admin() {
	//initialize
	adminID = 0;
	adminName = "";
	adminPhoneNumber = "";
	adminUsername = "";
	adminPassword = "";
	adminEmail = "";
}
admin::admin(int adminID, std::string adminName, std::string adminPhoneNumber, std::string adminEmail, std::string adminUsername, std::string adminPassword) {
	this->adminID = adminID;
	this->adminName = adminName;
	this->adminPhoneNumber = adminPhoneNumber;
	this->adminEmail = adminEmail;
	this->adminUsername = adminUsername;
	this->adminPassword = adminPassword;
}
bool admin::loginAdmin() {

	DBConnection db;
	db.prepareStatement("SELECT * FROM admin WHERE adminUsername=? AND adminPassword=?");
	db.stmt->setString(1, adminUsername);
	db.stmt->setString(2, adminPassword);
	db.QueryResult();
	if (db.res->rowsCount() == 1) {
		while (db.res->next()) {
			adminID = db.res->getInt("adminID");
			adminName = db.res->getString("adminName");
			adminPhoneNumber = db.res->getString("adminPhoneNumber");
			adminEmail = db.res->getString("adminEmail");
			adminUsername = db.res->getString("adminUsername");
			adminPassword = db.res->getString("adminPassword");
		}
		db.~DBConnection();
		return true;
	}
	else {

		db.~DBConnection();
		return false;
	}
}
void admin::insert() {

	// Nanti untuk client, kau tukar query dia ikut attribute dalam database

	DBConnection db;//instantiate
	db.prepareStatement("Insert into admin (adminName,adminPhoneNumber,adminEmail,adminUsername,adminPassword) VALUES (?,?,?,?,?)"); // <-- Ni nama dia query
	db.stmt->setString(1, adminName);
	db.stmt->setString(2, adminPhoneNumber);
	db.stmt->setString(3, adminEmail);
	db.stmt->setString(4, adminUsername);
	db.stmt->setString(5, adminPassword);
	db.QueryStatement();
	db.~DBConnection();

}
void admin::update() {

	DBConnection db;
	db.prepareStatement("UPDATE admin SET adminName=?, adminPhoneNumber=?, adminEmail=?, adminUsername=?, adminPassword=?, WHERE adminID=?");
	db.stmt->setString(1, adminName);
	db.stmt->setString(2, adminPhoneNumber);
	db.stmt->setString(3, adminEmail);
	db.stmt->setString(4, adminUsername);
	db.stmt->setString(5, adminPassword);
	db.stmt->setInt(6, adminID);
	db.QueryStatement();
	db.~DBConnection();

}
void admin::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM account WHERE adminID=?");
	db.stmt->setInt(1, adminID);
	db.QueryStatement();
	db.~DBConnection();
}

admin::~admin() {

}
