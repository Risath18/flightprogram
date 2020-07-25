/*
 *  passenger.h
 *  ENSF 337 - Spring 2020 Final Project
 *  Created by Risat Haque
 *  Date: 6/14/2020
 */
 
 //This file is only for the Passenger Data

#ifndef XYZ
#define XYZ
//#include "flight.cpp"
//#include "passenger.cpp"
#include <vector>
#include <iomanip>
#include <string> 

#include "seat.h"

using namespace std;

class Passenger{    
private:
	//Basic Passenger Information
	string fName;
	string lName;
	string phoneNumber;
	string id;
	Seat seat;
	

public:
	//Constructors/Destructors
	Passenger();
	//PROMISES:
	//sets the first name, last name, phonenumber, id and seat object as ""
	~Passenger();


	void publicDestroy();
	//PROMISES:
	//to set all the data of the passenger object to "" to suggest it no longer
	//exists
		
	
	//Setter and Getter Functions
    string get_fName() const{return fName;}
	//PROMISES:
	//returns the first name if the object as a string
	void set_fName(const string m);
	//REQUIRES:
	//A string with size > 0
	//PROMISES:
	//sets the objects first name to one sent of the arguement
	
	string get_lName() const{return lName;}
	//PROMISES:
	//returns the last name of the object as a string
	void set_lName(const string m);
	//REQUIRES:
	//A string with size > 0
	//PROMISES:
	//sets the objects last name to one sent in the arguement
	
	
	string get_phoneNumber() const{return phoneNumber;}
	//PROMISES:
	//returns the phone number of the object as a string
	void set_phoneNumber (const string phoneNumber);
	//REQUIRES:
	//A string with size > 0
	//PROMISES:
	//sets the objects phone number to one sent in the arguement
	
	void set_seat(const string row, const string seat);
	//REQUIRES:
	//A string with size > 0
	//PROMISES:
	//sets the objects seat by calling functions in the object seat
	//so the row and seatLetter can be set
	
	string get_seat();
	//PROMISES:
	//returns a string with the concatination of row and seatLetter
	//by calling functions in the respective object of seat as a string
	
	string get_id() const{return id;}
	//PROMISES:
	//returns the id of the object as a string
	void set_id(const string m);
	//REQUIRES:
	//A string with size > 0
	//PROMISES:
	//sets the id of the object from the one sent as an arguement
	
 
};

#endif

