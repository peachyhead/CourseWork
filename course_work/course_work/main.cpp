//
//  main.cpp
//  course_work
//
//  Created by Vasily Chalov on 12.10.2023.
//

#include <iostream>
#include "Group.h"
#include "Date.h"
#include "Student.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Student* gleb = new Student("Gleb");
    Student* alex = new Student("Alex");
    Student* dan = new Student("Dan");
    Student* kirill = new Student("Kirill");
    Student* dmitry = new Student("Dmitry");
    
    Date* mathLesson = new Date(22, 4, 10, 15);
    Date* englishLesson = new Date(23, 4, 8, 30);
    Date* programLesson = new Date(25, 4, 8, 30);
    Date* chemistryLesson = new Date(26, 4, 10, 15);
    Date* bilogyLesson = new Date(26, 4, 12, 00);
    
    Group* group1 = new Group();
    Group* group2 = new Group();

    group1->AddMember(gleb);
    group1->AddMember(dmitry);
    group2->AddMember(dan);
    group2->AddMember(kirill);
    
    gleb->Attend(*mathLesson);
    kirill->Attend(*mathLesson);
    dmitry->Attend(*mathLesson);
    
    group1->Attend(*englishLesson);
    group1->Attend(*programLesson);
    group1->Attend(*bilogyLesson);
    
    group2->Attend(*programLesson);
    group2->Attend(*chemistryLesson);
    
    group2->AddMember(alex);
    
    group2->Attend(*englishLesson);
    
    cout << gleb->ShowAttendments();
    cout << group2->Attendments(*programLesson);
    cout << alex->ShowAttendments();
    cout << dan->ShowAttendments();
    cout << kirill->ShowAttendments();
    cout << dmitry->ShowAttendments();
    return 0;
}
