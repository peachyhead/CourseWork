//
//  MenuRunner.hpp
//  course_work
//
//  Created by Vasily Chalov on 29.10.2023.
//

#ifndef MenuRunner_hpp
#define MenuRunner_hpp

#include <stdio.h>
#include "Date.h"
#include "Lesson.hpp"
#include "Student.h"
#include "utils/List.hpp"
#include "Faculty.hpp"

class MenuRunner {
public:
    
    MenuRunner(Faculty* faculty);
    ~MenuRunner();
    
    void run();
private:
    Faculty* _faculty;
    
    bool subBtn1(char symbol);
    bool subBtn2(char symbol);
    bool subBtn3(char symbol);
    bool subBtn4(char symbol);
    bool subBtn5(char symbol);
    bool subBtn6(char symbol);
    bool subBtn7(char symbol);
    bool subBtn8(char symbol);
    bool subBtn9(char symbol);
    string showOptions();
};

#endif /* MenuRunner_hpp */
