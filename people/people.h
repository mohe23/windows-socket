#ifndef PEOPLE_H_INCLUDED
#define PEOPLE_H_INCLUDED

#include<iostream>
using namespace std;

class Date{
   public:
      // Date(Date &de){ // ���ƹ��캯����
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
            cout<<Year<<"�� "<<Month<<"�� "<<Day<<"��"<<endl;
       }

   private:
       int Year, Month, Day;
};



class People{
    public:
        People(int num, char se, Date date, string di); //���캯����
        People(People &p); //���ƹ��캯����
        void setPel(int n2, char s2, Date d2, string i2); // ����
        void showPel(); //��ʾ�����Ϣ��
        ~People(){ // ����������ͬʱ��Ҳ��1������������
             cout<<"People, ��������!!!"<<endl;
        }

    private:
        int number; //���
        char sex; // �Ա�M-�У�W-Ů��
        Date birthday; //�������ڡ�
        string id; // ���֤�š�


};
#endif // PEOPLE_H_INCLUDED
