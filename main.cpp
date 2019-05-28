#include <iostream>
#include "And.h"
#include "Or.h"
#define huj cout<<and1.isSpecified()<<endl;
using namespace std;

int main()
{
    And <2> and1;

    and1.attachInput(0, true);
    and1.attachInput(1, false);

    Or <2> or1;
    or1.attachInput(0, and1.output);
    or1.attachInput(1, false);

    cout<<or1.outputValue();

}