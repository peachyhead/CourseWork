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
    string Name;
    
    Student();
    Student(string name);
    ~Student();
    
    void Attend(Date date);
    bool Attended(Date date);
    string ShowAttendments();
    
private:
    int _attendmentCount;
    Date* _attendments;
};

#endif /* Student_hpp */
