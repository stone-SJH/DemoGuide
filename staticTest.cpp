#include<iostream>
using namespace std;
/*
int f(int a)
{
	static int b = 2;
	cout << "f: b = " << b << endl;
	b = b + a;
	cout << "f: b = " << b << endl;
	return b;
}

int rf(int a)
{
	int k = 2;
	cout << "rf : k = " << k << endl;
	k = k + a;
	cout << "rf : k = " << k << endl;
	return k;
}
int main()
{
	int ret, rett;
	ret = f(3);
	rett = rf(3);
	cout << "ret = " << ret << endl;
	cout << "rett = " << rett << endl;
	ret = f(1);
	rett = rf(1);
	cout << "ret = " << ret << endl;
	cout << "rett = " << rett << endl;
	ret = f(4);
	rett = rf(4);
	cout << "ret = " << ret << endl;
	cout << "rett = " << rett << endl;
	return 0;
}
*/
/*
class A
{
private:
	static int i;
public:
	int kk;
	static int k;

	A();
	void add(int num);
};

A::A(){
	kk = 1;
	k = 10;
}

void A::add(int num){
	k += num;
}

int A::i = 1;
int A::k = 5;
int main()
{
	cout << A::k << endl;
	A test1;
	test1.add(5);
	cout << test1.k << endl;
	cout << A::k << endl;
	A test2;
	test2.add(10);
	cout << test2.k << endl;
	cout << test1.k << endl;
	cout << A::k << endl;
}
*/
/*
int main(){
	int num = 1;
	int const a = 10; 
	const int b = 10;
	int const *c = &a;
	int * const d = (int *)num;
	int const * const e = (int *)b;
}
*/