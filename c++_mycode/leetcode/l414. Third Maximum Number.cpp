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


class Solution {
public:
	int thirdMax(vector<int>& nums) {
		set<int> set;
		for (auto n : nums) {
			set.insert(n);
			if (set.size() == 4) {
				set.erase(set.begin());
			}
		}
		cout << set.size() << endl;
		if (set.size() == 3)
			return *set.begin();
		else
			return *set.rbegin();
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<vector<int>> times;
	times.push_back(vector<int>{2, 1, 1});
	times.push_back(vector<int>{2, 3, 1});
	times.push_back(vector<int>{3, 4, 111});

	cout << "sys start!" << endl;
	vector<int> te{ 5,1 };
	cout << a.thirdMax(te) << endl;
	

}