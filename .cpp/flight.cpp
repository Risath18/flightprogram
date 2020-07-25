/*
 *  flight.cpp
 *  ENSF 337 - Spring 2020 Final Project
 *  Created by Risat Haque
 *  Date: 6/14/2020
 */
 

//#include "flight.h"

//#include "flightprog.cpp"
#include "flight.h"
 
#include <iostream>

#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

Flight::Flight(){
	flightnumber = "";
	totalRows = 0;
	seatsPerRow = 0;

}
Flight::Flight(const string flightnumber, const int totalRows, const int seatsPerRow){
	this->flightnumber = flightnumber;
	this->totalRows= totalRows;
	this->seatsPerRow = seatsPerRow;
	
	m.resize(totalRows);
	for(int  j =0; j<totalRows; j++){
		m.at(j).resize(seatsPerRow);
	}
	for( int j = 0; j<totalRows; j++){
		for( int k = 0; k<seatsPerRow; k++){
			m[j][k].set_fName("");
			m[j][k].set_lName("");
			m[j][k].set_phoneNumber("");
			m[j][k].set_id("");
			m[j][k].set_seat("","");
		}
	}
    
}

Flight::~Flight() {
}

void Flight::set_totalRows(const int m){
	totalRows = m;
}

void Flight::set_seatsPerRow(const int m){
	seatsPerRow = m;
}


Flight& Flight::operator = (const Flight& rhs){
	if(this!=&rhs){
		 this->totalRows=rhs.totalRows;
		 this->seatsPerRow=rhs.seatsPerRow;
		 this->flightnumber=rhs.flightnumber;
		 this->m = rhs.m;
	}
	return *this;
}


void Flight::addPassenger(){ //matrx& m, string lName, int phoneNumber, int row, char seat, int id){
		while(1){
			int isValid  = 1;
			string fName = "";
			string lName = "";
			string phoneNumber = "";
			string row ="";
			string seat ="";
			string id = "";
	
			cout << "\nPlease enter the passenger ID: ";
			getline(cin, id, '\n');
			
			if(id.size()==0){
				cout << "\nWoops, you made a mistake! You will be returned\n";
				return;
			}

			id = trimTrailingString(id);
			id = trimLeadingString(id);
			id = onlyNumbers(id);
			id.resize(5);

			cout << "Please enter the passenger First Name: ";
			getline(cin, fName, '\n');
			
			if(fName.size()==0){
				cout << "\nWoops, you made a mistake! You will be returned\n";
				return;
			}
			
			fName = trimTrailingString(fName);
			fName = trimLeadingString(fName);
		
			cout << "Please enter the passenger Last Name: ";
			getline(cin, lName, '\n');
			
			if(lName.size()==0){
				cout << "\nWoops, you made a mistake! You will be returned\n";
				return;
			}
			
			lName = trimTrailingString(lName);
			lName = trimLeadingString(lName);
			
		
			cout << "Please enter the passenger Phone Number: ";
			getline(cin, phoneNumber, '\n');
			
			if(phoneNumber.size()==0){
				cout << "\nWoops, you made a mistake! You will be returned\n";
				return;
			}
			
			phoneNumber = trimTrailingString(phoneNumber);
			phoneNumber = trimLeadingString(phoneNumber);
			phoneNumber = onlyNumbers(phoneNumber);
			
	
			cout << "Enter the passenger's desired row: ";
			getline(cin, row, '\n');
			if(row.size()==0){
				cout << "\nWoops, you made a mistake! You will be returned\n";
				return;
			}		
			row = trimTrailingString(row);
			row = trimLeadingString(row);
			row = onlyNumbers(row);
			
		
			
			cout << "Enter the passenger's desired seat: ";
			getline(cin, seat, '\n');
			if(seat.size()==0){
				cout << "\nWoops, you made a mistake! You will be returned\n";
				return;
			}
				
			seat = trimTrailingString(seat);
			seat = trimLeadingString(seat);
			
		
			int seatInt= 0;
			int rowInt = 0;
			
			if(row== "" || isdigit(seat[0]) || seat.size()>1){
				cout << "Error in Seat Input! Try Again! " << endl;
				isValid = 0;
			}else{
	
	
		//Temporarily converting seat location to int to check avaliability and to set its correct index
			
				if(seat.at(0) >= 'a' && seat.at(0) <= 'z'){//converting string into int
					seatInt = int(seat.at(0))-97;
					seat[0] = int(seat.at(0))-32;
				} else
					seatInt = int(seat.at(0))-65;
				for( unsigned int c = 0 ; c<row.size(); c++){
					rowInt+=(int)row.at(c)-48;
					rowInt*= 10;
				}
				rowInt*=0.10; 
			}
			
			
			//-------------------------------------ERROR CHECKING FOR INPUT-----------------------------------
			if(rowInt>=totalRows || seatInt>=seatsPerRow){//testing to see if seat location is out of bounds
				cout << "\nSeat Location is out of range! Try Again!\n" << endl;
				rowInt = 0;
				seatInt = 0;
				isValid = 0;
			}
			int idExist = 0;
			for( int j = 0; j<totalRows; j++){
				for( int k = 0; k<seatsPerRow; k++){
					if(m[j][k].get_id() == id){//testing id id already exists
						idExist = 1;
						isValid = 0;
						break;
					}
				}
			}
			
			if(idExist ==1){
				cout << "\nThis ID already exists! Try Again!\n" << endl;
			}

			if(m[rowInt][seatInt].get_id()!=""){ //checking is seat is taken
				cout << "\nThis Seat is Taken! Try Again!\n" << endl;
					isValid = 0;

			}
			
			if(phoneNumber.size() != 10){//testing to see if seat location is out of bounds
				cout << "\nInvalid Phone Number! Try Again!\n" << endl;
				isValid = 0;
			}
			if(isValid != 0){
				//storing passenger information in apropriete location in flight storage (matrix)
				m[rowInt][seatInt].set_fName(fName);
				m[rowInt][seatInt].set_lName(lName);
			
				phoneNumber.insert(3, "-");
				phoneNumber.insert(7, "-");
				m[rowInt][seatInt].set_phoneNumber(phoneNumber);
				m[rowInt][seatInt].set_id(id);
				m[rowInt][seatInt].set_seat(row,seat);	
				cout << "\nSuccessfully added Passenger!\n" << endl;
				return;
			}
			
			string option;//allowing user to try again if needed
			cout << "\nWould you like to try again or exit? (Press 1 for try again, 0 for exit): ";
			getline(cin, option, '\n');
			option = trimTrailingString(option);
			option = trimLeadingString(option);
			option = onlyNumbers(option);
			if(option == "0"){
				cout <<"\nReturning to Menu Now....\n";
				return;
			}else if(option == "1"){
				cout <<"\nAdd Passenger:\n";
			}else{
				cout <<"\nInvalid Ouput, you will now return to menu!\n";
				return;
			}
		}
}

