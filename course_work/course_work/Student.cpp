//
//  Student.cpp
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#include "Student.h"

Student::Student(){
    Name = "Anonymous";
    next = nullptr;
    prev = nullptr;
    _attendmentCount = 0;
    _attendments = new Date[_attendmentCount];
}

Student::Student(string name){
    Name = name;
    next = nullptr;
    prev = nullptr;
    _attendmentCount = 0;
    _attendments = new Date[_attendmentCount];
}

Student::~Student(){
    next = nullptr;
    prev = nullptr;
}

void Student::Attend(Date date) {
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

bool Student::Attended(Date date){
    bool result = false;
    
    for (int i = 0; i < _attendmentCount; i++)
        if (_attendments[i].IsEqual(date))
            result = true;
    
    return result;
}

string Student::ShowAttendments(){
    stringstream result;
    result << "Attendments of " << Name << ":" << endl;
    for(int i = 0; i < _attendmentCount; i++){
        result << _attendments[i].Assemble() << endl;
    }
    result << endl;
    
    return result.str();
}
