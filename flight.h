/*
 *  flight.h
 *  ENSF 337 - Spring 2020 Final Project
 *  Created by Risat Haque
 *  Date: 6/14/2020
 */
 
 //This file is only for the Flight Data

#ifndef RST
#define RST

#include "passenger.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

typedef vector< vector<Passenger> > matrix; 

class Flight{
    
private:
    string flightnumber;
	int totalRows;
	int seatsPerRow;
	matrix m; // a vector matrix of type passenger
    
	//HELPER FUNCTIONS
	string trimTrailingString(string& s);
		//REQUIRES:
		//A string with size > 0
		//PROMISES:
		//removes all the trailing spaces (' ') and returns the string
	string trimLeadingString(string& s);
		//REQUIRES:
		//A string with size > 0
		//PROMISES:
		//removes all the leading spaces (' ') and returns the string
	string onlyNumbers(string& s); //returns a string with ONLY numbers
		//REQUIRES:
		//A string with size > 0
		//PROMISES:
		//removes everything but the numbers in the string and returns the string
	
public:
    Flight();
		//PROMISES:
		//Constructor sets all values to 0
	Flight(const string flightnumber, const int totalRows, const int seatsPerRow);
		//REQUIRES:
		//a string with size > 0 as a flightnumber, and 2 ints of the total rows on the plane, and seats per row
		//PROMISES:
		//sets the flightnumber, total number of rows and seats per rows in the private variables of the object
	
	
	Flight& operator = (const Flight& rhs);
		//REQUIRES:
		//a reference to an object of class Flight utilizing the = operator to copy its content into the flight on the left side of the = sign
		//PROMISES:
		//Copies all content from rhs to this 
	
	~Flight();
	
	void set_flightnumber(const string m);
		//REQUIRES:
		//a string with size > 0 as a flightnumber
		//PROMISES:
		//sets the flightnumber in the private variable of the  object
	void set_totalRows(const int m);
		//REQUIRES:
		//an int for total rows in the matrix
		//PROMISES:
		//sets the total rows in the private variable of the object
	void set_seatsPerRow(const int m);
		//REQUIRES:
		//an int for seatsPerRow in the matrix
		//PROMISES:
		//sets the seatsPerRowin the private variable of the object

	void populate_flight_from_file(string file_address);
	

	void addPassengers_file(string fName, string lName, string phoneNumber, string row, string seat, string id);
		//REQUIRES:
		//a series of seperate strings as Fname, lName, phonenumber, row, seat and id with no leading or trailing spaces (with all string size > 0)
		//PROMISES:
		//Adds the passenger data in the vector matrix according to the location of where they are sitting

	
	void showSeatMap();
		//PROMISES:
		//Displays an organized seat map with all the rows and collumns (as A,B,C,D...). If a passenger sits at a seat,
		//it labelled with X
	void displayPassengerInformation();
		//PROMISES:
		//Shows in an organized manner all the passengers with their first name, last name, phone number, 
		//seat location and id on the console.
	void addPassenger();
		//PROMISES:
		//To ask the user to add a passenger with input strings as first name, last name, id, phonenumber and seat location.
		//If all of the following conditions are met, the passenger is added into the vector matrix based on seat location:
		//All inputs are valid, seat is not out of bounds, seat is not occupied, phonenumber is 10 digits, id is not being
		//used by another user.
		//If any of these are invalid, the user will be asked to either try again or return to menu
	void removePassenger(string id);
		//REQUIRES:
		//a string with size > 0 to represent an id of  passenger
		//PROMISES:
		//Looks through the vector matrix to remove the passenger with that iD.
		//If the passenger does not exist, an appropriete message will be 
		//displayed that prompts them to return back to the menu
	
	void saveData();
		//PROMISES:
		//Will open the same text file (for input) to output all the passenger data.
		//This includes their first name, last name, id, phonenumber and seat location.
		//The formating MUST be consistent with the original file
		//On the first line of the file, flight information such as flight number
		//total number of rows, and seats per row must be provided
		//To save the data, you must access each passenger information using the 
		//vector matrix
	int checkPassengersFileValidity(string fName, string lName, string seat, string row, string id);
		//REQUIRES:
		//a series of seperate strings as Fname, lName, phonenumber, row, seat and id with no leading or trailing spaces (with all string size > 0)
		//PROMISES:
		//To check if 2 passengers with the same id exist, or if 2 people are occuping the same seat
		//If this is the case 0 is returned and an appropriete message is displayed, if everything is fine 1 is returned. 

		
};

#endif
