#ifndef E5131_H_INCLUDED
#define E5131_H_INCLUDED

#ifndef E513_H_INCLUDED
#define E513_H_INCLUDED

class X;
class Y{
public:
    void g(X*);

};

class X{
public:
    X(){i=0;}
    friend void h(X*);
    friend void Y::g(X*);
    friend class Z;
private:
    int i;
};

void h(X*x){x->i =+ 10;}
void Y::g(X*x){x->i++;}

class Z{
public:
    void f(X*x){x->i += 5;}
};
#endif // E513_H_INCLUDED


#endif // E5131_H_INCLUDED
