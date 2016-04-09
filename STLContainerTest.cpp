#ifndef CONTAINER
#define CONTAINER
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
using namespace std;

class Foo{
private:
	int con;
public:
	Foo(){ con = 0; }
	Foo(int i){ con = i; }
};
int main(){
//#define INIT
#ifdef INIT
	vector<int> test1(10, 0);

	vector<int> test2(test1);

	vector<int>::iterator i1 = test1.begin();
	vector<int>::iterator i2 = test1.end();
	vector<int> test3(i1, i1 + 1);

	int n = 10, content = 5;
	vector<int> test4(n, content);

	vector<int> test5(n);

	vector<Foo> test6(10, 1);
	vector<Foo> test7(10);

#endif
#define OPERATION
#ifdef OPERATION
	list<int> test1;
	test1.push_back(5);
	list<int>::iterator i1 = test1.end();//end()代表最后一个元素的后一个位置
	list<int>::iterator i2 = test1.begin();
	list<int>::reverse_iterator ri1 = test1.rbegin();//rbegin()代表第一个元素的前一个位置
	list<int>::reverse_iterator ri2 = test1.rend();//rend()代表最后一个元素
	//i2++;
	//i1 = i1 + 10;//error
	//i1 = i1 - i2;//error
	//while (i1 < i2) //error
	vector<string> test2;
	test2.push_back("");
	test2.push_back("b");
	vector<string>::iterator i3 = test2.begin();
	if (i3->empty())//i3相当于一个string指针
		cout << "empty" << endl;

	test1.push_front(6);//只适用于list deque
	//添加操作后原迭代器失效
	i1 = test1.begin();
	i2 = test1.end();
	list<int>::iterator i4 = test1.insert(i2, 0);//在i2前添加元素0，i3为指向新加元素的迭代器
	i2 = test1.end();
	test1.insert(i2, 2, 1);//在i2前添加2个1
	i1 = test1.begin();
	i2 = test1.end();
	int add[4] = { 1, 2, 3, 4 };
	test1.insert(i2, add, add + 4);//在i2前面插入add[0] - add[3]的值
	i1 = test1.begin();
	while (i1 != test1.end()){//使用test1.end()，每次循环插入都重新计算end()以防失效
		i1 = test1.insert(++i1, 32);
		i1++;
	}
	for (i1 = test1.begin(); i1 != test1.end(); i1++)
		cout << *i1 << endl;
#endif

	return 0;
}

#endif