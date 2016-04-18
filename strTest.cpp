//#define STRFUNC
#ifdef STRFUNC
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;

int main(){
	/*strtok*/
	/*strtok(str, const char* split)*/
	char input[100] = {"\0"};
	const char* split = " ";
	char* p;
	ws(cin);
	while (cin.getline(input, 100))
	{
		p = strtok(input, split);
		while (p != NULL)
		{
			cout << p << endl;
			p = strtok(NULL, split);//�������NULL
		}
	}
	return 0;

	/*strlen*/
	char input[] = "abcdef";
	cout << "strlen:" << strlen(input) << endl;//������\0
	cout << "sizeof:" << (sizeof(input)) / (sizeof(char)) << endl;
	cout << "----------------------" << endl;
	char input2[100] = "abcdef";
	cout << "strlen:" << strlen(input2) << endl;
	cout << "sizeof:" << (sizeof(input2)) / (sizeof(char)) << endl;

	/*strcat*/
	/*strcat(dst, suffix)
	dst must have enough space to add suffix!
	*/
	char input[100] = "abcdef";
	char *suffix = "123";
	strcat(input, suffix);
	cout << input << endl;
	char input2[] = "abcdef";
	strcat(input2, suffix);//error ��Ϊinput2����û���㹻�Ŀռ�
	cout << input2 << endl;

	/*strcmp*/
	/*strcmp(str1, str2)
	if str1 > str2 return 1;
	if str1 = str2 return 0;
	if str1 < str2 return -1;
	*/
	char input[] = "abc";
	char input2[] = "abd";
	int cmp = strcmp(input, input2);
	cout << cmp << endl;

	/*strcpy & strncpy*/
	/*strcpy(dst, src), return dst��ָ��λ��*/
	/*strncpy(dst, src, n), return dst��ָ��λ��*/
	char input[] = "abc";
	char input2[100] = "123456";
	char* p = strcpy(input2 + 3, input);//p = 123
	cout << input2 << endl;
	cout << p << endl;
	strncpy(input2, input, 3);
	cout << input2 << endl;

	/*strchr*/
	/*strchr(str, char c) STL find*/
	/*strrchr(str, char c) STL rfind*/
	char input[] = "abcba";
	char c1 = 'b';
	char c2 = 'd';
	char* p1 = strchr(input, c1);
	char* p2 = strchr(input, c2);
	char* p3 = strrchr(input, c1);
	cout << p1 << endl;
	//cout << p2 << endl;//NULL
	cout << p3 << endl;

	/*strcspn*/
	/*strcspn(str1, str2) STL find_first_of*/
	/*
	inline int tStrCSpn(const tChar *pStr, const tChar *pStrSet)
	{
		// map��32���ֽڵĴ�С��Ҳ����256��bit���ɰ�map����һ��2ά����[32][8]
		unsigned char map[32] = { 0 };

		// ÿ��ASCII��(��Ϊc)��8bit�������ֳ�2���֣���3λ�����±�j(ͨ��c&7(2����Ϊ111)),
		// ��5λ�����±�i(ͨ��c>>3�õ�)��������map[i][j]����1��ʾ�ַ�����
		while (*pStrSet)
		{
			map[*pStrSet >> 3] |= (1 << (*pStrSet & 7));
			pStrSet++;
		}

		map[0] |= 1;

		int count = 0;
		while (!(map[*pStr >> 3] & (1 << (*pStr & 7))))
		{
			count++;
			pStr++;
		}

		return count;
	}
	*/
	char input[] = "abcdef";
	char* other = "123eeee";
	int p1 = strcspn(input, other);
	cout << input + p1 << endl;

	/*strrev*/
	char input[] = "abc";
	char* dup;
	dup = _strdup(input);
	cout << dup << endl;
	delete []dup;//!!
	char* rev;
	rev = _strrev(input);
	cout << rev << endl;
	delete []rev;

	/*strstr*/
/*strstr(str1, str2) str2��str1�е�һ�γ��ֵ�λ��*/
	char input[] = "abcabc123123adsas";
	char s1[] = "312";
	char s2[] = "321";
	char* p1 = strstr(input, s1);
	cout << p1 << endl;
	char* p2 = strstr(input, s2);
	cout << p2 << endl;//NULL
}

#endif