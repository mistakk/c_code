using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

template<typename T>
void show(vector<T> vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

void show1(map<string, int> mp) {
	std::map<string, int>::iterator m = mp.begin();
	for (; m != mp.end(); ++m)
		cout << "key is " << m->first << "  value is " << m->second << endl;
}
void show2(vector<pair<string, int>> pairvec) {
	std::vector<pair<string, int>>::iterator p = pairvec.begin();
	for (; p != pairvec.end(); ++p)
		cout << "key is " << p->first << "  value is " << p->second << endl;
}


class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		std::map<int, int> mp;
		for (int i : nums)
			mp[i]++;
		int len = nums.size();
		vector<int> ret{ 0,0 };
		for (int i = 1; i <= len; ++i)
		{
			if (mp[i] == 2)
				ret[0] = i;
			else if (mp[i] == 0)
				ret[1] = i;
		}
		return ret;
	}
};



void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;

	vector<int> ret2{ 1, 2, 2, 4 };
	vector<int>  ret = a.findErrorNums(ret2);
	show(ret);
}