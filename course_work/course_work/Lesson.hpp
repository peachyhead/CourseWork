//
//  Lesson.hpp
//  course_work
//
//  Created by Vasily Chalov on 18.10.2023.
//

#ifndef Lesson_hpp
#define Lesson_hpp

#include <stdio.h>
#include <iostream>
#include "Date.h"
#include "Time.h"

using namespace std;

class Lesson {
public:
    string name;
    Date* date;
    Time* time;
    
    Lesson();
    Lesson(string name, Date* date);
    Lesson(string name, Date* date, Time* time);
    ~Lesson();
    
    string toString();
};

#endif /* Lesson_hpp */
