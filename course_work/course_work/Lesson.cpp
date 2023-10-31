//
//  Lesson.cpp
//  course_work
//
//  Created by Vasily Chalov on 31.10.2023.
//

#include "Lesson.hpp"

Lesson::Lesson() {
    this->name = "undefined";
}

Lesson::Lesson(string name, Date* date) {
    this->name = name;
    this->date = date;
}

Lesson::Lesson(string name, Date* date, Time* time) {
    this->name = name;
    this->date = date;
    this->time = time;
}

Lesson::~Lesson() {
    
}

string Lesson::toString() {
    return name + " " + date->toString();
}
