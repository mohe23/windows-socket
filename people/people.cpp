#include<iostream>
#include<string>
#include"people.h"
using namespace std;

//:birthday(date)
People::People(int num, char se, Date date, string di){ // ���캯����
          number = num;
          sex = se;
          birthday = date;
          id = di;
        cout<<"People, ���캯����������"<<endl;
}


People::People(People &p):birthday(p.birthday){ // ���ƹ��캯����
         number = p.number;
         sex = p.sex;
         id = p.id;
     cout<<"People,  ���ƹ��캯������"<<endl;
}


void People::setPel(int n2, char s2, Date d2, string i2){  // ���������Ϣ��
       number = n2;
       sex = s2;
       birthday = d2;
       id = i2;
}


void People::showPel(){ // ��ʾ�����Ϣ��
       cout<<"��ţ� "<<number<<endl;
       cout<<"�Ա� "<<sex<<endl;
       cout<<"�������ڣ�";
       birthday.showDate();
       cout<<"���֤�ţ�"<<id<<endl;
}
