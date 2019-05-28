//
// Created by tytjan on 28.05.2019.
//

#ifndef LOGICSIMULATOR_AND_H
#define LOGICSIMULATOR_AND_H

#include "Gate.h"
#include <iostream>//DEBUG
using namespace std;//DEBUG
template <uchar inputCount=2>
class And :public Gate<inputCount>
{
protected:
    virtual void countOutputValue()
    {
        bool outVal=true;
        for(int i = 0; i<this->inputsAttached; ++i)
        {
            outVal &= *(this->input[i]);
            if(outVal == 0) break;
        }
        *(this->output) = outVal;
    }
public:
    explicit And(uchar propTime=20) : Gate <inputCount> (propTime) {}

};

#endif //LOGICSIMULATOR_AND_H
