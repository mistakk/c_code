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
	int removeDuplicates2(vector<int>& nums) {
		//only handle the number instead of the array
		int len = nums.size();
		if (len <= 2)
			return len;
		int cnt = 1, s = 1;
		bool flag = true;
		while (s < len) {
			if (nums[s] == nums[s - 1]) {
				if (flag) {
					flag = false;
					cnt++;
				}
			}
			else{
				flag = true;
				cnt++;
			}
			s += 1;
		}
		return cnt;
	}

	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len <= 2)
			return len;
		int cnt = 1, s = 1;
		bool flag = true;
		while (s < len) {
			if (nums[s] == nums[s - 1]) {
				if (flag) {
					flag = false;
					nums[cnt++] = nums[s];
				}
			}
			else {
				flag = true;
				nums[cnt++] = nums[s];
			}
			s += 1;
		}
		return cnt;
	}

};
void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<vector<int>> times;
	vector<int > times2{ 1,2,2,2,3,3 };
	times.push_back(vector<int>{2, 1, 1});
	times.push_back(vector<int>{2, 3, 1});
	times.push_back(vector<int>{3, 4, 111});

	cout << "sys start!" << endl;
	cout << a.removeDuplicates(times2) << endl;


}