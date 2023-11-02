//
//  Student.cpp
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#include "Student.h"

Student::Student(){
    this->firstName = new char[strlen("Anonymous")];
    strcpy(this->firstName, "Anonymous");
    this->lastName = new char[strlen("Anonymous")];
    strcpy(this->lastName, "Anonymous");
    group = new char [2];
    group [0] = '-';
    group [1] = '\0';
    _attendmentCount = 0;
    _attendments = new Date[_attendmentCount];
}

Student::Student(char* firstName, char* lastName){
    this->firstName = new char[strlen(firstName + 1)];
    strcpy(this->firstName, firstName);
    this->lastName = new char[strlen(lastName + 1)];
    strcpy(this->lastName, lastName);
    group = new char [2];
    group [0] = '-';
    group [1] = '\0';
    _attendmentCount = 0;
    _attendments = new Date[_attendmentCount];
}

Student::~Student(){
    if (firstName)
        delete firstName;
    if (lastName)
        delete lastName;
    if (group)
        delete group;
}

void Student::attend(Date date) {
    size_t newSize = (_attendmentCount + 1) * sizeof(Date);

    Date* changed = new Date[newSize];

    if (_attendmentCount != 0) {
        memcpy(changed, _attendments, _attendmentCount * sizeof(Date));
    }

    changed[_attendmentCount] = date;

    delete [] _attendments;
    _attendments = changed;
    _attendmentCount += 1;
}

bool Student::isAttended(Date date){
    bool result = false;
    
    for (int i = 0; i < _attendmentCount; i++)
        if (_attendments[i].isEqual(date))
            result = true;
    
    return result;
}

int Student::getAttendances() {
    return _attendmentCount;
}

char* Student::showAttendments() {
    size_t totalLength = strlen("Attendments of ") + 
    strlen(firstName) + strlen(":") + strlen("\n");
    
    for (int i = 0; i < _attendmentCount; i++) {
        totalLength += strlen(_attendments[i].toString()) + 
        strlen("\n");
    }
    
    char* result = new char[totalLength + 1];

    strcpy(result, "Attendments of ");
    strcat(result, firstName);
    strcat(result, ":\n");
    for (int i = 0; i < _attendmentCount; i++) {
        strcat(result, _attendments[i].toString());
        strcat(result, "\n");
    }

    return result;
}


void Student::setGroup(const char* groupName) {
    if (group)
        delete[] group;

    group = strdup(groupName);
}

int Student::toString(char* buffer, size_t bufferSize) {
    return snprintf(buffer, bufferSize, "%s %s",firstName, lastName);
}

bool Student::isEqual(Student student) {
    return  student.firstName == firstName &&
            student.lastName == lastName &&
            student.group == group;
}
