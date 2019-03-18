#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Database.h"
#include "Person.h"
#include "Student.h"


//
//updateStudentDirectory
//
void Database::updateStudentsDirectory(Student s) {
	//check if the student already exist
	for (auto i : studentsDirectory)
	{
		if (i.getstudentID() == s.getstudentID()) { //check if it is already exist
			cout << "Student with the same ID already exist.  Unable to store in the directory" << endl;
			return;
		}
	}// end for loop

	//cout << "CHECKING BITCH" << endl;
	/*cout << s.getFirstName() << " " << s.getLastName() << " " << s.getstudentID() << " " << s.getPhysicsMarks() << " " << s.getChemistryMarks() << " " << s.getMathsMarks() << " " <<
		+ s.getEnglishMarks() << " " << s.getCSMarks() << endl;*/

	//if gets here, print the message, update the students record
	studentsDirectory.push_back(s);
	cout << "Successfully added student in the directory" << endl;
	return;
}


//
//Display in Descending order with Last name.
//If Last name are Same, then arrange in Ascending order with First ame
//
void Database::readAllStudentsRecord() {
	//check if database is empty
	if (studentsDirectory.empty()) {
		cout << "Database is empty.  No records found..." << endl;
		return;
	}


	//use built in sort function
	sort(studentsDirectory.begin(), studentsDirectory.end(), [&](Student s1, Student s2) {
		if (s1.getLastName() > s2.getLastName())
			return true;
		else if (s1.getLastName() < s2.getLastName())
			return false;
		else {
			if (s1.getFirstName() < s2.getFirstName())
				return true;
			else
				return false;
		}
	});

	for (auto s : studentsDirectory) {
		cout << s.getLastName() << ", " << s.getFirstName() << endl;
		cout << "ID: " << s.getstudentID() << endl;
		cout << "Physics: " << s.getPhysicsMarks() << endl;
		cout << "Chemistry: " << s.getChemistryMarks() << endl;
		cout << "Maths: " << s.getMathsMarks() << endl;
		cout << "English: " << s.getEnglishMarks() << endl;
		cout << "Computer Science: " << s.getCSMarks() << endl;
		cout << '\n';
	}
	return;
}


//
//Get Student information from the databse given ID
//
void Database::getStudentInfo(int id) {
	for (auto i : studentsDirectory) {
		if (i.getstudentID() == id)
		{
			i.displayStudentInfo();
			return;
		}
	}

	//if gets here, student not found in the database
	cout << "No student record exist of this ID '" << id << "'" << endl;
	return;
}


//
//helper function for Modify student information, Return true if there's any modification, otherwise false
//
bool Database::_modifyStudentInfo(Student *s) {
	int userInput, id;
	string name;
	bool isModified = false;

	cout << "\nChoose option below to modify or enter any other number to return\n" << endl;
	cout << "1: Modify student first name" << endl;
	cout << "2: Modify student last name" << endl;
	cout << "3: Modify student ID\n" << endl;

	cin >> userInput;
	while (userInput > 0 && userInput < 4)
	{
		if (userInput == 1) {
			//do changes
			cout << "\nEnter First Name" << endl;
			cin >> name;
			s->setFirstName(name);
		}

		if (userInput == 2) {
			//do changes
			cout << "\nEnter Last Name" << endl;
			cin >> name;
			s->setLastName(name);
		}

		if (userInput == 3) {
			//do changes
			cout << "\nEnter Student ID" << endl;
			cin >> id;

			for (auto i : studentsDirectory)
			{
				if (i.getstudentID() == id) { //check if it is already exist
					cout << "Student with the same ID already exist.  Unable to update Student ID in the directory" << endl;
					return isModified;
				}
			}// end for loop

			s->setStudentID(id);
		}

		//set modification flag true
		isModified = true;

		cout << "\nChoose option below to modify or enter any other number to return\n" << endl;
		cout << "1: Modify student first name" << endl;
		cout << "2: Modify student last name" << endl;
		cout << "3: Modify student ID\n" << endl;
		cin >> userInput;
	} //end while loop

	return isModified;
}


//
//	Modify student information and update the database with new information
/*	**Important: When trying to change student ID in the helper function, check for ID already exist,
	otherwise it will delete the current student object **/
//
void Database::modifyStudentInfo() {
	int student_id;
	cout << "Enter Student ID to make changes in the Student's Information" << endl;
	cin >> student_id;

	bool isModified = false;
	//match the id within the database, if found, ask for changes. otherwise display error message
	for (auto &i : studentsDirectory)
	{
		if (i.getstudentID() == student_id)
		{
			isModified = _modifyStudentInfo(&i);
			if (isModified) {
				//student_id = i.getstudentID();
				cout << "Student record has been updated in the database" << endl;
			}
			else {
				cout << "No changes in the database" << endl;
			}
			return;
		}
	}

	//if gets here, no student found in the database
	cout << "No student record exist of this ID '" << student_id << "'" << endl;
	return;
}


