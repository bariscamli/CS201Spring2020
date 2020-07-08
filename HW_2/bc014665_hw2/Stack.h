//
// Created by baris on 27.03.2020.
//

#ifndef __STACK__
#define __STACK__
#include "StackItem.h"

class Stack {
private:
    StackItem *head ;
public:
    Stack();
    ~Stack();
    void push(StackItem*);
    StackItem* pop();
    StackItem* top();
    bool isEmpty();
};


#endif 
