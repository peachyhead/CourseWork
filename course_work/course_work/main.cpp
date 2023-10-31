//
//  main.cpp
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#include <iostream>
#include "Faculty.hpp"
#include "MenuRunner.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Faculty* faculty = new Faculty();
    MenuRunner* menuRunner = new MenuRunner(faculty);
    
    menuRunner->run();
    return 0;
}
