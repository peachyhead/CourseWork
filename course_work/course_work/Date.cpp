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

char* Date::toString() {
    char buffer[12];

    snprintf(buffer, sizeof(buffer), "%d/%d", _day, _month);

    return strdup(buffer);
}

Date::~Date() {
    
}

bool Date::isEqual(Date date){
    return date._day == _day &&
    date._month == _month;
}
