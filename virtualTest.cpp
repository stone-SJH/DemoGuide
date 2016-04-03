#include <iostream>
using namespace std;
#ifndef VIRTUAL
#define VIRTUAL

#ifndef VFUNC
//#define VFUNC
class father
{
public:
	father(){};
	father(int i){ age = i; }
	father(father &f) :age(f.age){}
	virtual void print(){ cout << "father's age is " << age << endl; }
	virtual void is_print(){ cout << "father's print\n"; }
protected:
	int age;
};

class son :public father
{
public:
	son(){};
	son(int j){ age = j; }
	void print(){ cout << "son's age is " << age << endl; }
};

class daughter:public father
{
public:
	daughter(){};
	daughter(int i){
		age = i;
	}
	void print(){
		cout << "daughter's age is " << age << endl;
	}
	void print(int k){
		cout << "daughter's age is " << age << endl;
	}
};
#endif

#ifndef PVFUNC
//#define PVFUNC
class Person{
protected:
	enum Sex{
		male,
		female
	};	
	int age;
	Sex sex;
public:
	Person(){};
	virtual void func1(){
		cout << "person" << endl;
	}
	virtual void func2() = 0;
};

class Father : public Person{
public:
	Father(int i){
		age = i;
		sex = Person::male;
	}
	/*void func1(){
		cout << "father" << endl;
	}*/
	void func2(){
		cout << "Adult!" << endl;
	}
};

class Son : public Person{
public:
	Son(int i){
		age = i;
		sex = Person::male;
	}
	void func1(){
		cout << "son" << endl;
	}
	void func2(){
		cout << "Teen!" << endl;
	}
};
#endif

#ifndef VTABLE
#define VTABLE
class Base1 {
public:
	virtual void f() 
	{ 
		cout << "Base1::f" << endl; 
	}
	virtual void g() 
	{ 
		cout << "Base1::g" << endl;
	}
	void h()//����ķ��麯��
	{ 
		cout << "Base1::h" << endl;
	}

};

class Base2 {
public:
	virtual void f() 
	{ 
		cout << "Base2::f" << endl; 
	}
	virtual void g() 
	{ 
		cout << "Base2::g" << endl; 
	}
private:
	virtual void h() //�麯��Ϊprivate�����������޷�����
	{ 
		cout << "Base2::h" << endl; 
	}
};

class Base3 {
public:
	virtual void f() 
	{ 
		cout << "Base3::f" << endl; 
	}
	virtual void g()
	{ 
		cout << "Base3::g" << endl;
	}
	virtual void h() 
	{ 
		cout << "Base3::h" << endl;
	}
};


class Derive : public Base1, public Base2, public Base3 {
public:
	virtual void f()//���¶�������е��麯��
	{ 
		cout << "Derive::f" << endl; 
	}
	virtual void g1()//�¶��庯��
	{ 
		cout << "Derive::g1" << endl;
	}
	void h1()
	{
		cout << "Derive::h1" << endl;
	}
};


typedef void (*Fun)();
#endif

#ifdef VIRTUAL
int main()
{
#ifdef VFUNC
	father* s1 = new father(56);
	s1->print();
	//father *s2=new son(22);
	father &s2 = son(22);
	s2.print();
	s2.is_print();
	father* s3 = new daughter(17);
	s3->print();
#endif
#ifdef PVFUNC
	Person *s1 = new Father(46);
	s1->func1();
	s1->func2();
	Person *s2 = new Son(15);
	s2->func1();
	s2->func2();
	Father *s3 = new Father(59);
	s3->func1();
	s3->func2();
	Father s4(50);
	Person &s5 = s4;
	s5.func1();
	s5.func2();
#endif
#ifdef VTABLE
	Fun pFun = NULL;

	Derive d;
	int** pVtab = (int**)&d;

	//Base1's vtable
	//pFun = (Fun)*((int*)*(int*)((int*)&d+0)+0);
	pFun = (Fun)pVtab[0][0];
	pFun();

	//pFun = (Fun)*((int*)*(int*)((int*)&d+0)+1);
	pFun = (Fun)pVtab[0][1];
	pFun();
	
	//Derive's vtable
	//pFun = (Fun)*((int*)*(int*)((int*)&d+0)+2);
	pFun = (Fun)pVtab[0][2];
	pFun();

	//no Base1::h and Derive::h1
	//���麯��������������ʵ����vtable��

	//pFun = (Fun)*((int*)*(int*)((int*)&d+0)+3);
	pFun = (Fun)pVtab[0][3];
	//pFun();
	cout << pFun << endl;



	//Base2's vtable
	//pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);
	pFun = (Fun)pVtab[1][0];
	pFun();

	//pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);
	pFun = (Fun)pVtab[1][1];
	pFun();

	//pFun = (Fun)*((int*)*(int*)((int*)&d+1)+2);
	pFun = (Fun)pVtab[1][2];//����Private���麯����Ȼ�������vtable��
	pFun();//ͨ��vtable�Ƿ����ʱ������ʲ����ĸ���private�麯��

	//vtable' tail
	pFun = (Fun)pVtab[1][3];
	cout << pFun << endl;



	//Base3's vtable
	//pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);
	pFun = (Fun)pVtab[2][0];
	pFun();

	//pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);
	pFun = (Fun)pVtab[2][1];
	pFun();

	//pFun = (Fun)*((int*)*(int*)((int*)&d+1)+2);
	pFun = (Fun)pVtab[2][2];
	pFun();

	//vtable' tail
	pFun = (Fun)pVtab[2][3];
	cout << pFun << endl;


	//Base1 *b1 = new Derive();
	//b1->g1(); //error������ָ���޷���������δ���Ǹ����Ա�麯�����麯��
	Base1 *b1 = new Derive();
	int** b1Vtab = (int**)b1;
	pFun = (Fun)b1Vtab[0][2];
	pFun();//ͨ�������ʵ���Derive::g1

#endif
	int a;
	cin >> a;
}
#endif
#endif