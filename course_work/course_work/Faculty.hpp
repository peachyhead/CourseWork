//
//  Faculty.hpp
//  course_work
//
//  Created by Vasily Chalov on 30.10.2023.
//

#ifndef Faculty_hpp
#define Faculty_hpp

#include <stdio.h>
#include "utils/List.hpp"
#include "Student.h"
#include "Date.h"
#include <iomanip>

using namespace std;

class Faculty {
private:
    List<Student> _students;
    
    Student* getStudent(string firstName, string lastName);
    
public:
    Faculty();
    ~Faculty();
    
    void addStudent(Student* student);
    bool removeStudent(string firstName, string lastName);
    bool addStudentToGroup(string firstName, string lastName, string group);
    
    bool attendStudent(string firstName, string lastName, Date date);
    void attendGroup(string group, Date date);
    
    string showAttendees(Date date);
    string showStudents();
    
    void sortAlphabetically();
    void sortByAttendments();
    
    bool isSortedAlphabetically();
    bool isSortedByAttendments();
};

#endif /* Faculty_hpp */
