using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#include <fstream>


class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int diff = 0;
		for (int i = 0; i < nums.size(); i++)
			diff = diff ^ nums[i];
		
		diff = diff & -diff;
		vector<int> ret{ 0,0 };
		for (int i = 0; i < nums.size(); i++)
		{
			if ((nums[i] & diff) == 0)
				ret[0] = ret[0] ^ nums[i];
			else
				ret[1] = ret[1] ^ nums[i];
		}
		return ret;
	}
};

int main() {
	vector<int> nums{ 1,2,2,8,16,1,5,5 };
	Solution a;
	vector<int> ret = a.singleNumber(nums);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}