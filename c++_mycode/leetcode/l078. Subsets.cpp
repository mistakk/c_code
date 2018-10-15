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
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret = { {} };
		int n = nums.size();
		if (n == 0)
			return ret;
		for (auto n : nums) {
			int precnt = ret.size();
			for (int i = 0; i < precnt; i++) {
				vector<int> temp = ret[i];
				temp.push_back(n);
				ret.push_back(temp);
			}
		}
		return ret;
	}
};

void main()
{
	Solution a;
	vector<int> nums{ 1,2,3 };
	cout << "sys start!" << endl;
	vector<vector<int>> aa = a.subsets(nums);
	for (auto s : aa) {
		for (auto ss : s) {
			cout << ss;
			cout << "";
		}
		cout << endl;
	}

}