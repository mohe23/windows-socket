#include"Clocks.h"
#include<iostream>

using namespace std;


Clocks::Clocks(int newH, int newM, int newS){ //在类外实现函数体。
      Hour = newH;
    Minute = newM;
    Second = newS;

}



Clocks::Clocks(Clocks &c){ // 复制构造函数。
       Hour = c.Hour;
       Minute = c.Minute;
       Second = c.Second;
}


void Clocks::setTime(int newH, int newM, int newS){
      Hour = newH;
    Minute = newM;
    Second = newS;
}


void Clocks::showTime(){

  cout<<Hour<<"::"<<Minute<<"::"<<Second<<endl;
}


void func1(Clocks c1){ // 将类的对象作为形参。
      cout<<"输出时间：";
      c1.showTime();
}


Clocks func2(){ // 返回值为Clocks类的对象。
      Clocks c2(13,45,56);

      return c2;
}


Clocks::~Clocks(){  //析构函数。
     cout<<"已调用析构函数，执行清理工作。"<<endl;
}
