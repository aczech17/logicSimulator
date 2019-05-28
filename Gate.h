//
// Created by tytjan on 28.05.2019.
//

#ifndef LOGICSIMULATOR_GATE_H


typedef unsigned char uchar;
template <uchar inputCount>
class Gate
{
protected:
    void attachInput(uchar inputNumber, bool* inputPointer)
    {
        if(input[inputNumber] == nullptr)
            inputsAttached++;
        input[inputNumber] = inputPointer;
        if(inputsAttached == inputCount)
        {
            countOutputValue();
        }
    }
    bool **input;//tablica wskaznikow na boole
    bool *const0;
    bool *const1;
    bool *output;
    int propagationTime;//nanoseconds
    uchar inputsAttached;
    virtual void countOutputValue()=0;
public:
    explicit Gate(uchar propTime) : input(new bool*[inputCount]), propagationTime(propTime), output(new bool), inputsAttached(0), const0(new bool), const1(new bool)
    {
        input = new bool*[inputCount];
        propagationTime=propTime;
        for(uchar i = 0; i<inputCount; ++i)
        {
            input[i] = nullptr;
        }
        *const0=false;
        *const1=true;
    }//constructor

    void attach(uchar inputNumber, const bool inputValue)
    {
        if(inputValue == 0)
            attachInput(inputNumber, const0);
        else
            attachInput(inputNumber, const1);
    }

    void attach(uchar inputNumber, Gate <inputCount> &gate)
    {
        attachInput(inputNumber, gate.output);
    }

    bool outputValue()
    {
        return *output;
    }
    int givePropagationTime()
    {
        return propagationTime;
    }
};



#define LOGICSIMULATOR_GATE_H

#endif //LOGICSIMULATOR_GATE_H
