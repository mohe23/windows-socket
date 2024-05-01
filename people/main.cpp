#include <iostream>
#include"people.h"
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;

    Date b1,b2;
    b1.setDate(2018, 4, 23);
    b2.setDate(2008, 7, 13);
    People p1(12, 'M', b1, "11234");
    p1.showPel();
    People p2 = p1;
    p2.showPel();
    p2.setPel(78, 'W', b2, "23455");
    p2.showPel();
    return 0;
}
