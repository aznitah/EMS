#include "event.h"
#include <ctime>
#include <vector>
#include "DBConnection.h" 
using namespace std;

event::event() {
	//initialize
	eventID = 0;
	eventName = "";
	eventDescription = "";
	eventDate = "";
	eventVenue = "";
	eventPrice = "";
	eventCapacity = "";
	venueID = "";
}
event::event(int eventID, std::string eventName, std::string eventDescription, std::string eventDate, 
	std::string eventVenue, std::string eventPrice, std::string eventCapacity, std::string venueID) {

	this->eventID = eventID;
	this->eventName = eventName;
	this->eventDescription = eventDescription;
	this->eventDate = eventDate;
	this->eventVenue = eventVenue;
	this->eventPrice = eventPrice;
	this->eventCapacity = eventCapacity;
	this->venueID = venueID;
}

event::~event() {

}

vector<event> event::search()
{
	// Nanti untuk client, kau tukar query dia ikut attribute dalam database

	DBConnection db;//instantiate
	db.prepareStatement("Insert into event (eventID, eventName, eventDescription, eventDate, eventDate, eventVenue, eventPrice, eventCapacity, venueID) VALUES (?,?,?,?,?)"); // <-- Ni nama dia query

	vector<event> event;

	db.QueryStatement();
	db.~DBConnection();

}
