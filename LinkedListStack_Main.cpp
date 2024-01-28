/*
Samuel KWibe
 ID # 2278332
 Email: Samuel.kwibe@snhu.edu
 class :217
In - Class Assignment # 4
Array - Based Stack

In this assignment, I'm going to build a program that's a stack for keeping track of student records.
Each record in this stack will include details like the student's name, ID, phone number,
and home address. My task is to enable adding new records on top of the stack, which
is known as "pushing," and also removing the most recent record, referred to as "popping."
Besides these, I'll also make functions to check how many records are currently in the stack,
see if the stack is empty, and find out who the most recent student added is.
*/



#include "LinkedListStack.h"
#include <iostream>
using namespace std;

void displayMenu(); // for the menu
void performPush(LinkedListStack& stack);
void performPop(LinkedListStack& stack);
void displayTop(const LinkedListStack& stack);

int main() {
    LinkedListStack stack;
    char choice;
     // This is the while loop that keep on repeating, and cheking the record in the stack
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case '1':
            performPush(stack);
            break;
        case '2':
            performPop(stack);
            break;
        case '3':
            cout << " The number of the students in the stack is: " << stack.getSize() << endl; // this will show the number of the student  that are in the stack
            break;
        case '4':
            cout << (stack.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl; // this will wcheck if the stack is empty or not
            break;
        case '5':
            displayTop(stack); // this will display ofll the information that are in the stack
            break;
        case '6':
            cout << "Exiting program." << endl; // the option for exiting the application
            break;
        default:
            cout << "Invalid choice. Please try again." << endl; // this will be shown when the user input the wrong choice
        }
    } while (choice != '6');

    return 0;
}

void displayMenu() {
    cout << "+=================SNHU STUDNTS STACK=========================+" << endl;
    cout << "1. Push (Add a student)\n";
    cout << "2. Pop (Remove the most recent student)\n";
    cout << "3. Size (Get the number of students in the stack)\n";
    cout << "4. Empty (Check if the stack is empty)\n";
    cout << "5. Top (View the most recent student)\n";
    cout << "6. Exit\n";
    cout << "+===========================================================+" << endl;
    cout << "Enter your choice: ";

}

void performPush(LinkedListStack& stack) {
    Student newStudent;
    cout << "Enter student's name: ";
    cin.ignore(); // this will hel[ to free the memory space for the new line
    getline(cin, newStudent.name); // ask the user to enter student name
    cout << "Enter student's ID: ";
    getline(cin, newStudent.id);// for tj student ID
    cout << "Enter student's phone number: ";
    getline(cin, newStudent.phone);// phone Number
    cout << "Enter student's address: ";
    getline(cin, newStudent.address); // address
    stack.push(newStudent);
    cout << "Student added to stack." << endl;
}

void performPop(LinkedListStack& stack) {
    if (stack.isEmpty()) {
        cout << "Stack is empty. No students to remove." << endl;
    }
    else {
        Student removedStudent = stack.pop();
        cout << "Student " << removedStudent.name << " removed from stack." << endl;
    }
}

void displayTop(const LinkedListStack& stack) {
    if (stack.isEmpty()) {
        cout << "Stack is empty. No student to display." << endl;
    }
    else {
        cout << "+=================SNHU STUDNTS STACK=========================+" << endl;
        Student topStudent = stack.topStudent();
        cout << "Most recent student details:" << endl;
        cout << "Name: " << topStudent.name << endl;
        cout << "ID: " << topStudent.id << endl;
        cout << "Phone: " << topStudent.phone << endl;
        cout << "Address: " << topStudent.address << endl;
        cout << "+===========================================================+" << endl;
    }
}


