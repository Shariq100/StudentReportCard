#pragma once
#include <iostream>
#include <vector>

#include "Person.h"

using namespace std;

class Student:public Person
{
	private:
		int s_id, chemistry, maths, english, computerscience, physics;

	protected:

	public:
		//function declarations...
		void setStudentID(int id);
		void setPhysicsMarks(int marks);
		void setChemistryMarks(int marks);
		void setMathsMarks(int marks);
		void setEnglishMarks(int marks);
		void setCSMarks(int marks);

		int getstudentID();
		int getPhysicsMarks();
		int getChemistryMarks();
		int getMathsMarks();
		int getEnglishMarks();
		int getCSMarks();

		void createStudentReport(string fName, string lName, int id, int phys, int chem, int math, int eng, int cs);
		void displayStudentInfo();
		double getExamAvg();
		char getStudentLetterGrade(string subject);
		int getStudentAverageScore();
		char getStudentAverageLetterGrade();

		~Student() = default;
};