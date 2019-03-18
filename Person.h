#pragma once
#include <iostream>

using namespace std;

class Person {
private:
protected:
	string firstName, lastName;
public:
	void setFirstName(string fname);
	void setLastName(string lname);

	string getFirstName();
	string getLastName();
};
