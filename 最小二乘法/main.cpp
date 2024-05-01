#include <iostream>
#include"Point.h"
#include<cmath>
using namespace std;

void Linefit(Point p[], int sum){ // 计算所得直线方程的拟合程度。
    float xx=0,yy=0,Lxx=0,Lxy=0,Lyy=0,r,a,b;
    int i;
    for(i=0;i<sum;i++){
        xx = xx + p[i].getX();
        yy = yy + p[i].getY();
    }
    xx = xx/sum;
    yy = yy/sum;

    for(i=0;i<sum;i++){
        Lxx =  Lxx + (p[i].getX() - xx)*(p[i].getX() - xx);
        Lxy =  Lxy + (p[i].getX() - xx)*(p[i].getY() - yy);
        Lyy =  Lyy + (p[i].getY() - yy)*(p[i].getY() - yy);
    }

    a = Lxy/Lxx;
    b = yy - a*xx;
    r = Lxy/(sqrt(Lxx*Lyy));

    cout<<"拟合直线为："<<"y = "<<a<<"x+"<<b<<endl;
    cout<<"拟合系数为： "<<r<<endl;
}


int main()
{
    //cout << "Hello world!" << endl;
    Point p[10]={Point(6,10), Point(14,20), Point(26,30), Point(33,40), Point(46,50), Point(54,60), Point(67,70), Point(75,80),
     Point(84,90), Point(100,100)};

     Linefit(p,10);
    return 0;
}
