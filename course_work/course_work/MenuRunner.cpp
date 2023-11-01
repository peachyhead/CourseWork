//
//  MenuRunner.cpp
//  course_work
//
//  Created by Vasily Chalov on 29.10.2023.
//

#include "MenuRunner.hpp"
#include <vector>

MenuRunner::MenuRunner(Faculty* faculty) {
    _faculty = faculty;
}

MenuRunner::~MenuRunner() {
    //delete _faculty;
}

void MenuRunner::run() {
    _faculty->addStudent(new Student("Gleb", "Ignatev"));
    _faculty->addStudent(new Student("Alex", "Korchuganov"));
    _faculty->addStudent(new Student("Dan", "Shaposhnikov"));
    _faculty->addStudent(new Student("Kirill", "Lapshin"));
    _faculty->addStudent(new Student("Dmitry", "Svyatash"));

    _faculty->addStudentToGroup("Gleb", "Ignatev", "AVT-143");
    _faculty->addStudentToGroup("Dmitry", "Svyatash", "AVT-143");

    char input;

    do {
        clearScreen();

        cout << showOptions();
        cout << "Choose option: ";
        cin >> input;

        subBtn1(input);
        subBtn2(input);
        subBtn3(input);
        subBtn4(input);
        subBtn5(input);
        subBtn6(input);
        subBtn7(input);
        subBtn8(input);
        subBtn9(input);

    } while (!subBtnExt(input));
}

bool MenuRunner::subBtn1(char symbol) {
    if (symbol != '1') return false;

    char firstName[50], lastName[50];

    cout << "Enter student name: ";
    cin >> firstName >> lastName;

    Student* student = new Student(firstName, lastName);
    _faculty->addStudent(student);

    cout << "Added student " << student->toString() << "!" << endl;
    return true;
}

bool MenuRunner::subBtn2(char symbol) {
    if (symbol != '2') return false;
    char firstName[50], lastName[50];
    cout << "Enter student name: ";
    cin >> firstName >> lastName;
    if (_faculty->removeStudent(firstName, lastName))
        cout << "Removed student " << firstName << " " << lastName << "!" << endl;
    else
        cout << "Failed to remove student!" << endl;
    return true;
}

bool MenuRunner::subBtn3(char symbol) {
    if (symbol != '3') return false;

    _faculty->showStudents();
    return true;
}

bool MenuRunner::subBtn4(char symbol) {
    if (symbol != '4') return false;
    char firstName[50], lastName[50], group[20];
    cout << "Enter student name: ";
    cin >> firstName >> lastName;

    cout << "Enter group name: ";
    cin >> group;
    if (_faculty->addStudentToGroup(firstName, lastName, group))
        cout << "Added student " << firstName << " " << lastName << " to group " << group << "!" << endl;
    else
        cout << "Failed to add student group" << "!" << endl;
    return true;
}

bool MenuRunner::subBtn5(char symbol) {
    if (symbol != '5') return false;
    char firstName[100], lastName[100], date[12];
    cout << "Enter student name: ";
    cin >> firstName >> lastName;

    cout << "Enter lesson date (dd/mm): ";
    cin >> date;

    int day, month;
    if (sscanf(date, "%d/%d", &day, &month) != 2) {
        cerr << "Invalid date format: " << date << endl;
        return false;
    }

    Date* relatedDate = new Date(day, month);
    _faculty->attendStudent(firstName, lastName, *relatedDate);

    return true;
}


bool MenuRunner::subBtn6(char symbol) {
    if (symbol != '6') return false;
    char group[100], date[12];
    cout << "Enter group name: ";
    cin >> group;

    cout << "Enter lesson date (dd/mm): ";
    cin >> date;

    int day, month;
    if (sscanf(date, "%d/%d", &day, &month) != 2) {
        cerr << "Invalid date format: " << date << endl;
        return false;
    }

    Date* relatedDate = new Date(day, month);
    _faculty->attendGroup(group, *relatedDate);
    return true;
}

bool MenuRunner::subBtn7(char symbol) {
    if (symbol != '7') return false;
    char date[12];
    cout << "Enter lesson date (dd/mm): ";
    cin >> date;

    int day, month;
    if (sscanf(date, "%d/%d", &day, &month) != 2) {
        cerr << "Invalid date format: " << date << endl;
        return false;
    }

    Date* relatedDate = new Date(day, month);
    _faculty->showAttendees(*relatedDate);
    return true;
}

bool MenuRunner::subBtn8(char symbol) {
    if (symbol != '8') return false;

    char result;
    cout << "Press 'a' if you want to sort list alphabetically," << endl <<
    "either 's' if you wish to sort by attendments count:" << endl;
    cin >> result;

    if (result == 'a') {
        _faculty->sortAlphabetically();
        cout << "Students has been sorted alphabetically!" << endl;
    }
    else if (result == 's') {
        _faculty->sortByAttendments();
        cout << "Students has been sorted by their attendments!" << endl;
    }
    else
        cout << "No matching input! Stepping back to the menu!" << endl;
    return true;
}

bool MenuRunner::subBtn9(char symbol) {
    if (symbol != '9') return false;
    char firstName[100], lastName[100], date[12];
    cout << "Enter student name: ";
    cin >> firstName >> lastName;
    
    _faculty->showStudent(firstName, lastName);
    
    return true;
}

bool MenuRunner::subBtnExt(char symbol){
    return symbol == 'q' || symbol == 'Q';
}

char* MenuRunner::showOptions() {
    const char* result =
        "[1] - Add student\n"
        "[2] - Remove student\n"
        "[3] - Show students\n"
        "[4] - Add student to group\n"
        "[5] - Attend student\n"
        "[6] - Attend group\n"
        "[7] - Show attendees on date\n"
        "[8] - Sort students with option\n"
        "[9] - Find student by name\n"
        "[Q] - Quit\n";
    return strdup(result);
}

void MenuRunner::clearScreen(){
    #if defined(_WIN32)
    system("cls");
    #endif // defined

    #if defined(__APPLE__) || defined(__linux__)
    system("clear");
    #endif // defined
}
