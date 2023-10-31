//
//  Student.cpp
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#include "Student.h"

Student::Student(){
    firstName = "Anonymous";
    firstName = "Anonymous";
    _attendmentCount = 0;
    _attendments = new Date[_attendmentCount];
}

Student::Student(string firstName, string lastName){
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

string Student::showAttendments(){
    stringstream result;
    result << "Attendments of " << firstName << ":" << endl;
    for(int i = 0; i < _attendmentCount; i++){
        result << _attendments[i].toString() << endl;
    }
    result << endl;
    
    return result.str();
}

void Student::setGroup(string groupName) {
    group = groupName;
}

string Student::getGroup() {
    return group;
}

string Student::toString() {
    return firstName + " " + lastName;
}

bool Student::isEqual(Student student) {
    return  student.firstName == firstName &&
            student.lastName == lastName &&
            student.group == group;
}
