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
    
    Student* student2 = new Student("Gleb");
    Student* student3 = new Student("Alex");
    Student* student4 = new Student("Daniil");
    Student* student5 = new Student("Kirill");
    Student* student6 = new Student("Dmitry");
    
    Date* mathLesson = new Date(22, 4, 10, 15);
    Date* englishLesson = new Date(23, 4, 8, 30);
    Date* programLesson = new Date(25, 4, 8, 30);
    Date* chemistryLesson = new Date(26, 4, 10, 15);
    Date* bilogyLesson = new Date(26, 4, 12, 00);
    
    Group* group1 = new Group();
    Group* group2 = new Group();

    group1->AddMember(student2);
    group1->AddMember(student6);
    
    group2->AddMember(student3);
    group2->AddMember(student4);
    group2->AddMember(student5);
    
    student2->Attend(*mathLesson);
    student5->Attend(*mathLesson);
    student6->Attend(*mathLesson);
    
    group1->Attend(*englishLesson);
    group1->Attend(*programLesson);
    group1->Attend(*bilogyLesson);
    
    group2->Attend(*programLesson);
    group2->Attend(*chemistryLesson);
    group2->Attend(*englishLesson);
    
    cout << student2->ShowAttendments();
    cout << student3->ShowAttendments();
    cout << student4->ShowAttendments();
    cout << student5->ShowAttendments();
    cout << student6->ShowAttendments();
    return 0;
}
