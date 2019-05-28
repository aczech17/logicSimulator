//
// Created by tytjan on 28.05.2019.
//

#ifndef LOGICSIMULATOR_OR_H
#define LOGICSIMULATOR_OR_H

#include "Gate.h"
template <uchar inputCount = 2>
class Or :public Gate<inputCount>
{
    virtual void countOutputValue()
    {
        bool outVal = false;
        for(int i = 0; i < this->inputsAttached; ++i)
        {
            outVal |= *(this->input[i]);
            if(outVal == 1) break;
        }
        *(this->output) = outVal;
    }
public:
    explicit Or(uchar propTime=20) : Gate<inputCount>(propTime) {}

};
#endif //LOGICSIMULATOR_OR_H