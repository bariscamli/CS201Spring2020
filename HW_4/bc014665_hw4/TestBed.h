#ifndef __TESTBED__
#define __TESTBED__

#include <iostream>
#include "SelectionAlgorithm.h"
#include "AlgorithmSortAll.h"
#include "AlgorithmSortK.h"
#include "AlgorithmSortHeap.h"
#include "AlgorithmSortQuick.h"

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


#endif
