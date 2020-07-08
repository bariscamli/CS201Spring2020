#ifndef __SELECTIONALGORITHM__
#define __SELECTIONALGORITHM__

#include <iostream>

class SelectionAlgorithm {
protected:
    int k;
public:
    virtual int select();
    SelectionAlgorithm(int);
};


#endif
