#include<iostream>
using namespace std;
#ifndef INHERIT
//#define INHERIT
class A
{
private:
	int privatedateA;
protected:
	int protecteddateA;
public:
	int publicdateA;
};
class B :public A
{
public:
	void funct()
	{
		int b;
		//b = privatedateA;   //error��������˽�г�Ա�����������ǲ��ɼ���
		b = protecteddateA; //ok������ı�����Ա����������Ϊ������Ա
		b = publicdateA;    //ok������Ĺ�����Ա����������Ϊ������Ա
	}
};
class C :private A
{
public:
	void funct()
	{
		int c;
		//c = privatedateA;    //error��������˽�г�Ա�����������ǲ��ɼ���
		c = protecteddateA;  //ok������ı�����Ա����������Ϊ˽�г�Ա
		c = publicdateA;     //ok������Ĺ�����Ա����������Ϊ˽�г�Ա
	}
};
class D :protected A
{
public:
	void funct()
	{
		int d;
		//d = privatedateA;   //error��������˽�г�Ա�����������ǲ��ɼ���
		d = protecteddateA; //ok������ı�����Ա����������Ϊ������Ա
		d = publicdateA;    //ok������Ĺ�����Ա����������Ϊ������Ա
	}
};

int main()
{
#ifdef INHERIT
	A* test1 = new B();
	//A* test2 = new C(); //error
	//A* test3 = new D(); //error
	
	int a;

	A* objB = new B();
	//a = objB->privatedateA;   //error��������˽�г�Ա�����������ǲ��ɼ���,�Զ��󲻿ɼ�
	//a = objB->protecteddateA; //error������ı�����Ա����������Ϊ������Ա���Զ��󲻿ɼ�
	a = objB->publicdateA;    //ok������Ĺ�����Ա����������Ϊ������Ա���Զ���ɼ�

	C objC;
	//a = objC.privatedateA;   //error��������˽�г�Ա�����������ǲ��ɼ���,�Զ��󲻿ɼ�
	//a = objC.protecteddateA; //error������ı�����Ա����������Ϊ˽�г�Ա���Զ��󲻿ɼ�
	//a = objC.publicdateA;    //error������Ĺ�����Ա����������Ϊ˽�г�Ա���Զ��󲻿ɼ�

	D objD;
	//a = objD.privatedateA;   //error��������˽�г�Ա�����������ǲ��ɼ���,�Զ��󲻿ɼ�
	//a = objD.protecteddateA; //error������ı�����Ա����������Ϊ������Ա���Զ��󲻿ɼ�
	//a = objD.publicdateA;    //error������Ĺ�����Ա����������Ϊ������Ա���Զ��󲻿ɼ�
#endif
}
#endif