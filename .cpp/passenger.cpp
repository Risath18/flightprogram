/*
 *  passenger.cpp
 *  ENSF 337 - Spring 2020 Final Project
 *  Created by Risat Haque
 *  Date: 6/14/2020
 */
 


#include "passenger.h"
#include <assert.h>
#include <iostream>
#include <iomanip>
using namespace std;


Passenger::Passenger(){
	 fName = "";
	 lName = "";
	 phoneNumber = "";
	 id= "";
	 seat.set_row("");
	 seat.set_seatLetter("");
	}

Passenger::~Passenger() {
}


void Passenger::set_fName(const string m){
	fName=m;
}

void Passenger::set_lName(const string m){
	lName =m;
}

void Passenger::set_phoneNumber(const string m){
	this->phoneNumber = m;
}


void Passenger::set_seat(const string row, const string seatLetter){
	seat.set_row(row);
	seat.set_seatLetter(seatLetter);
} 


string Passenger::get_seat(){
	string seatLetter = seat.get_seatLetter();
	string row = seat.get_row();
	return row+seatLetter;
} 


void Passenger::set_id(const string m){
	this->id = m;
}

void Passenger::publicDestroy(){
	 fName = "";
	 lName = "";
	 phoneNumber = "";
	 seat.set_row("");
	 seat.set_seatLetter("");
	 id="";
}
