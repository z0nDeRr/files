#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
	string surname; 
	float grade; 
	string course; 
};

const int MAX_STUDENTS = 50;

int main() {
    Student students[MAX_STUDENTS]; 
    int numStudents = 0; 
    ifstream inputFile("students.txt"); 

    if (!inputFile.is_open()) { 
        cout << "Error opening file." << endl;
        return 1;
    }

    while (numStudents < MAX_STUDENTS && !inputFile.eof()) { 
        getline(inputFile, students[numStudents].surname);
        inputFile >> students[numStudents].grade;
        inputFile >> students[numStudents].course;
        inputFile.ignore(numeric_limits<streamsize>::max(), '\n'); 
        numStudents++;
    }

    inputFile.close(); 

    
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Surname: " << students[i].surname << endl;
        cout << "Grade: " << students[i].grade << endl;
        cout << "Course: " << students[i].course << endl;
        cout << endl;
    }

    return 0;
}