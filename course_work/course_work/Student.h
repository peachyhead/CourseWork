//
//  Student.hpp
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>
#include "Date.h"

using namespace std;

class Student {
public:

    char* firstName;
    char* lastName;
    char* group;
    
    Student();
    Student(char* firstName, char* lastName);
    ~Student();
    
    void setGroup(const char* groupName);
    void attend(Date date);

    bool isAttended(Date date);
    bool isEqual(Student student);
    char* showAttendments();
    int getAttendances();
    char* toString();

    bool operator ==(Student* student){
        return isEqual(*student);
    }
    
private:
    int _attendmentCount;
    Date* _attendments;
};

#endif /* Student_hpp */
