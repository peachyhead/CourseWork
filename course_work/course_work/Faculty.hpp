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

    Student* getStudent(const char* firstName, const char* lastName);

public:
    Faculty();
    ~Faculty();

    void addStudent(Student* student);
    bool removeStudent(const char* firstName, const char* lastName);
    bool addStudentToGroup(const char* firstName, const char* lastName, const char* group);

    bool attendStudent(char* firstName, char* lastName, Date date);
    void attendGroup(char* group, Date date);

    void showAttendees(Date date);
    void showStudents();
    void showStudent(char* firstName, char* lastName);

    void sortAlphabetically();
    void sortByAttendments();

    bool isSortedAlphabetically();
    bool isSortedByAttendments();
};

#endif /* Faculty_hpp */
