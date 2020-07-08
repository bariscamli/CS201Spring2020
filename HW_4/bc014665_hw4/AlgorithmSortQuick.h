//
// Created by baris on 12.05.2020.
//

#ifndef _ALGORITHMSORTQUICK_
#define _ALGORITHMSORTQUICK_

#include "SelectionAlgorithm.h"

class AlgorithmSortQuick :public SelectionAlgorithm{
public:
    int select();
    int quickselect(int*,int,int,int);
    AlgorithmSortQuick(int);
};


#endif