//
//helper function for Modify Student SCORE, Return true if there's any modification, otherwise false
//
bool Database::_modifyStudentScore(Student *s) {
	//declare variables
	int userInput, score;
	bool isModified = false;

	cout << "1: Modify student Physics score" << endl;
	cout << "2: Modify student Chemistry score" << endl;
	cout << "3: Modify student Maths score" << endl;
	cout << "4: Modify student English score" << endl;
	cout << "5: Modify student Computer Science score" << endl;

	cout << "Select \"1 - 5\" to modify or enter any other number to return" << endl;
	cin >> userInput;
	while (userInput > 0 && userInput < 6)
	{
		if (userInput == 1) {
			//do changes
			cout << "Enter Physics Score" << endl;
			cin >> score;
			s->setPhysicsMarks(score);
		}

		if (userInput == 2) {
			//do changes
			cout << "Enter Chemistry Score" << endl;
			cin >> score;
			s->setChemistryMarks(score);
		}

		if (userInput == 3) {
			//do changes
			cout << "Enter Maths Score" << endl;
			cin >> score;
			s->setMathsMarks(score);
		}

		if (userInput == 4) {
			//do changes
			cout << "Enter English Score" << endl;
			cin >> score;
			s->setEnglishMarks(score);
		}

		if (userInput == 5) {
			//do changes
			cout << "Enter Computer Science Score" << endl;
			cin >> score;
			s->setCSMarks(score);
		}

		//set modification flag true
		isModified = true;

		cout << "Select \"1 - 5\" to modify or enter any other number to return" << endl;
		cin >> userInput;
	} //end while loop

	return isModified;
}


//
//Modify student score(s) and update the database with new score(s)
//
void Database::modifyStudentScore() {
	int student_id;
	cout << "Enter Student ID to make changes in the Student's Score" << endl;
	cin >> student_id;

	bool isModified = false;
	//match the id within the database, if found, ask for changes. otherwise display error message
	for (auto &i : studentsDirectory)
	{
		if (i.getstudentID() == student_id)
		{
			isModified = _modifyStudentScore(&i);
			if (isModified) {
				cout << "Student score has been updated in the database" << endl;
			}
			else {
				cout << "No changes in the database" << endl;
			}
			return;
		}
	}

	//if gets here, no student found in the database
	cout << "No student record exist of this ID '" << student_id << "'" << endl;
	return;
}


//
//Delete Student Record from the database
//
void Database::deleteStudentRecord() {
	int id, index = 0;

	cout << "Enter student ID to delete from the database" << endl;
	cin >> id;

	for (auto &i : studentsDirectory) {
		if (i.getstudentID() == id) {
			studentsDirectory.erase(studentsDirectory.begin() + index);
			cout << "Student record has been deleted" << endl;
			return;
		}
		index++;
	}

	//if gets here, no student found in the database
	cout << "No student record exist of this ID '" << id << "'" << endl;
}


//
//Delete everything from the database
//
void Database::deleteAllStudentsRecord() {
	if (studentsDirectory.empty()) {
		cout << "Database is empty.  No records found..." << endl;
		return;
	}

	studentsDirectory.clear();
	cout << "Students Record has been deleted" << endl;
	return;
}


//
//Return average score of all students given course name
//Return -1.0 if course name is invalid, -2.0 if database is empty
//
double Database::getCourseAvg(string courseName) {
	double avgScore = 0;

	//convert courseName into lower case
	transform(courseName.begin(), courseName.end(), courseName.begin(), ::tolower);

	//check if database is empty or not
	if (studentsDirectory.empty()) {
		cout << "Database is empty.  No records found..." << endl;
		return -2.0;
	}

	for (Student S : studentsDirectory) {//don't need '&' cuz no need to change anything in the database
		if (courseName == "chemistry")
			avgScore += double(S.getChemistryMarks()) / studentsDirectory.size();
		else if (courseName == "physics")
			avgScore += double(S.getPhysicsMarks()) / studentsDirectory.size();
		else if (courseName == "maths")
			avgScore += double(S.getMathsMarks()) / studentsDirectory.size();
		else if (courseName == "computer science" || courseName == "cs")
			avgScore += double(S.getCSMarks()) / studentsDirectory.size();
		else if (courseName == "english")
			avgScore += double(S.getEnglishMarks()) / studentsDirectory.size();
		else {
			//course name not found.. return
			return -1.0;
		}

	}

	return avgScore;
}