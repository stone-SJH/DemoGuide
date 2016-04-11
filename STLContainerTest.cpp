//#define CONTAINER
#ifdef CONTAINER

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <stack>
#include <queue>
using namespace std;

class Foo{
private:
	int con;
public:
	Foo(){ con = 0; }
	Foo(int i){ con = i; }
};

class Node
{  
public:  
	Node(int nri, char *pszName)  
	{  
		strcpy_s(szName, pszName);  
		priority = nri;  
	}  
	char* GetName();  
	int   GetPriority();  
	char* GetName() const;  
	int   GetPriority() const;  
private:  
	char szName[20];  
	int  priority;  
};  
char* Node::GetName()  
{
	return szName;
}
int   Node::GetPriority()
{
	return priority;
}
char* Node::GetName() const
{
	return (char*)szName;
}
int   Node::GetPriority() const
{
	return priority;
}
bool operator<(const Node &a, const Node &b)
{
	if (a.GetPriority() != b.GetPriority())
		return a.GetPriority() <= b.GetPriority();
	else
		return strcmp(a.GetName(), b.GetName()) > 0;
}

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

//#define OPERATION1
#ifdef OPERATION1
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

	i1 = test1.begin();
	if (i1 != test1.end())	//check if i1 is end() before erase it
		i2 = test1.erase(i1);//删除i1指向的元素，返回i1之后的位置
	test1.pop_front();//删除第一个，返回void
	test1.pop_back();

	i1 = test1.begin();
	i2 = test1.end();
	test1.erase(i1, i2);//返回元素段后一个位置
	for (i1 = test1.begin(); i1 != test1.end(); i1++)
		cout << *i1 << endl;

	while(!test1.empty()){//use container as a stack
		test1.front();//do something with it
		test1.pop_front();//then remove it
	}
#endif

//#define OPERATION2
#ifdef OPERATION2
	list<int> test1;
	int listMaxSize = test1.max_size();
	cout << listMaxSize << endl;
	list<string> test2;
	listMaxSize = test2.max_size();
	cout << listMaxSize << endl;
	list<char> test3;
	listMaxSize = test3.max_size();
	cout << listMaxSize << endl;
	list<double> test4;
	listMaxSize = test4.max_size();
	cout << listMaxSize << endl;

	if (test1.empty())
		cout << "empty" << endl;

	test1.resize(10, 5);
	test1.resize(0);//清空

	test1.resize(10, 5);
	int frontInt = test1.front();
	int backInt = test1.back();//先判断非空
	//c[n] c.at(n)只适用于vector和deque


#endif

//#define OPERATION3
#ifdef OPERATION3
	list<int> test1;
	for (int i = 0; i < 10; i++)
		test1.push_back(i);
	list<int>::iterator i1, i2;
	int num1 = 0, num2 = 9;
	i1 = find(test1.begin(), test1.end(), num1);//返回第一个查找到的num1位置，若无则返回超出末端位置
	i2 = find(test1.begin(), test1.end(), num2);
	test1.erase(i1, i2);
	//i1, i2均非超出末端，则删除[i1, i2)内的元素
	//若i1超出末端，则不删除
	//若i2超出末端，则删除[i1, c.end())
	//若i1=i2， 则不删除
	for (list<int>::iterator i = test1.begin(); i != test1.end(); i++)
		cout << *i << endl;
#endif

//#define OPERATION4
#ifdef OPERATION4
	list<int> test1;
	for (int i = 0; i < 10; i++)
		test1.push_back(i);
	list<int> test2;
	for (int i = 10; i > 0; i--)
		test2.push_back(i);
	list<int>::iterator i1, i2;
	i1 = test1.begin();
	i2 = test2.begin();
	//test1 = test2;
	test1.swap(test2);//不会使迭代器失效
	cout << *i1 << endl;//指向现在test2的首个元素，即仍为0而不是10
	cout << *i2 << endl;

	test1.assign(test2.begin(), test2.end());//将test1重新设置为[i1, i2)的元素，i1 i2必须不是指向test1的迭代器
	test1.assign(10, 1); //将test1重新设置为10个1
#endif

