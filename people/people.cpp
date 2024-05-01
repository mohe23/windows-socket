#include<iostream>
#include<string>
#include"people.h"
using namespace std;

//:birthday(date)
People::People(int num, char se, Date date, string di){ // 构造函数。
          number = num;
          sex = se;
          birthday = date;
          id = di;
        cout<<"People, 构造函数！！！！"<<endl;
}


People::People(People &p):birthday(p.birthday){ // 复制构造函数。
         number = p.number;
         sex = p.sex;
         id = p.id;
     cout<<"People,  复制构造函数！！"<<endl;
}


void People::setPel(int n2, char s2, Date d2, string i2){  // 设置相关信息。
       number = n2;
       sex = s2;
       birthday = d2;
       id = i2;
}


void People::showPel(){ // 显示相关信息。
       cout<<"编号： "<<number<<endl;
       cout<<"性别： "<<sex<<endl;
       cout<<"出生日期：";
       birthday.showDate();
       cout<<"身份证号："<<id<<endl;
}
