//
//  Date.hpp
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

class Date{
private:
    int _day;
    int _month;
    int _hour;
    int _minute;
    
public:
    Date();
    Date(int month, int day, int hour, int minute);
    ~Date();
    
    string Assemble();
    bool IsEqual(Date date);
};

#endif /* Date_hpp */
