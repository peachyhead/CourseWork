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

    cout << "+-----+--------------------------------------------------+----------------+" << endl;
    cout << "|-----|                Attendments for:      " << date.toString() << "     |----------------|" << endl;
    cout << "+-----+----------------+----------------+----------------+----------------+" << endl;
    cout << "| ID  | First Name     | Last Name      | Group          | Attendances    |" << endl;
    cout << "+-----+----------------+----------------+----------------+----------------+" << endl;

    for (int iter = 0; iter < _students.getCount(); iter++) {
        Student student = _students[iter];
        if (!student.isAttended(date)) continue;
        cout << "| " << left << setw(4) << iter <<
                "| " << left << setw(15) << student.firstName <<
                "| " << left << setw(15) << student.lastName <<
                "| " << left << setw(15) << student.group <<
                "| " << left << setw(15) << student.getAttendances() << "|" << endl;
        cout << "+-----+----------------+----------------+----------------+----------------+" << endl;
    }
}

void Faculty::showStudents() {
    cout << "+-----+--------------------------------------------------+----------------+" << endl;
    cout << "|-----|                Faculty's students:               |----------------|" << endl;
    cout << "+-----+----------------+----------------+----------------+----------------+" << endl;
    cout << "| ID  | First Name     | Last Name      | Group          | Attendances    |" << endl;
    cout << "+-----+----------------+----------------+----------------+----------------+" << endl;

    Node<Student>* q = _students.getBack();
    int iter = 0;
    for (; iter < _students.getCount(); iter++)
    {
        q = q->next;
        Student* student = q->data;

        cout << "| " << left << setw(4) << iter <<
                "| " << left << setw(15) << student->firstName <<
                "| " << left << setw(15) << student->lastName <<
                "| " << left << setw(15) << student->group <<
                "| " << left << setw(15) << student->getAttendances() << "|" << endl;
        cout << "+-----+----------------+----------------+----------------+----------------+" << endl;
    }
}

void Faculty::showStudent(char *firstName, char *lastName) {
    cout << "+-----+--------------------------------------------------+----------------+" << endl;
    cout << "|-----|                   Student info:                  |----------------|" << endl;
    cout << "+-----+----------------+----------------+----------------+----------------+" << endl;
    cout << "| ID  | First Name     | Last Name      | Group          | Attendances    |" << endl;
    cout << "+-----+----------------+----------------+----------------+----------------+" << endl;
    
    Student* student = getStudent(firstName, lastName);
    if (student == nullptr) return;

    cout << "| " << left << setw(4) << _students.indexOf(student) <<
            "| " << left << setw(15) << student->firstName <<
            "| " << left << setw(15) << student->lastName <<
            "| " << left << setw(15) << student->group <<
            "| " << left << setw(15) << student->getAttendances() << "|" << endl;
    cout << "+-----+----------------+----------------+----------------+----------------+" << endl;
}

void Faculty::showStudent(int index) {
    cout << "+-----+--------------------------------------------------+----------------+" << endl;
    cout << "|-----|                   Student info:                  |----------------|" << endl;
    cout << "+-----+----------------+----------------+----------------+----------------+" << endl;
    cout << "| ID  | First Name     | Last Name      | Group          | Attendances    |" << endl;
    cout << "+-----+----------------+----------------+----------------+----------------+" << endl;
    
    Student* student = &_students[index];
    
    if (student == nullptr) return;

    cout << "| " << left << setw(4) << _students.indexOf(student) <<
            "| " << left << setw(15) << student->firstName <<
            "| " << left << setw(15) << student->lastName <<
            "| " << left << setw(15) << student->group <<
            "| " << left << setw(15) << student->getAttendances() << "|" << endl;
    cout << "+-----+----------------+----------------+----------------+----------------+" << endl;
}

void Faculty::sortAlphabetically() {
    int n = _students.getCount();
    bool swapped;

    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (strcmp(_students[i].firstName, _students[i + 1].firstName) > 0) {
                _students.swap(i, i + 1);
                swapped = true;
            }
        }
        n--;
    } while (swapped);
}

void Faculty::sortByAttendments() {
    int n = _students.getCount();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (_students[j].getAttendances() < _students[j + 1].getAttendances()) {
                _students.swap(j, j + 1);
                swapped = true;
            }
        }
        if (!swapped) {
            // If no swaps were made during a pass, the list is already sorted
            break;
        }
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
        if (_students[i].getAttendances() <
            _students[i + 1].getAttendances())
            return false;
    }
    return true;
}

Student* Faculty::getStudent(const char* firstName, const char* lastName) {
    Student* requiredStudent = nullptr;

    Node<Student>* q = _students.getBack()->next;
    for(int iter = 0; iter < _students.getCount(); iter++)
    {
        Student* s = q->data;
        if (strcmp(s->firstName, firstName) == 0 &&
            strcmp(s->lastName, lastName) == 0)
            return s;
        q = q->next;
    }

    return requiredStudent;
}
