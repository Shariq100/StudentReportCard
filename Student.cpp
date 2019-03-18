#include <iostream>
#include <vector>
#include <string>

#include "Person.h"
#include "Student.h"

using namespace std;

//
//Setter Functions
//
void Student::setStudentID(int id) {
	this->s_id = id;
}

void Student::setPhysicsMarks(int marks) {
	this->physics = marks;
}

void Student::setChemistryMarks(int marks) {
	this->chemistry = marks;
}

void Student::setMathsMarks(int marks) {
	this->maths = marks;
}

void Student::setEnglishMarks(int marks) {
	this->english = marks;
}

void Student::setCSMarks(int marks) {
	this->computerscience = marks;
}

//
//Getter Functions...
//
int Student::getstudentID() {
	return this->s_id;
}

int Student::getPhysicsMarks() {
	return this->physics;
}

int Student::getChemistryMarks() {
	return this->chemistry;
}

int Student::getMathsMarks() {
	return this->maths;
}

int Student::getEnglishMarks() {
	return this->english;
}

int Student::getCSMarks() {
	return this->computerscience;
}


//
//Create student report
//
void Student::createStudentReport(string fName, string lName, int id, int phys, int chem, int math, int eng, int cs) {
	this->firstName = fName;
	this->lastName = lName;
	this->s_id = id;
	this->physics = phys;
	this->chemistry = chem;
	this->maths = math;
	this->english = eng;
	this->computerscience = cs;
}


//
//Display Student information
//
void Student::displayStudentInfo() {
	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "ID: " << s_id <<endl;
	cout << "Physics: " << physics << endl;
	cout << "Chemistry: " << chemistry << endl;
	cout << "Maths: " << maths << endl;
	cout << "English " << english << endl;
	cout << "Computer Science " << computerscience << endl;
}


//
//Get exam avg of a student
//
double Student::getExamAvg() {
	return (chemistry + physics + maths + english + computerscience) / 5.0;
}
