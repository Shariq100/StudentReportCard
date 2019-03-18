#include <iostream>

#include "Person.h"

using namespace std;

//
//getter functions
//
void Person::setFirstName(string fname) {
	this->firstName = fname;
}

void Person::setLastName(string lname) {
	this->lastName = lname;
}

//
//setter functions
//
string Person::getFirstName() {
	return this->firstName;
}
string Person::getLastName() {
	return this->lastName;
}