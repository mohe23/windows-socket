#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

class Point{
    public:
            Point(int xx=0, int yy=0){ //���캯����
                   x = xx;
                   y = yy;
            }
            Point(Point &p); //���ƹ��캯��
            int getX(){
                 return x;
            }
            int getY(){
                 return y;
            }
    private:
        int x, y;
};


class Line{  // ����ࡣ
public:
    Line(Point xp1, Point xp2); //���캯����
    Line(Line &l); // ���ƹ��캯����
    double getLen(){
         return len;
    }
private:
    Point p1, p2;  //Point��ĳ�Ա��
    double len;

};
#endif // LINE_H_INCLUDED
