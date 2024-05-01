#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

class Point{
    public:
            Point(int xx=0, int yy=0){ //构造函数。
                   x = xx;
                   y = yy;
            }
            Point(Point &p); //复制构造函数
            int getX(){
                 return x;
            }
            int getY(){
                 return y;
            }
    private:
        int x, y;
};


class Line{  // 组合类。
public:
    Line(Point xp1, Point xp2); //构造函数。
    Line(Line &l); // 复制构造函数。
    double getLen(){
         return len;
    }
private:
    Point p1, p2;  //Point类的成员。
    double len;

};
#endif // LINE_H_INCLUDED
