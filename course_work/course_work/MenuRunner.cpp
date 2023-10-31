//
//  MenuRunner.cpp
//  course_work
//
//  Created by Vasily Chalov on 29.10.2023.
//

#include "MenuRunner.hpp"

MenuRunner::MenuRunner(Faculty* faculty) {
    _faculty = faculty;
}

MenuRunner::~MenuRunner() {
    delete _faculty;
}

void MenuRunner::run() {
    _faculty->addStudent(new Student("Gleb", "Ignatev"));
    _faculty->addStudent(new Student("Alex", "Korchuganov"));
    _faculty->addStudent(new Student("Dan", "Shaposhnikov"));
    _faculty->addStudent(new Student("Kirill", "Laphin"));
    _faculty->addStudent(new Student("Dmitry", "Svyatash"));
    
    _faculty->addStudentToGroup("Gleb", "Ignatev", "AVT-143");
    _faculty->addStudentToGroup("Dmitry", "Svyatash", "AVT-143");
    
    while (true) {
        system("clear");
        cout << showOptions();
        char input;
        cout << "Choose option:" << endl;
        cin >> input;
        
        subBtn1(input);
        subBtn2(input);
        subBtn3(input);
        subBtn4(input);
        subBtn5(input);
        subBtn6(input);
        subBtn7(input);
        subBtn8(input);
    }
}

bool MenuRunner::subBtn1(char symbol) {
    if (symbol != '1') return false;
    string firstName, lastName;
    cout << "Enter student name: " << endl;
    cin >> firstName >> lastName;
    Student* student = new Student(firstName, lastName);
    _faculty->addStudent(student);
    cout << "Added student " << student->toString() << "!" << endl;
    return true;
}

bool MenuRunner::subBtn2(char symbol) {
    if (symbol != '2') return false;
    string firstName, lastName;
    cout << "Enter student name: " << endl;
    cin >> firstName >> lastName;
    if (_faculty->removeStudent(firstName, lastName))
        cout << "Removed student " << firstName << " " << lastName << "!" << endl;
    else
        cout << "Failed to remove student!" << endl;
    return true;
}

bool MenuRunner::subBtn3(char symbol) {
    if (symbol != '3') return false;
    
    cout << _faculty->showStudents();
    return true;
}

bool MenuRunner::subBtn4(char symbol) {
    if (symbol != '4') return false;
    string firstName, lastName, group;
    cout << "Enter student name: " << endl;
    cin >> firstName >> lastName;
    
    cout << "Enter group name: " << endl;
    cin >> group;
    if (_faculty->addStudentToGroup(firstName, lastName, group))
        cout << "Added student " << firstName << " " << lastName << " to group " << group << "!" << endl;
    else
        cout << "Failed to add student group" << "!" << endl;
    return true;
}

bool MenuRunner::subBtn5(char symbol) {
    if (symbol != '5') return false;
    string firstName, lastName, date;
    cout << "Enter student name: " << endl;
    cin >> firstName >> lastName;
    
    cout << "Enter lesson date:" << endl;
    cin >> date;
    
    vector<int> tokens;
    istringstream iss(date);
    string token;

    while (getline(iss, token, '/')) {
        try {
            int value = stoi(token);
            tokens.push_back(value);
        } catch (const invalid_argument& e) {
            cerr << "Invalid integer: " << token << endl;
            return false;
        } catch (const out_of_range& e) {
            cerr << "Integer out of range: " << token << endl;
            return false;
        }
    }
    
    if (tokens.size() < 2) return false;
    Date* relatedDate = new Date(tokens.at(0), tokens.at(1));
    _faculty->attendStudent(firstName, lastName, *relatedDate);
    
    return true;
}

bool MenuRunner::subBtn6(char symbol) {
    if (symbol != '6') return false;
    string group, date;
    cout << "Enter group name: " << endl;
    cin >> group;
    
    cout << "Enter lesson date:" << endl;
    cin >> date;
    
    vector<int> tokens;
    istringstream iss(date);
    string token;

    while (getline(iss, token, '/')) {
        try {
            int value = stoi(token);
            tokens.push_back(value);
        } catch (const invalid_argument& e) {
            cerr << "Invalid integer: " << token << endl;
            return false;
        } catch (const out_of_range& e) {
            cerr << "Integer out of range: " << token << endl;
            return false;
        }
    }
    
    if (tokens.size() < 2) return false;
    Date* relatedDate = new Date(tokens.at(0), tokens.at(1));
    _faculty->attendGroup(group, *relatedDate);
    return true;
}

bool MenuRunner::subBtn7(char symbol) {
    if (symbol != '7') return false;
    string date;
    cout << "Enter lesson date:" << endl;
    cin >> date;
    
    vector<int> tokens;
    istringstream iss(date);
    string token;

    while (getline(iss, token, '/')) {
        try {
            int value = stoi(token);
            tokens.push_back(value);
        } catch (const invalid_argument& e) {
            cerr << "Invalid integer: " << token << endl;
            return false;
        } catch (const out_of_range& e) {
            cerr << "Integer out of range: " << token << endl;
            return false;
        }
    }
    
    Date* relatedDate = new Date(tokens.at(0), tokens.at(1));
    cout << _faculty->showAttendees(*relatedDate);
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

string MenuRunner::showOptions() {
    stringstream result;
    result << "[1] - Add student" << endl <<
           "[2] - Remove student" << endl <<
           "[3] - Show students" << endl <<
           "[4] - Add student to group" << endl <<
           "[5] - Attend student" << endl <<
           "[6] - Attend group" << endl <<
           "[7] - Show attendees on date" << endl <<
           "[8] - Sort students with option" << endl;
    return result.str();
}
