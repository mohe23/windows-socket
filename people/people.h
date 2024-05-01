#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED

#include<iostream>
using namespace std;

class Date{
   public:
      // Date(Date &de){ // 复制构造函数。
        //   Year = de.Year;
          // Month = de.Month;
          // Day = de.Day;
       //}

       void setDate(int y2, int m2, int d2){
             Year = y2;
             Month = m2;
             Day = d2;
       }

       void showDate(){
            cout<<Year<<"年 "<<Month<<"月 "<<Day<<"日"<<endl;
       }

   private:
       int Year, Month, Day;
};



class People{
    public:
        People(int num, char se, Date date, string di); //构造函数。
        People(People &p); //复制构造函数。
        void setPel(int n2, char s2, Date d2, string i2); // 设置
        void showPel(); //显示相关信息。
        ~People(){ // 析构函数，同时这也是1个内联函数。
             cout<<"People, 析构函数!!!"<<endl;
        }

    private:
        int number; //编号
        char sex; // 性别，M-男，W-女。
        Date birthday; //出生日期。
        string id; // 身份证号。


};
#endif // PEOPLE_H_INCLUDED
