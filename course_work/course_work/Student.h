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
    string group;
    string firstName;
    string lastName;
    
    Student();
    Student(string firstName, string lastName);
    ~Student();
    
    void setGroup(string groupName);
    void attend(Date date);

    bool isAttended(Date date);
    bool isEqual(Student student);
    string showAttendments();
    int getAttendances();
    string getGroup();
    string toString();

    bool operator ==(Student* student){
        return isEqual(*student);
    }
    
private:
    int _attendmentCount;
    Date* _attendments;
};

#endif /* Student_hpp */
