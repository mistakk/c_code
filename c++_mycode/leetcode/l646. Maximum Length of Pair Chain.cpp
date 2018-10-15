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
	bool cmp(vector<int>a, vector<int>b) {
		return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
	}
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(), pairs.end(), cmp);
		int max_tail = 0;
		int cnt = 0;
		for (int i = 0; i < pairs.size(); ++i) {
			if (i == 0 || max_tail < pairs[i][0]) {
				max_tail = pairs[i][1];
				cnt++;
			}
		}
		return cnt;
	}

};

void main()
{
	string s = "aaa";
	Solution a;
	cout << a.countSubstrings(s) << endl;

}
