#include <iostream>
#include"Line.h"
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    Point myp1(1,1),myp2(4,5); // Point类对象
    Line line(myp1,myp2);      // Line类对象。
    Line line2(line);

    cout<<line.getLen()<<endl;
    cout<<line2.getLen()<<endl;
    return 0;
}
