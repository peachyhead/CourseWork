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
    Student* next;
    Student* prev;
    
    Student();
    Student(string name);
    ~Student();
    
    void Attend(Date date);
    string ShowAttendments();
    
private:
    string _name;
    int _attendmentCount;
    Date* _attendments;
};

#endif /* Student_hpp */
