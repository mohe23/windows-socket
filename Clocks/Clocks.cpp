#include"Clocks.h"
#include<iostream>

using namespace std;


Clocks::Clocks(int newH, int newM, int newS){ //������ʵ�ֺ����塣
      Hour = newH;
    Minute = newM;
    Second = newS;

}



Clocks::Clocks(Clocks &c){ // ���ƹ��캯����
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


void func1(Clocks c1){ // ����Ķ�����Ϊ�βΡ�
      cout<<"���ʱ�䣺";
      c1.showTime();
}


Clocks func2(){ // ����ֵΪClocks��Ķ���
      Clocks c2(13,45,56);

      return c2;
}


Clocks::~Clocks(){  //����������
     cout<<"�ѵ�������������ִ����������"<<endl;
}
