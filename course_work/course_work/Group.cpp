//
//  Group.cpp
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#include "Group.h"

Group::Group(){
    _front = nullptr;
    _back = nullptr;
}

Group::~Group(){
    delete _front;
    delete _back;
}

bool Group::isEmpty(){
    return _front == nullptr;
}

void Group::AddMember(Student* student){
    if (isEmpty()) {
        _front = student;
        _back = student;
        student->next = student;
        student->prev = student;
    }
    else {
        student->next = _front;
        student->prev = _back;
        _back->next = student;
        _front->prev = student;
        _back = student;
    }
}

void Group::Attend(Date date){
    Student* enumerator = _front;
    bool iterated = false;
    
    while (!iterated || enumerator != _front) {
        enumerator = enumerator->next;
        enumerator->Attend(date);
        iterated = true;
    }
}

string Group::Attendments(Date date){
    Student* enumerator = _front;
    bool iterated = false;
    stringstream resultStream;
    
    resultStream << "Attendments for " << date.Assemble() << ":" << endl;
    
    while (!iterated || enumerator != _front) {
        enumerator = enumerator->next;
        if (enumerator->Attended(date))
            resultStream << enumerator->Name << endl;
        iterated = true;
    }
    resultStream << endl;
    
    return resultStream.str();
}
