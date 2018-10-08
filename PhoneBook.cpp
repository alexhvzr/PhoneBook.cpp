//============================================================================
// fName        : HelloPleaseWork.cpp
// Author      : Alex van Zuiden-Rylander
// Version     : 1
// Copyright   : Your copyright notice
// Description : PhoneBook Assignment one
//============================================================================

#include <iostream>
#include<string>
#include <fstream>
#include "Contact.h"

int INDEX_TOTAL = 0;
using namespace std;
//creates my phone book class
class PhoneBook {

public:
	friend class Contact;
	Contact *contact = new Contact[1000000];
	void add();
	void upper(string&);
	void search();
	void del();
	void list();
	void quit();
	friend ostream& operator<<(ostream&, PhoneBook);

};

void PhoneBook::add() {
	string tempFirst, tempLast;
	cout << "Enter First Name: ";
	//ignored input from before so getline would work
	cin.ignore();
	getline(cin, tempFirst);
	//make it to upper case so my phone book will have the correct structure
	upper(tempFirst);
	//insert name into contact array
	contact[INDEX_TOTAL].fName = tempFirst;
	cout << "Enter Last Name: ";
	getline(cin, tempLast);
	upper(tempLast);
	contact[INDEX_TOTAL].lName = tempLast;
	cout << "Enter a phone number: ";
	cin >> contact[INDEX_TOTAL].pNum;
	//increase my index total so that if another is added it adds to the correct position
	INDEX_TOTAL++;
}
//method to convert a string into an upper case string
void PhoneBook::upper(string &str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
}
void PhoneBook::search() {
	// declare temp first and last name strings
	string fn, ln;
	cin.ignore();
	cout << "Enter a first name: ";
	cin >> fn;
	cout << "Enter a last name: ";
	cin >> ln;
	//convert first and last name to upper to search within contact array
	upper(fn);
	upper(ln);
	//finds where in the pointer array the name is and returns the person's phone number
	for (int i = 0; i < INDEX_TOTAL; i++) {
		if (fn == contact[i].getFirstName() && ln == contact[i].getLastName()) {
			cout << "Phone Number: " << contact[i].getNum() << endl;
			break;
		}
	}
}
void PhoneBook::del() {
	string fn, ln;
	int temp;
	cin.ignore();
	cout << "Enter a first name: ";
	cin >> fn;
	cout << "Enter a last name: ";
	cin >> ln;
	upper(fn);
	upper(ln);
	//essentially the same loop for search method, except this is just to get the index of the person
	for (int i = 0; i < INDEX_TOTAL; i++) {
		if (fn == contact[i].getFirstName() && ln == contact[i].getLastName()) {
			//delete contact[i];
			temp = i;
			break;
		}
	}
	//this method will start at the index, and reassign that value and all others after to the next value
	//essentially deleting the person from the array
	for (int x = temp + 1; x < INDEX_TOTAL; x++) {
		contact[x - 1] = contact[x];
	}
	INDEX_TOTAL--;
}
//overload this operator so that you can output the contact
ostream& operator<<(ostream& os, Contact index) {
	os << index.fName << " " << index.lName << " " << index.pNum;
	return os;
}
void PhoneBook::list() {
	//loops through the contact array and prints each persons name and number
	for (int index = 0; index < INDEX_TOTAL; index++) {
		//using overloaded operator
		cout << contact[index] << endl;
	}
}
//causes program to quit.
void PhoneBook::quit() {
	cout << "Goodbye!" << endl;
}
void runProgram(PhoneBook a) {
	char task;
	//create a file
	ifstream inFile;
	//open the file
	inFile.open("phonebook.txt");
	//checks to see if the file path works
	if (!inFile) {
		cout << "Error opening the file." << endl;
	}
	//while the file valid, read through it
	while (inFile.good()) {
		//take each given contact in the phonebook.txt and sort them into the contact array
		inFile >> a.contact[INDEX_TOTAL].fName >> a.contact[INDEX_TOTAL].lName
				>> a.contact[INDEX_TOTAL].pNum;
		//track your index so that you can insert at the end
		INDEX_TOTAL++;
	}
	//close the file you opened
	inFile.close();
	//"game" loop, this will continue running until q (quit) is pressed
	cout << "Phone book operations (Please select one):" << endl;
	while (!((task == 'Q') || (task == 'q'))) {
		cout << "A(Add) | S(Search)  D(Delete) |L(List) | Q(Quit): ";
		cin >> task;
		//switch case to see what character the user inputs
		switch (task) {
		case 'a':
		case 'A': {
			a.add();
		}
			break;
		case 's':
		case 'S': {
			a.search();
		}
			break;
		case 'd':
		case 'D': {
			a.del();
		}
			break;
		case 'l':
		case 'L': {
			a.list();
		}
			break;
		case 'q':
		case 'Q': {
			a.quit();
		}
			break;
			//default opperator will print error method if none of the cases are true
		default:
			cout << "Invalid Selection. Please try Again." << endl;
		}
	}

}

int main() {
	//create a phonebook and run the program on it!
	PhoneBook test;
	runProgram(test);
	return 0;
}