void Flight::removePassenger(string id){
	for( int j = 0; j<totalRows; j++){
		for( int k = 0; k<seatsPerRow; k++){
			if(m[j][k].get_id() == id){
				m[j][k].publicDestroy();
			return;
			}
		}
	}
	cout << "Passenger does not exist or has already been deleted!" << endl;

	return;
}

void Flight::displayPassengerInformation(){
	
	cout << "\n" << setw(20) << "First Name" << setw(20) <<"Last Name" << setw(12+8) << "Phone Number" << setw(2+8) << "Row" << setw(1+5) << "Seat" << setw(10+5) << "Id Number";
	cout << "\n   -----------------------------------------------------------------------------------------";
	for(int i = 0; i<totalRows; i++){
		for(int j = 0; j<seatsPerRow; j++){
			if(m[i][j].get_id() != ""){
				cout << "\n" << setw(20) << m[i][j].get_fName() << setw(20) <<m[i][j].get_lName()<< setw(12+8) << m[i][j].get_phoneNumber() << setw(2+8) << i << setw(1+5) << char(j+65) << setw(10+5) << m[i][j].get_id();
				cout << "\n   -----------------------------------------------------------------------------------------";
			}	
		}
	}
	cout<<endl;
	return;
}


void Flight::showSeatMap(){
	int seatsPerRow = this->seatsPerRow;
	cout << "             Aircraft Seat Map             \n"<<"        ";

	for( int s = 0; s<seatsPerRow; s++){
		cout << (char)(s + 65) << "     ";
	}
	cout << "\n";
	string bar = "+-----";
	for(unsigned int i = 0; i<m.size(); i++){
		cout <<"     ";
		for( int u = 0; u<seatsPerRow; u++){ 
			cout << bar;
		}
		cout << "+\n  " << setw(2) << i << " |  ";
		for(unsigned int j = 0; j<m[i].size(); j++){
			if(m[i][j].get_id() != "")
				cout << setw(1) << "X" << "  |  ";
			else
				cout << setw(1) << " " << "  |  ";
		}
	cout << endl;
	}
	cout <<"     ";
	for( int u = 0; u<seatsPerRow; u++){ //creating bottom bar
			cout << bar;
		}
	cout << "+" <<endl;	
	return;
}


