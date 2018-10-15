using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INT_MAX 0x7fffffff

#define INT_MIN 0x80000000

void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}

class Solution {
public:
	int countSubstrings(string s) {
		int n = s.size();
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; i - j >= 0 && i + j < n&&s[i - j] == s[i + j]; j++)
				res++;
			for (int j = 0; i - 1 - j >= 0 && i + j < n&&s[i - 1 - j] == s[i + j]; j++)
				res++;
		}
		return res;
	}
};

void main()
{
	string s = "aaa";
	Solution a;
	cout << a.countSubstrings(s) << endl;

}
