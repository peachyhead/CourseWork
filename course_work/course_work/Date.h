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

class Date {
private:
    int _day;
    int _month;
    
public:
    Date();
    Date(int month, int day);
    ~Date();
    
    string toString();
    bool isEqual(Date date);
};

#endif /* Date_hpp */
