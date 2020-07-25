/*
 *  seat.cpp
 *  ENSF 337 - Spring 2020 Final Project
 *  Created by Risat Haque
 *  Date: 6/14/2020
 */
 
#include "seat.h"


Seat::Seat(){
	 row = "";
	 seatLetter = "";
}


Seat::~Seat() {
}


void Seat::set_row(const string m){
	row=m;
}

void Seat::set_seatLetter(const string m){
	seatLetter =m;
}
