#pragma once
#ifndef client_H
#define client_H

#include <string>

class client
{
public://access specifier
	int clientID; //numerical attributes
	std::string clientName, clientPhoneNumber, clientEmail, clientUsername, clientPassword; // text attributes


	client(); // constructor method
	client(int clientID, std::string clientName, std::string clientPhoneNumber, std::string clientEmail, std::string clienUsername, std::string clientPassword);

	bool loginClient();
	void insert();
	void update();
	void remove();

	~client(); //destructor method


	static client older(client a, client b);


};

#endif