#include <iostream>
using namespace std;
#define VIRTUAL
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

#define PVFUNC
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
	int a;
	cin >> a;
}
#endif