#ifndef CLOCKS_H_INCLUDED
#define CLOCKS_H_INCLUDED

class Clocks{
   public:
            Clocks(int newH, int newM, int newS); //���캯����
            Clocks(Clocks &c);   //���ƹ��캯����
            void setTime(int newH, int newM, int newS); //��Ա����������ʱ�䡣
            void showTime();  // ��ʾʱ�䡣
            ~Clocks();       // �򵥵�����������
   private:
             int Hour, Minute, Second;
};

void func1(Clocks c1);
Clocks func2();
#endif // CLOCKS_H_INCLUDED
