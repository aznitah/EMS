#pragma once
#ifndef event_H
#define event_H
#include <vector>
#include <string>

class event
{
public://access specifier
	int eventID; //numerical attributes
	std::string eventName, eventDescription, eventDate, eventVenue, eventPrice, eventCapacity, venueID; // text attributes


	event(); // constructor method
	event(int eventID, std::string eventName, std::string eventDescription, std::string eventDate, std::string eventVenue, 
		std::string eventPrice, std::string eventCapacity, std::string venueID);

	~event(); //destructor method


	static event older(event a, event b);
	static std::vector<event> search();

};

#endif