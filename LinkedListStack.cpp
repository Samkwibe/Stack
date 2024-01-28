#include "LinkedListStack.h"
#include <string>

LinkedListStack::LinkedListStack() : top(nullptr), size(0) {}

LinkedListStack::~LinkedListStack() {
    while (!isEmpty()) {
        pop();
    }
}

void LinkedListStack::push(const Student& student) {
    Node* newNode = new Node{ student, top };
    top = newNode;
    size++;
}

Student LinkedListStack::pop() {
    if (top != nullptr) {
        Node* nodeToDelete = top;
        top = top->next;
        Student student = nodeToDelete->data;
        delete nodeToDelete;
        size--;
        return student;
    }
    return Student{}; // Return an empty student if the stack is empty
}

int LinkedListStack::getSize() const {
    return size;
}

bool LinkedListStack::isEmpty() const {
    return top == nullptr;
}

Student LinkedListStack::topStudent() const {
    if (top != nullptr) {
        return top->data;
    }
    return Student{}; // Return an empty student if the stack is empty
}
