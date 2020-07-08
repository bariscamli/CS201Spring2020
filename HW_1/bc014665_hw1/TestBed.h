#ifndef TESTBED_H
#define TESTBED_H

#include <iostream>
#include "SelectionAlgorithm.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortK.h"
using namespace std;
class TestBed {
private:
    SelectionAlgorithm *algorithm;
public:
    void execute();
    void setAlgorithm(int,int);
    TestBed();
    ~TestBed();
};


#endif // TESTBED_H
