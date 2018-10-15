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
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> s;
		if (nums.size() == 0)
			return s;
		int start = nums[0];
		int next = nums[0];
		for (auto now : nums) {
			if (now == next) {
				next += 1;
				continue;
			}
			else {
				string temp;
				if (start == next - 1)
					temp = to_string(start);
				else
					temp = to_string(start) + "->" + to_string(next - 1);
				s.push_back(temp);
				start = now;
				next = now+1;
			}
		}
		string temp;
		if (start == next - 1)
			 temp = to_string(start);
		else
			 temp = to_string(start) + "->" + to_string(next - 1);
		s.push_back(temp);
		return s;
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;

	vector<int> nums{0,1,2,4,7};
	cout << "sys start!" << endl;
	vector<string> aa = a.summaryRanges(nums);
	for (auto s : aa) {
		cout << s << endl;
	}

}