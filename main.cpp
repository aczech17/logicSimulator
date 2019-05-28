#include <iostream>
#include "And.h"
#include "Or.h"
using namespace std;

int main()
{
    And <2> and1;
    and1.attach(0, false);
    and1.attach(1, true);

    Or<2> or1;
    or1.attach(0, and1);
    or1.attach(1, and1);

    cout<<or1.outputValue();
}