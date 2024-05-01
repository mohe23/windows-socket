#ifndef CLOCKS_H_INCLUDED
#define CLOCKS_H_INCLUDED

class Clocks{
   public:
            Clocks(int newH, int newM, int newS); //构造函数。
            Clocks(Clocks &c);   //复制构造函数。
            void setTime(int newH, int newM, int newS); //成员函数，设置时间。
            void showTime();  // 显示时间。
            ~Clocks();       // 简单的析构函数。
   private:
             int Hour, Minute, Second;
};

void func1(Clocks c1);
Clocks func2();
#endif // CLOCKS_H_INCLUDED
