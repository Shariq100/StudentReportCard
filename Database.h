#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Person.h"
#include "Student.h"

using namespace std;

class Database{
private:
	vector<Student> studentsDirectory;
public:
	void updateStudentsDirectory(Student s);
	void readAllStudentsRecord();
	void getStudentInfo(int id);

	bool _modifyStudentInfo(Student *s);
	void modifyStudentInfo(); //see this function description for important note

	bool _modifyStudentScore(Student *s);
	void modifyStudentScore();

	void deleteStudentRecord();
	void deleteAllStudentsRecord();


	//get averages of each subject(i.e physics, chemistry, maths, english and computer science)
	double getCourseAvg(string courseName);

	int getAllStudentsPhysicsAvg();
	int getAllStudentsChemistryAvg();
	int getAllStudentsMathsAvg();
	int getAllStudentsEnglishAvg();
	int getAllStudentsComputerScienceAvg();

};