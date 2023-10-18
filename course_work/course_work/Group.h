//
//  Group.hpp
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#ifndef Group_hpp
#define Group_hpp

#include <stdio.h>
#include "Student.h"

class Group {
private:
    Student* _front;
    Student* _back;
    bool isEmpty();
    
public:
    Group();
    ~Group();
    
    void Attend(Date date);
    string Attendments(Date date);
    void AddMember(Student* student);
};

#endif /* Group_hpp */
