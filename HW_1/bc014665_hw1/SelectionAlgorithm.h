#ifndef SELECTIONALGORITHM_H
#define SELECTIONALGORITHM_H

#include <iostream>

class SelectionAlgorithm {
protected:
    int k;
public:
    virtual int select();
    SelectionAlgorithm(int);
};


#endif // SELECTIONALGORITHM_H
