/*
 * PhoneBook.h
 *
 *  Created on: Oct 1, 2018
 *      Author: Alex
 */

#ifndef CONTACT_H_
#define CONTACT_H_
#include<iostream>
using namespace std;

class Contact {
public:
	string fName, lName;
	int pNum;

	Contact(){}
	Contact(string firstName, string lastName, int phoneNumber){
		this->fName = firstName;
		this->lName = lastName;
		this->pNum = phoneNumber;
	}


	const string& getFirstName() const {
		return fName;
	}

	void setFirstName(const string& name) {
		fName = name;
	}

	const string& getLastName() const {
		return lName;
	}

	void setLastName(const string& name) {
		lName = name;
	}

	int getNum() const {
		return pNum;
	}

	void setNum(int num) {
		pNum = num;
	}


};


#endif /* CONTACT_H_ */
