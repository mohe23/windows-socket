#include <iostream>
#include"Clocks.h"
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    Clocks c1(12,23,56);
    Clocks c2(c1);
    Clocks c3 = c2;
    Clocks c4(0,0,0);
    c1.showTime();
    c2.showTime();
    c3.showTime();
    func1(c1);
    c4 = func2();
    c4.showTime();
    return 0;
}
