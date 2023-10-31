//
//  Date.cpp
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#include "Date.h"

Date::Date(){
    _month = 0;
    _day = 0;
}

Date::Date(int day, int month) {
    _month = month;
    _day = day;
}

string Date::toString() {
    stringstream serializedData;
    serializedData << _day << "/" << _month;
    return serializedData.str();
}

Date::~Date() {
    
}

bool Date::isEqual(Date date){
    return date._day == _day &&
    date._month == _month;
}
