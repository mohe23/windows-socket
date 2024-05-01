#include <iostream>
#include"Point.h"
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    int i;
    Point b[2];//={Point(12, 34), Point(13, 34)};
    b[0].show();
    b[1].show();
    cout<<"Enter...."<<endl;
    Point a[2];
    for(i=0;i<2;i++)
        a[i].moves(i+10, i+20);
    cout<<"Exting..."<<endl;


    return 0;
}
