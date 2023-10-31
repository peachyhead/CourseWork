//
//  Time.h
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#ifndef Time_h
#define Time_h

#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

class Time {
private:
    int _hour;
    int _minute;
    
public:
    Time();
    Time(int hour, int minute);
    ~Time();
    
    string toString();
    bool isEqual(Time time);
};

#endif /* Time_h */
