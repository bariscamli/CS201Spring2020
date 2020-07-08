//============================================================================
// Name        : BinaryHeap.cpp
// Author      : Hasan Sozer
// Version     : 1.2
// Copyright   : (c) 2013 Ozyegin University
// Description : Includes the (incomplete) implementation file of the
//               BinaryHeap class that will be used as part of the program
//               to be submitted as Homework 3, which is assigned in the
//               context of the course CS201, Data Structures and Algorithms.
//
//               THE IMPLEMENTATION MUST BE COMPLETED TO MAKE ALL THE TESTS
//               IN THE MAIN METHOD PASS.
//
//               After completing the heap implementation, "BinaryHeap.h" and
//               "BinaryHeap.cpp" files will be used for extending homework 1,
//               and the extended program will be submitted as Homework 3.
//============================================================================

#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(int capacity) {
    this->capacity = capacity;
    heap = new int[capacity+1];
    size = 0;
}

BinaryHeap::~BinaryHeap() {
    delete [] heap;
}

void BinaryHeap::insert(int element) {
    if(size <= capacity){
        int hole = ++size;
        while(hole > 1 &&  element < heap[hole/2]){
            heap[hole] = heap[hole/2];
            hole /=2;
        }
        heap[hole] = element;
    }
}

void BinaryHeap::deleteMin() {
    if(size == 1){
        heap[1] = 0;
        size -=1;
    }
    else if(size > 1){
        heap[1] = heap[size];
        heap[size] = 0;
        size -= 1;
        percolateDown(1);
    }
}

int BinaryHeap::getMin() {
    if(size < 1){
        return -1;
    }
    else{
        return heap[1];
    }
}

void BinaryHeap::percolateDown(int hole) {
    if(2*hole+1 <= size){
        if(((heap[2*hole+1] > heap[hole]) && (heap[2*hole] > heap[hole])) ){

        }
        else if( heap[2 * hole] > heap[2 * hole + 1] ){
            swap(hole,2*hole+1);
            percolateDown(2*hole+1);
        }
        else{
            swap(hole,2*hole);
            percolateDown(2*hole);
        }
    }
}

void BinaryHeap::swap(int i, int j) {
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}
