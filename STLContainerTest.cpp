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
	list<int>::iterator i1 = test1.end();//end()�������һ��Ԫ�صĺ�һ��λ��
	list<int>::iterator i2 = test1.begin();
	list<int>::reverse_iterator ri1 = test1.rbegin();//rbegin()�����һ��Ԫ�ص�ǰһ��λ��
	list<int>::reverse_iterator ri2 = test1.rend();//rend()�������һ��Ԫ��
	//i2++;
	//i1 = i1 + 10;//error
	//i1 = i1 - i2;//error
	//while (i1 < i2) //error
	vector<string> test2;
	test2.push_back("");
	test2.push_back("b");
	vector<string>::iterator i3 = test2.begin();
	if (i3->empty())//i3�൱��һ��stringָ��
		cout << "empty" << endl;
	test1.push_front(6);//ֻ������list deque
	//��Ӳ�����ԭ������ʧЧ
	i1 = test1.begin();
	i2 = test1.end();
	list<int>::iterator i4 = test1.insert(i2, 0);//��i2ǰ���Ԫ��0��i3Ϊָ���¼�Ԫ�صĵ�����
	i2 = test1.end();
	test1.insert(i2, 2, 1);//��i2ǰ���2��1
	i1 = test1.begin();
	i2 = test1.end();
	int add[4] = { 1, 2, 3, 4 };
	test1.insert(i2, add, add + 4);//��i2ǰ�����add[0] - add[3]��ֵ
	i1 = test1.begin();
	while (i1 != test1.end()){//ʹ��test1.end()��ÿ��ѭ�����붼���¼���end()�Է�ʧЧ
		i1 = test1.insert(++i1, 32);
		i1++;
	}

	i1 = test1.begin();
	if (i1 != test1.end())	//check if i1 is end() before erase it
		i2 = test1.erase(i1);//ɾ��i1ָ���Ԫ�أ�����i1֮���λ��
	test1.pop_front();//ɾ����һ��������void
	test1.pop_back();

	i1 = test1.begin();
	i2 = test1.end();
	test1.erase(i1, i2);//����Ԫ�ضκ�һ��λ��
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
	test1.resize(0);//���

	test1.resize(10, 5);
	int frontInt = test1.front();
	int backInt = test1.back();//���жϷǿ�
	//c[n] c.at(n)ֻ������vector��deque


#endif

//#define OPERATION3
#ifdef OPERATION3
	list<int> test1;
	for (int i = 0; i < 10; i++)
		test1.push_back(i);
	list<int>::iterator i1, i2;
	int num1 = 0, num2 = 9;
	i1 = find(test1.begin(), test1.end(), num1);//���ص�һ�����ҵ���num1λ�ã������򷵻س���ĩ��λ��
	i2 = find(test1.begin(), test1.end(), num2);
	test1.erase(i1, i2);
	//i1, i2���ǳ���ĩ�ˣ���ɾ��[i1, i2)�ڵ�Ԫ��
	//��i1����ĩ�ˣ���ɾ��
	//��i2����ĩ�ˣ���ɾ��[i1, c.end())
	//��i1=i2�� ��ɾ��
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
	test1.swap(test2);//����ʹ������ʧЧ
	cout << *i1 << endl;//ָ������test2���׸�Ԫ�أ�����Ϊ0������10
	cout << *i2 << endl;

	test1.assign(test2.begin(), test2.end());//��test1��������Ϊ[i1, i2)��Ԫ�أ�i1 i2���벻��ָ��test1�ĵ�����
	test1.assign(10, 1); //��test1��������Ϊ10��1
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
	char nn[] = { 'W', 'o', 'r', 'l', 'd' };//�޽�����
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
	string sub1 = test1.substr(6, 3);//���ش��±�6(test[6])��ʼ��3���ַ����ַ���, ���ֻ�ܵ�test1��β
	//sub1 = "Wor"
	string sub2 = test1.substr(6);//���ش��±�6(test[6])��test1��β���ַ���
	//sub2 = "World"
	string sub3 = test1.substr();//����test1�ĸ���
	//sub3 = "Hello World"

	string test2 = "";
	string app1 = "Hello";
	test2.append(app1);
	//test2.append(app1, 2, 3);//app1��app[2]��ʼ��3���ַ���ɵ��ַ���

	test2.replace(2, 2, "r");//��test2��test2[2]��ʼ�������ַ��滻Ϊ"r"
	//��Ҫ���滻���ַ����뱻�滻���ַ�������һ��
	//test2 = "Hero"
	string rep1 = "aird";
	test2.replace(1, 3, rep1, 0, 3);
	//test2 = "Hair"

	string number = "0123456789";
	string find1 = "123";
	string test3 = "hello123nums123";

	int pos = 0;
	pos = test3.find(find1);//����test3��find1��һ�γ��ֵ�λ��
	//pos = 5
	pos = test3.rfind(find1);//����test3��find1���һ�γ��ֵ�λ��
	//pos = 12
	pos = test3.find_first_of(number);//����test3��number������һ���ַ���һ�γ��ֵ�λ��
	pos = test3.find_last_of(number);//
	pos = test3.find_first_not_of(number);//����test3�е�һ��������number���ַ����ֵ�λ��
	pos = test3.find_last_not_of(number);
	
	//����test3��ȫ��������
	pos = 0;
	string numInTest3;
	while ((pos = test3.find_first_of(number, pos)) != string::npos){
		numInTest3.push_back(test3[pos]);
		pos++;
	}

	//����test3��ȫ���ķ�����
	pos = 0;
	string nonNumInTest3;
	while ((pos = test3.find_first_not_of(number, pos)) != string::npos){
		nonNumInTest3.push_back(test3[pos]);
		pos++;
	}

	//��ȡtest4��ȫ���ĵ���
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