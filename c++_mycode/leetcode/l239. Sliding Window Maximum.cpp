using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> re;
		for (int i = 0; i < nums.size() ; i++) {
			if (!dq.empty() && dq.front() == i - k)
				dq.pop_front();
			while (!dq.empty() && dq.back() < nums[i])
				dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1)
				re.push_back(nums[dq.front()]);
		}
		for (auto i : re)
			cout << i << endl;
		return re;
	}
};

void main()
{
	Solution a;
	int k = 3;
	vector<int> nums{ 1,3,-1,-3,5,3,6,7 };
	a.maxSlidingWindow(nums, k);

}

