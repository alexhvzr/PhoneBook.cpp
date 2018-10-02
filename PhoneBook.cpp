//============================================================================
// fName        : HelloPleaseWork.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include <fstream>
#include "Contact.h"

int IndexTotal = 0;
using namespace std;

class PhoneBook {
public:
	Contact *contact = new Contact[1000000];
	void runProgram();
	void add();
	void upper(string&);
	void search();
	void del();
	void list();
	void quit();

};

void PhoneBook::add() {
	string tempFirst, tempLast;
	cout << "Enter First Name: ";
	cin.ignore();
	//getline(cin, contact[IndexTotal].fName);
	getline(cin, tempFirst);
	upper(tempFirst);
	contact[IndexTotal].fName = tempFirst;
	cout << "Enter Last Name: ";
	getline(cin, tempLast);
	upper(tempLast);
	contact[IndexTotal].lName = tempLast;
	cout << "Enter a phone number: ";
	cin >> contact[IndexTotal].pNum;
	IndexTotal++;
}
void PhoneBook::upper(string &str) {
	for (int i = 0; i < str.length(); i++){
		str[i] = toupper(str[i]);
	}
}
void PhoneBook::search() {
	string fn, ln;
	cin.ignore();
	cout << "Enter a first name: ";
	cin >> fn;
	cout << "Enter a last name: ";
	cin >> ln;
	upper(fn);
	upper(ln);
	for (int i = 0; i < IndexTotal; i++) {
		if (fn == contact[i].getFirstName() && ln == contact[i].getLastName()) {
			cout << contact[i].getNum() << endl;
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
	for (int i = 0; i < IndexTotal; i++) {
		if (fn == contact[i].getFirstName() && ln == contact[i].getLastName()) {
			temp = i;
			break;
		}
	}
	for (int x = temp + 1; x < IndexTotal; x++) {
	        contact[x - 1] = contact[x];
	    }
	    IndexTotal--;
}
void PhoneBook::list() {

	for (int index = 0; index < IndexTotal; index++) {
		cout << contact[index].getFirstName() << " "
				<< contact[index].getLastName() << " "
				<< contact[index].getNum() << " " << endl;
	}
}
void PhoneBook::quit() {
	cout << "Goodbye!" << endl;
}
void PhoneBook::runProgram() {
	char task;
	PhoneBook a;
	ifstream inFile;
	inFile.open("phonebook.txt");
	if (!inFile) {
		cout << "Error opening the file." << endl;
	}
	while (inFile.good()) {
		inFile >> a.contact[IndexTotal].fName >> a.contact[IndexTotal].lName
				>> a.contact[IndexTotal].pNum;
		IndexTotal++;
	}
	inFile.close();

	cout << "Phone book operations (Please select one):" << endl;
	while (!((task == 'Q') || (task == 'q'))) {
		cout << "A(Add) | S(Search)  D(Delete) |L(List) | Q(Quit): ";
		cin >> task;
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
		default:
			cout << "Invalid Selection. Please try Again." << endl;
		}
	}

}

int main() {
	PhoneBook b;
	b.runProgram();
	return 0;
}
