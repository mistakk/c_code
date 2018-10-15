using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size();
		if (len < 3)
			return len - 1;
		int count = 0, curend=0, curfurthest=0;
		for (int i = 0; i < len; i++) {
			curfurthest = max(curfurthest, i + nums[i]);
			if (curfurthest >= len-1)
				return count + 1;
			if (curend == i) {
				count++;
				curend = curfurthest;
			}
		}
		return count;
	}
};

void main()
{
	Solution a;
	vector<int> nums{ 3,2,1};
	//cout << a.jump(nums) << endl;
}

