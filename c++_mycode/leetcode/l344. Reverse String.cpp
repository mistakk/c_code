using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	string reverseString(string s) {
		int len = s.size();
		char tmp;
		for (int i = 0, j = len - 1; i < j; i++, j--) {
			tmp = s[i];
			s[i] = s[j];
			s[j] = tmp;
		}
		return s;
	}

	char * reverseString2(char *s) {
		char* r = s;

		//��pָ���ַ������һ���ַ�
		char* p = s;
		while (*(p + 1) != '\0')
			++p;

		// ʹ�����������н���
		while (p > s)
		{
			*p = *p ^ *s;
			*s = *p ^ *s;
			*p = *p-- ^ *s++;
		}

		return r;
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	string s = "abcdefghijabcdefghij";
	cout << s << endl;
	Solution a;
	//s = a.reverseString(s);
	cout << s << endl;
	reverse(s.begin(), s.begin()+2);
	cout << s << endl;
	//cout << s.end() << endl;
	char *ss = "abc";
	ss = a.reverseString2(ss);
	cout << ss << endl;

}