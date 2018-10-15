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
	for (int i = 0; i != vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}


class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int len = nums.size();
		if (nums.size() <= 1)
			return len;
		int cnt = 1;
		int flag = 0;
		int val = nums[0];
		for (int i = 1; i < len; i++)
		{
			if (nums[i] > val && flag >= 0)
			{
				cnt++;
				flag = -1;
			}
			else if (nums[i] < val && flag <= 0)
			{
				cnt++;
				flag = 1;
			}
			val = nums[i];
		}
		return cnt;
	}

	int wiggleMaxLength2(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;

		int pos = 1, neg = 1;
		for (int i = 1; i < n; i++) {
			if (nums[i] > nums[i - 1]) {
				pos = neg + 1;
			}
			else if (nums[i] < nums[i - 1]) {
				neg = pos + 1;
			}
		}
		return max(pos, neg);
	}

};


void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;
	vector<int>vec{ 1,3,2,4,5 ,6,5};

	int ret = a.wiggleMaxLength(vec);
	cout << ret << endl;

}