//#define STRING
#ifdef STRING
	string s;
	for (int i = 0; i < 10; i++)
		s.push_back(i + 50);
	s.pop_back();
	//cout << s << endl;

	char* cp = "Hello";
	char ca[] = "World";
	char nn[] = { 'W', 'o', 'r', 'l', 'd' };//无结束符
	string s1(cp);
	string s2(ca);
	string s3(ca + 1, 4);
	string s4(nn);//error!
	string s5(nn, 5);
	string s6(ca, 2, 5); 
	/*cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;*/

	string test1 = "Hello World";
	string sub1 = test1.substr(6, 3);//返回从下标6(test[6])开始的3个字符的字符串, 最多只能到test1结尾
	//sub1 = "Wor"
	string sub2 = test1.substr(6);//返回从下标6(test[6])到test1结尾的字符串
	//sub2 = "World"
	string sub3 = test1.substr();//返回test1的副本
	//sub3 = "Hello World"

	string test2 = "";
	string app1 = "Hello";
	test2.append(app1);
	//test2.append(app1, 2, 3);//app1从app[2]开始的3个字符组成的字符串

	test2.replace(2, 2, "r");//将test2从test2[2]开始的两个字符替换为"r"
	//不要求替换的字符串与被替换的字符串长度一致
	//test2 = "Hero"
	string rep1 = "aird";
	test2.replace(1, 3, rep1, 0, 3);
	//test2 = "Hair"

	string number = "0123456789";
	string find1 = "123";
	string test3 = "hello123nums123";

	int pos = 0;
	pos = test3.find(find1);//返回test3中find1第一次出现的位置
	//pos = 5
	pos = test3.rfind(find1);//返回test3中find1最后一次出现的位置
	//pos = 12
	pos = test3.find_first_of(number);//返回test3中number中任意一个字符第一次出现的位置
	pos = test3.find_last_of(number);//
	pos = test3.find_first_not_of(number);//返回test3中第一个不属于number的字符出现的位置
	pos = test3.find_last_not_of(number);
	
	//查找test3中全部的数字
	pos = 0;
	string numInTest3;
	while ((pos = test3.find_first_of(number, pos)) != string::npos){
		numInTest3.push_back(test3[pos]);
		pos++;
	}

	//查找test3中全部的非数字
	pos = 0;
	string nonNumInTest3;
	while ((pos = test3.find_first_not_of(number, pos)) != string::npos){
		nonNumInTest3.push_back(test3[pos]);
		pos++;
	}

	//获取test4中全部的单词
	string test4 = "--We were he pride of 10 she named us: Benjamin, Phoenix, 332643145t{}?the Prodigal and perspicacious pacific Suzanne--";
	string alphabet = "abcdefghigklmnopqrstuvwxyzABCDEFGHIGKLMNOPQRSTUVWXYZ";
	int longPos = 0, longSize = 0;
	int shortPos = 0, shortSize = 10000;
	int curPos = 0, nextPos = 0;
	curPos = test4.find_first_of(alphabet, 0);
	vector <string> vocabs;
	while ((nextPos = test4.find_first_not_of(alphabet, curPos)) != string::npos){
		int size = nextPos - curPos;
		string tmp = test4.substr(curPos, size);
		vocabs.push_back(tmp);
		if ((curPos = test4.find_first_of(alphabet, nextPos)) == string::npos)
			break;
	}
	if (curPos != string::npos && curPos != test4.size() - 1){
		string tmp = test4.substr(curPos);
		vocabs.push_back(tmp);
	}
	for (vector<string>::iterator i = vocabs.begin(); i != vocabs.end(); i++)
		cout << *i << endl;

	string test5 = "abc123";
	string cmp1 = "abc";
	int r1 = test5.compare(cmp1);//+
	int r2 = test5.compare(0, 3, cmp1);//0
	int r3 = test5.compare(0, 2, cmp1, 0, 2);//0

#endif

//#define ADAPTOR
#ifdef ADAPTOR
	vector<string> str_vec;
	deque<string> str_deq;
	list<string> str_list;
	stack<string> test0(str_deq);
	stack<string, vector<string> > test1(str_vec);
	queue<string> test2(str_deq);
	priority_queue<Node> test3;
	test3.push(Node(2, "a1"));
	test3.push(Node(3, "b1"));
	test3.push(Node(1, "c1"));
	cout << test3.top().GetName() << endl;
	test3.pop();
	cout << test3.top().GetName() << endl;
	test3.pop();
	cout << test3.top().GetName() << endl;
	test3.pop();
#endif
	return 0;
}

#endif