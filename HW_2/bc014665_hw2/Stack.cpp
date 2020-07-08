#include "Stack.h"

Stack::Stack() {
    this->head = 0;
}

Stack::~Stack() {
    StackItem *stackPtr = head;
    while(head != 0) {
        head = head->next;
        delete stackPtr;
        stackPtr = head;
    }
}

void Stack::push(StackItem *item) {
    item->next = head;
    this->head = item;
}

StackItem *Stack::pop() {
    StackItem *stackPtr = this->head;
    this->head = this->head->next;
    stackPtr->next = 0;
    return stackPtr;
}

StackItem *Stack::top() {
    return this->head;
}

bool Stack::isEmpty() {
    return this->head == 0;
}