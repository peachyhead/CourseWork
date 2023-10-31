//
//  Faculty.cpp
//  course_work
//
//  Created by Vasily Chalov on 30.10.2023.
//

#include "Faculty.hpp"

Faculty::Faculty() {
    
}

Faculty::~Faculty() {
    
}

void Faculty::addStudent(Student* student) {
    _students.add(student);
    _students.swap(0, _students.getCount() - 1);
}

bool Faculty::removeStudent(string firstName, string lastName) {
    Student* requiredStudent = getStudent(firstName, lastName);
    
    if (requiredStudent == nullptr) return false;
    _students.remove(requiredStudent);
    
    return true;
}

bool Faculty::addStudentToGroup(string firstName, string lastName, string group) {
    Student* requiredStudent = getStudent(firstName, lastName);
    
    if (requiredStudent == nullptr) return false;
    requiredStudent->setGroup(group);
    
    return true;
}

bool Faculty::attendStudent(string firstName, string lastName, Date date) {
    Student* requiredStudent = getStudent(firstName, lastName);
    
    if (requiredStudent == nullptr) return false;
    requiredStudent->attend(date);
    
    return true;
}

void Faculty::attendGroup(string group, Date date) {
    for (int i = 0; i < _students.getCount(); i++) {
        if (_students[i].getGroup() == group)
            _students[i].attend(date);
    }
}

string Faculty::showAttendees(Date date) {
    stringstream studentStream;
    studentStream << "+----------------+----------------+----------------+----------------+" << endl;
    studentStream << "+----------------+ Attendments for:      " << date.toString() << "      +----------------+" << endl;
    studentStream << "+----------------+----------------+----------------+----------------+" << endl;
    studentStream << "| First Name     | Last Name      | Group          | Attendances    |" << endl;
    studentStream << "+----------------+----------------+----------------+----------------+" << endl;
    
    
    
    for (int i = 0; i < _students.getCount(); i++) {
        Student student = _students[i];
        if (!student.isAttended(date)) continue;
        studentStream << "| " << left << setw(15) << student.firstName <<
                         "| " << left << setw(15) << student.lastName <<
                         "| " << left << setw(15) << student.group <<
                         "| " << left << setw(15) << student.getAttendances() << "|" << endl;
        studentStream << "+----------------+----------------+----------------+----------------+" << endl;
    }
    return studentStream.str();
}

string Faculty::showStudents() {
    stringstream studentStream;
    studentStream << "+----------------+----------------+----------------+----------------+" << endl;
    studentStream << "+----------------+       Faculty's students:       +----------------+" << endl;
    studentStream << "+----------------+----------------+----------------+----------------+" << endl;
    studentStream << "| First Name     | Last Name      | Group          | Attendances    |" << endl;
    studentStream << "+----------------+----------------+----------------+----------------+" << endl;

    for (int i = 0; i < _students.getCount(); i++) {
        Student student = _students[i];
        studentStream << "| " << left << setw(15) << student.firstName <<
                         "| " << left << setw(15) << student.lastName <<
                         "| " << left << setw(15) << student.group <<
                         "| " << left << setw(15) << student.getAttendances() << "|" << endl;
        studentStream << "+----------------+----------------+----------------+----------------+" << endl;
    }
    return studentStream.str();
}

void Faculty::sortAlphabetically() {
    while (!isSortedAlphabetically()) {
        for (int i = 0; i < _students.getCount() - 1; i++) {
            
        }
    }
}
void Faculty::sortByAttendments() {
    while (!isSortedByAttendments()) {
        int min = -1;
        int bound = 0;
        for (int i = 0; i < _students.getCount() - 1; i++) {
            if (_students[i].getAttendances() <
                _students[i + 1].getAttendances()) {
                min = i;
            }
        }
        
        _students.swap(min, bound);
        bound += 1;
    }
}

bool Faculty::isSortedAlphabetically() {
    for (int i = 0; i < _students.getCount() - 1; i++) {
        if (_students[i].firstName > _students[i + 1].firstName)
            return false;
    }
    return true;
}

bool Faculty::isSortedByAttendments() {
    for (int i = 0; i < _students.getCount() - 1; i++) {
        if (_students[i].getAttendances() >
            _students[i + 1].getAttendances())
            return false;
    }
    return true;
}

Student* Faculty::getStudent(string firstName, string lastName) {
    Student* requiredStudent = nullptr;
    for (int i = 0; i < _students.getCount(); i++) {
        if (_students[i].firstName == firstName &&
            _students[i].lastName == lastName)
            requiredStudent = &_students[i];
    }
    
    return requiredStudent;
}
