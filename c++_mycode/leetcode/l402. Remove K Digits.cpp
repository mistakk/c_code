using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}
void show(vector<char> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}

class Solution {
public:
	string removeKdigits(string num, int k) {
		int n = num.size();
		int top = 0, retsize = n - k;
		vector<char> stk(n);
		for (char c : num)
		{
			while (top > 0 && stk[top - 1] > c && k > 0)
			{
				k--;
				top--;
			}
			stk[top++] = c;
		}
		string res, res2;
		for (int i =0;i<retsize;i++)
			res += stk[i];
		int idx = 0;
		while (res[idx] == '0')
			idx++;
		for (int i = idx; i < res.size(); i++)
			res2 += res[i];
		if (res2.size() == 0)
			res2 = "0";
		return res2;
	}
};


void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	string res = a.removeKdigits("10200", 1);
	cout << "sys start!" << endl;
	cout << res << endl;
	cout << INTMAX_MAX << endl;
	cout << INTMAX_MIN << endl;
}