void Flight::addPassengers_file(string fName, string lName, string phoneNumber, string row, string seat, string id){
	
	//Determine Location in Matrix based on Seat Value
	int seatInt= 0;
	int rowInt = 0;

	if(seat.at(0) >= 'a' && seat.at(0) <= 'z'){//converting string into int
		seatInt = int(seat.at(0))-97;
		seat[0] = int(seat.at(0))-32;
	}
	else
		seatInt = int(seat.at(0))-65;
	for( unsigned int c = 0 ; c<row.size(); c++){
		rowInt+=(int)row.at(c)-48;
		rowInt*= 10;
	}
	rowInt*=0.10; 


	if(checkPassengersFileValidity(fName, lName, seat,row, id)){ //if passenger is valid, it is added to system
		m[rowInt][seatInt].set_fName(fName);
		m[rowInt][seatInt].set_lName(lName);
		m[rowInt][seatInt].set_phoneNumber(phoneNumber);
		m[rowInt][seatInt].set_id(id);
		m[rowInt][seatInt].set_seat(row,seat);		
	}
	
	return;
}

int Flight::checkPassengersFileValidity(string fName, string lName, string seat, string row, string id){ //checks to see if errors exist in file

	for( int j = 0; j<totalRows; j++){
		for( int k = 0; k<seatsPerRow; k++){
			if(m[j][k].get_id() == id){
				cout<< "\nAtleast 2 individuals have the same id! " << fName << " " << lName << " will be removed!" <<endl;
				return 0;
			}
				if(row+seat == m[j][k].get_seat()){
					cout<< "\nAtleast 2 individuals have the same seat! " << fName << " " << lName << " will be removed!" <<endl;
				return 0;
			}
		}
	}
	return 1;
}

void Flight::saveData(){
	ofstream out_stream;
	
	out_stream.open("flight_info.txt");
	
	if(out_stream.fail()){
		cout<< "Error opening file... \n Saving Data Failed!" <<endl;
	}
	
	string flightNumber_O =  flightnumber;

	flightNumber_O.resize(10);

	out_stream << flightnumber << " " << totalRows <<" "<< seatsPerRow << '\n';
	
	string fName_O;
	string lName_O; 
	string phoneNumber_O;
	string location_O;
	string id_O;
	
	for(unsigned int i = 0; i<m.size(); i++){
		for(unsigned int j = 0; j<m[i].size(); j++){
			if(m[i][j].get_id() != ""){ //checks to see if seat is occupied, if it is, its data is collected and 
				
				 fName_O = m[i][j].get_fName();
				 lName_O = m[i][j].get_lName();
				 phoneNumber_O = m[i][j].get_phoneNumber();
				 location_O = m[i][j].get_seat();
				 id_O = m[i][j].get_id();
				
				fName_O.resize(20, ' ');
				lName_O.resize(20,' ');
				phoneNumber_O.resize(20,' ');
				location_O.resize(4,' ');
				id_O.resize(5,' ');
				
				out_stream << fName_O << lName_O << phoneNumber_O <<location_O << id_O << '\n';
			}
		}
	}
	out_stream.close();
	return;
}


string Flight::trimTrailingString(string& s){//removes any trailing spaces
	while((s.at(s.size()-1) == ' '|| s.at(s.size()-1) == '\n') && s.size()> 0)
		s.pop_back();
	return s;	
}

string Flight::trimLeadingString(string& s){ //removes any leading spaces
	size_t start = s.find_first_not_of(" \n");
	return s.substr(start);
}

string Flight::onlyNumbers(string& s){ //returns a string with ONLY numbers
	for(unsigned int i=0; i< s.size(); i++){
		if(!isdigit(s.at(i))){
			s.erase(i,1);
			i--;
		}
	}
	return s;
}


