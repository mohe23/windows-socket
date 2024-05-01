#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point{
public:
    Point(float x=0, float y=0):x(x),y(y){}
    float getX()  {return x;}
    float getY()  {return y;}

private:
    float x,y;
};

#endif // POINT_H_INCLUDED
