//#define MVIRTUAL
#ifdef MVIRTUAL

#include <iostream>
using namespace std;

class A{
public:
	virtual void print(){
		cout << "A" << endl;
	}
};

class B : public A{
public:
	virtual void print(){
		cout << "B" << endl;
	}
};

class C :public A{
public:
	virtual void print(){
		cout << "C" << endl;
	}
};

class D :public B{
public:
	void print(){
		cout << "D" << endl;
	}
};

class E :public B{
public:
	virtual void print(){
		cout << "E" << endl;
	}
};

class F :public C{
public:
	virtual void print(){
		cout << "F" << endl;
	}
};

class G :public C{
public:
	void print(){
		cout << "G" << endl;
	}
};

void Handle(A *a)
{
	if (dynamic_cast<B*>(a))
	{
		cout << "I am a B truly." << endl;
	}
	else if (dynamic_cast<C*>(a))
	{
		cout << "I am a C truly." << endl;
	}
	else
	{
		cout << "I am alone." << endl;
	}
}

class A1{
public:
	virtual void print(){
		cout << "A1" << endl;
	}
};
class B1 : public A1{
public:
	void print(){
		cout << "B1" << endl;
	}
};
class C1 : public A1{
public:
	void print(){
		cout << "C1" << endl;
	}
};

int main(){
	/*
	A* b = new B;
	A* test0 = static_cast<A *>(b);
	B* test1 = static_cast<B *>(b);
	C* test2 = static_cast<C *>(b);
	D* test3 = static_cast<D *>(b);
	E* test4 = static_cast<E *>(b);
	F* test5 = static_cast<F *>(b);
	G* test6 = static_cast<G *>(b);
	test0->print();
	test1->print();
	test2->print();
	test3->print();
	test4->print();
	test5->print();
	test6->print();
	
	return 0;
	*/
	/*
	A *pA = new B();
	Handle(pA);
	delete pA;
	pA = new C();
	Handle(pA);
	delete pA;
	pA = new A();
	Handle(pA);
	delete pA;
	return 0;
	*/
	/*
	const A* test0 = new B;
	A* test1 = const_cast<A*>(test0);
	//A* test2 = static_cast<A*>(test0);//error
	test1->print();
	B* test2 = dynamic_cast<B*>(test1);
	test2->print();
	return 0;
	*/
	/*
	A test0;
	B test1;
	A* a1 = dynamic_cast<A*>(&test0);
	a1->print();
	A* a2 = dynamic_cast<A*>(&test1);
	a2->print();
	//B* b1 = dynamic_cast<B*>(&test0);//b1 = NULL
	B* b2 = dynamic_cast<B*>(&test1);
	b2->print();
	*/
	/*
	B1* test1 = new B1();
	C1* test2 = dynamic_cast<C1*> (test1);//test2 = NULL
	*/
	/*
	A* a = new A();
	int aa = reinterpret_cast<int>(a);
	cout << aa << endl;
	A* b = reinterpret_cast<A*>(aa);
	b->print();
	*/
}
#endif