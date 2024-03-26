//
//  main.cpp
//  csdp250pp1+
//
//  Created by Chris Turnbull on 3/26/24.
//

#include <iostream>
#include <string>
#include "courseNodes.hpp"
using namespace std;
class CourseList {
private:
    CourseNode* head;

public:
    CourseList();
    ~CourseList();
    void addCourse(string code, int creditHours, char grade);
    void deleteCourse(string code);
    void deleteAllNodes();
    void displayList();
};

CourseList::CourseList() {
    head = nullptr;
}

CourseList::~CourseList() {
    deleteAllNodes();
}

void CourseList::addCourse(string code, int creditHours, char grade) {
    CourseNode* newNode = new CourseNode(code, creditHours, grade);
    if (!head || head->code > code) {
        newNode->next = head;
        head = newNode;
    } else {
        CourseNode* current = head;
        while (current->next && current->next->code < code) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void CourseList::deleteCourse(string code) {
    CourseNode* current = head;
    CourseNode* previous = nullptr;

    while (current && current->code != code) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        cout << "Course not found." << endl;
        return;
    }

    if (!previous) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
}

void CourseList::deleteAllNodes() {
    while (head) {
        CourseNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void CourseList::displayList() {
    CourseNode* current = head;
    while (current) {
        cout << "Code: " << current->code << ", Credit Hours: " << current->creditHours << ", Grade: " << current->grade << endl;
        current = current->next;
    }
}

int main() {
    CourseList list;

    
    for (int i = 0; i < 10; ++i) {
        string code;
        int creditHours;
        char grade;

        cout << "Enter course code: ";
        cin >> code;
        cout << "Enter credit hours: ";
        cin >> creditHours;
        cout << "Enter grade: ";
        cin >> grade;

        list.addCourse(code, creditHours, grade);
    }

  
    cout << "List before deletion:" << endl;
    list.displayList();

    
    for (int i = 0; i < 2; ++i) {
        string code;
        cout << "Enter course code to delete: ";
        cin >> code;
        list.deleteCourse(code);

        // Display list after deletion
        cout << "List after deletion:" << endl;
        list.displayList();
    }

    return 0;
}
