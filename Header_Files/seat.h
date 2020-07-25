/*
 *  seat.h
 *  ENSF 337 - Spring 2020 Final Project
 *  Created by Risat Haque
 *  Date: 6/14/2020
 */
 
 //This file is only for the seat Data

#ifndef SEA
#define SEA

class Seat{    
private:
	//Basic Passenger Information
	string row;
	string seatLetter;
		
public:
	//Constructors/Destructors
	Seat();
	//PROMISES:
	//sets the row and seatLetter to ""
	~Seat();
			
	
	//Setter and Getter Functions
    string get_row() const{return row;}
	//PROMISES:
	//returns the row of the object as a string
	void set_row(const string m);
	//REQUIRES:
	//A string with size > 0
	//PROMISES:
	//sets the objects row to the one sent by the arguement
	
	string get_seatLetter() const{return seatLetter;}
	//PROMISES:
	//returns the seatLetter off the object as a string
	void set_seatLetter(const string m);
	//REQUIRES:
	//A string with size > 0
	//PROMISES:
	//sets the objects setLetter to the one sent by the arguement
	
 
};

#endif

