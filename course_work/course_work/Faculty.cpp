//
//  Faculty.cpp
//  course_work
//
//  Created by Vasily Chalov on 30.10.2023.
//

#include <cstring>

#include "Faculty.hpp"

Faculty::Faculty() {

}

Faculty::~Faculty() {

}

void Faculty::addStudent(Student* student) {
    _students.add(student);
}

bool Faculty::removeStudent(const char* firstName, const char* lastName) {
    Student* requiredStudent = getStudent(firstName, lastName);

    if (requiredStudent == nullptr) return false;

    _students.remove(requiredStudent);
    return true;
}

bool Faculty::addStudentToGroup(const char* firstName, const char* lastName, const char* group) {
    Student* requiredStudent = getStudent(firstName, lastName);

    if (requiredStudent == nullptr) return false;

    requiredStudent->setGroup(group);
    return true;
}

bool Faculty::attendStudent(char* firstName, char* lastName, Date date) {
    Student* requiredStudent = getStudent(firstName, lastName);

    if (requiredStudent == nullptr) return false;
    
    requiredStudent->attend(date);
    return true;
}

void Faculty::attendGroup(char* group, Date date) {
    for (int i = 0; i < _students.getCount(); i++) {
        Student* student = &_students[i];
        if (strcmp(student->group, group) == 0)
            student->attend(date);
    }
}

void Faculty::showAttendees(Date date) {

    cout << "+----------------+----------------+----------------+----------------+" << endl;
    cout << "|----------------| Attendments for:      " << date.toString() << "      |----------------|" << endl;
    cout << "+----------------+----------------+----------------+----------------+" << endl;
    cout << "| First Name     | Last Name      | Group          | Attendances    |" << endl;
    cout << "+----------------+----------------+----------------+----------------+" << endl;

    for (int i = 0; i < _students.getCount(); i++) {
        Student student = _students[i];
        if (!student.isAttended(date)) continue;
        cout << "| " << left << setw(15) << student.firstName <<
                "| " << left << setw(15) << student.lastName <<
                "| " << left << setw(15) << student.group <<
                "| " << left << setw(15) << student.getAttendances() << "|" << endl;
        cout << "+----------------+----------------+----------------+----------------+" << endl;
    }
}

void Faculty::showStudents() {
    cout << "+----------------+----------------+----------------+----------------+" << endl;
    cout << "|----------------|       Faculty's students:       |----------------|" << endl;
    cout << "+----------------+----------------+----------------+----------------+" << endl;
    cout << "| First Name     | Last Name      | Group          | Attendances    |" << endl;
    cout << "+----------------+----------------+----------------+----------------+" << endl;

    Node<Student>* q = _students.getBack();
    while(q != nullptr)
    {
        Student* student = q->data;

        cout << "| " << left << setw(15) << student->firstName <<
                "| " << left << setw(15) << student->lastName <<
                "| " << left << setw(15) << student->group <<
                "| " << left << setw(15) << student->getAttendances() << "|" << endl;
        cout << "+----------------+----------------+----------------+----------------+" << endl;
        q = q->next;
    }
}

void Faculty::showStudent(char *firstName, char *lastName) {
    cout << "+----------------+----------------+----------------+----------------+" << endl;
    cout << "|----------------|          Student info:          |----------------|" << endl;
    cout << "+----------------+----------------+----------------+----------------+" << endl;
    cout << "| First Name     | Last Name      | Group          | Attendances    |" << endl;
    cout << "+----------------+----------------+----------------+----------------+" << endl;
    
    Node<Student>* q = _students.getBack();
    while(q != nullptr)
    {
        Student* student = q->data;
        q = q->next;
        if (strcmp(student->firstName, firstName) != 0 ||
            strcmp(student->lastName, lastName) != 0) continue;

        cout << "| " << left << setw(15) << student->firstName <<
                "| " << left << setw(15) << student->lastName <<
                "| " << left << setw(15) << student->group <<
                "| " << left << setw(15) << student->getAttendances() << "|" << endl;
        cout << "+----------------+----------------+----------------+----------------+" << endl;
    }
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
        if (strcmp(_students[i].firstName, _students[i + 1].firstName) < 0)
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

Student* Faculty::getStudent(const char* firstName, const char* lastName) {
    Student* requiredStudent = nullptr;

    Node<Student>* q;
    for(q = _students.getBack(); q != nullptr; q = q->next)
    {
        Student* s = q->data;
        if (strcmp(s->firstName, firstName) == 0 &&
            strcmp(s->lastName, lastName) == 0)
            {
                requiredStudent = s;
                break;
            }
    }

    return requiredStudent;
}
