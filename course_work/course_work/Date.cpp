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
    _hour = 0;
    _minute = 0;
}

Date::Date(int day, int month, int hour, int minute){
    _month = month;
    _day = day;
    _hour = hour;
    _minute = minute;
}

string Date::Assemble(){
    stringstream serializedData;
    serializedData << _day << "/" << _month << " - " << _hour << ":" << _minute;
    return serializedData.str();
}

Date::~Date(){
    
}

bool Date::IsEqual(Date date){
    return date._day == _day && 
    date._hour == _hour && 
    date._month == _month &&
    date._minute == _minute;
}
