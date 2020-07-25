/*
 *  flightprog.cpp
 *  ENSF 337 - Spring 2020 Final Project
 *  Created by Risat Haque
 *  Date: 6/14/2020
 */
 
#include <iostream>
#include <assert.h>
using namespace std;
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>



#include "seat.h"
#include "passenger.h"
#include "flight.h"

#include "flight.cpp"
#include "passenger.cpp"
#include "seat.cpp"

void pressEnter();
	//PROMISES:
	//to display an appropriete message for user to press enter
	//checks if they have pressed a button to continue
string trimLeadingString(string& s);
	//REQUIRES:
		//A string with size > 0
		//PROMISES:
		//removes all the trailing spaces (' ') and returns the string
string trimTrailingString(string& s);
//REQUIRES:
		//A string with size > 0
		//PROMISES:
		//removes all the leading spaces (' ') and returns the string
string onlyNumbers(string& s);
	//REQUIRES:
	//A string with size > 0
	//PROMISES:
	//removes everything but the numbers in the string and returns the string




string intToString(int s);
	//REQUIRES:
	//An a valid int
	//PROMISES:
	//returns a string by based on the int values. For example:
	//if the integer is 43, the string is "43"
Flight populate_flight_from_file(string file_address);
	//REQUIRES:
	//A string with size > 0. The string should be the title of a txt file located in a folder with all the rest of the files
	//PROMISES:
	//returns as type Flight with a matrix with data such as flight number, total rows, total seats per row
	//and all data related to passenger. This is achieved through reading the file row by row until the end of the file
void menu();
	//PROMISES:
	//displays a menu on the screen with options such as: view seat map, view passenger information
	//add passenger, remove pasenger, save data and exit.


int main(){
	Flight f;
	f = populate_flight_from_file("flight_info.txt");
	
	//Program Title
		cout << "\nVersion: 1.0";
		cout << "\nTerm Project - Flight Management Program in C++";
		cout << "\nProduced by: Risat Haque\n";
		
		//Main area input area for menu
	while(1){
		pressEnter();
		menu();
		string option;
		string idOption;
		
		getline(cin, option, '\n');

		if("1" == option){ //Display Flight Seat Map
			f.showSeatMap();
		}else if("2" == option){ //Display Passenger Information
			f.displayPassengerInformation();
		}else if("3" == option){ //Add a new Passenger
			f.addPassenger();
		}else if("4" == option){ //Remove an existing Passenger
				cout << "\nEnter the Passenger id: ";
				getline(cin, idOption, '\n');
				f.removePassenger(idOption);
		}else if("5" == option){ //Save Data
			cout << "\n Saving Data..." <<endl; 
			f.saveData();
		}else if("6" == option){ // Quit
			cout << "\nNow Exiting..." <<endl; 
			exit(1);
		}else
			cout <<"\nError in Input" <<endl;
		
	}
	return 0;
}

void menu(){
		cout << "\n Please select one the following options:\n";
		cout << " 1. Display Flight Seat Map\n";
		cout << " 2. Display Passengers Information\n";
		cout << " 3. Add a New Passenger\n";
		cout << " 4. Remove an Existing Passenger\n";
		cout << " 5. Save Data\n";
		cout << " 6. Quit\n";
		
		cout <<"\nEnter your choice: (1, 2, 3, 4, 5, or 6): ";
	
}

void pressEnter(){
	cout << "\n<<< Press Return to Continue>>>\n";
	cin.get();
}


string trimTrailingString(string& s){
	while((s.at(s.size()-1) == ' '|| s.at(s.size()-1) == '\n') && s.size()> 0)
		s.pop_back();
	return s;	
}

string trimLeadingString(string& s){
	size_t start = s.find_first_not_of(" \n");
	return s.substr(start);
}

string onlyNumbers(string& s){ //returns a string with ONLY numbers
	for(unsigned int i=0; i< s.size(); i++){
		if(!isdigit(s.at(i))){
			s.erase(i,1);
			i--;
		}
	}
	return s;
}

Flight populate_flight_from_file(string file_address){
	ifstream in_stream;
	
	in_stream.open(file_address);
	
	if(in_stream.fail()){
		cout <<"Error opening file..." << endl;
		
		in_stream.clear();
		exit(1);
	}
	string flightnumberTEMP, totalRowsTEMP, seatsPerRowTEMP;
	in_stream >> flightnumberTEMP >> totalRowsTEMP >>seatsPerRowTEMP; //receiving flight information
	
	

	int totalSeatInt= 0;
	int seatsPerRowInt = 0;
	
	//Converting string to int
	for( unsigned int c = 0 ; c<seatsPerRowTEMP.size(); c++){
		seatsPerRowInt+=(int)seatsPerRowTEMP.at(c)-48;
		seatsPerRowInt*= 10;
	}
	seatsPerRowInt*=0.10;
	
	for( unsigned int c = 0 ; c<totalRowsTEMP.size(); c++){
		totalSeatInt+=(int)totalRowsTEMP.at(c)-48;
		totalSeatInt*= 10;
	}
	totalSeatInt*=0.10;

	// Creating a new flip with a coonstructer using values from the first row of the file
	Flight temp(flightnumberTEMP, totalSeatInt, seatsPerRowInt);

	string tempPerson;
	while(!in_stream.eof()){
		string fName, lName, phoneNumber, location, id, row,seat; //setting temporary values to recieve
		getline(in_stream, tempPerson);
		if(tempPerson.size() >0){ //receiving different parts of the input string by line
		  fName = tempPerson.substr(0,20);
		  lName = tempPerson.substr(20,20);
		  phoneNumber = tempPerson.substr(40,20);
		  location = tempPerson.substr(60,4);
		  id = tempPerson.substr(64,5); 
		 
		  row = location[0]; //determing the row and seat(A,B,C,D)
		  if(isdigit(location[1])){
			  row+=location[1];
			  seat = location[2];
		  }else
			  seat=location[1];
		  //triming down spaces of all strings
		  fName = trimLeadingString(fName);
		  fName = trimTrailingString(fName);

		  lName = trimLeadingString(lName);
		  lName = trimTrailingString(lName);
		  		  
		  phoneNumber = trimLeadingString(phoneNumber);
		  phoneNumber = trimTrailingString(phoneNumber);
		  
		  row = trimLeadingString(row);
		  row = trimTrailingString(row);
		  
		  seat = trimLeadingString(seat);
		  seat = trimTrailingString(seat);
		  
		  id = trimLeadingString(id);
		  id = trimTrailingString(id);

		 temp.addPassengers_file( fName,  lName,  phoneNumber,  row,  seat,  id);
		}
	}
	cout <<endl;

	in_stream.close();
	return temp;
}

