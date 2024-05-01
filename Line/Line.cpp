#include <iostream>
#include<cmath>
#include"Line.h"
using namespace std;


Point::Point(Point &p){
   x = p.x;
   y = p.y;
   cout<<"Calling the copy constructor of Point"<<endl;
}


Line::Line(Point xp1, Point xp2):p1(xp1),p2(xp2){// ¹¹Ôìº¯Êý
     double x, y;
     cout<<"Calling constructor of Line"<<endl;
     x = p1.getX() - p2.getX();
     y = p1.getY() - p2.getY();
     len = sqrt(x*x + y*y);
}


Line::Line(Line &l):p1(l.p1),p2(l.p2){
     cout<<"Calling the copy constructor of Line"<<endl;
     len = l.len;

}
