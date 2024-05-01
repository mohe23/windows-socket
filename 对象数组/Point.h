#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point{
public:
    Point();
    Point(int x, int y);
    ~Point();
    void moves(int newX, int newY);
    int getX() const {return x;}
    int getY() const {return y;}
    void show();
    static void showCount(); //¾²Ì¬º¯Êý³ÉÔ±¡£

private:
    int x, y;
};


#endif // POINT_H_INCLUDED
