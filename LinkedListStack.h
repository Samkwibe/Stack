#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H

#include <string>

struct Student {
    std::string name;
    std::string id;
    std::string phone;
    std::string address;
};

struct Node {
    Student data;
    Node* next;
};

class LinkedListStack {
private:
    Node* top;
    int size;

public:
    LinkedListStack();
    ~LinkedListStack();
    void push(const Student& student);
    Student pop();
    int getSize() const;
    bool isEmpty() const;
    Student topStudent() const;
};

#endif // LINKEDLISTSTACK_H
