#pragma once
#ifndef admin_H
#define admin_H

#include <string>

class admin
{
public://access specifier
	int adminID; //numerical attributes
	std::string adminName, adminPhoneNumber, adminEmail, adminUsername, adminPassword; // text attributes


	admin(); // constructor method
	admin(int clientID, std::string clientName, std::string clientPhoneNumber, std::string clientEmail, std::string clienUsername, std::string clientPassword);

	bool loginAdmin();
	void insert();
	void update();
	void remove();

	~admin(); //destructor method


	static admin older(admin a, admin b);


};

#endif