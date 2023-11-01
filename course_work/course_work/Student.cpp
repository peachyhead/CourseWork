//
//  Student.cpp
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#include "Student.h"

Student::Student(){
    group = new char[1];
    
    firstName = "Anonymous";
    firstName = "Anonymous";
    
    _attendmentCount = 0;
    _attendments = new Date[_attendmentCount];
}

Student::Student(char* firstName, char* lastName){
    group = new char[1];
    group[0] = '\0';
    
    this->firstName = firstName;
    this->lastName = lastName;
    _attendmentCount = 0;
    _attendments = new Date[_attendmentCount];
}

Student::~Student(){
    
}

void Student::attend(Date date) {
    size_t newSize = (_attendmentCount + 1) * sizeof(Date);

    Date* changed = (Date*)malloc(newSize);

    if (_attendmentCount != 0) {
        memcpy(changed, _attendments, _attendmentCount * sizeof(Date));
    }

    changed[_attendmentCount] = date;

    free(_attendments);
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

char* Student::toString() {
    char buffer[100];

    snprintf(buffer, sizeof(buffer), "%s %s", firstName, lastName);

    return strdup(buffer);
}

bool Student::isEqual(Student student) {
    return  student.firstName == firstName &&
            student.lastName == lastName &&
            student.group == group;
}
