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
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (int i = 0; i < 32; i++) {
			int sum = 0;
			for (int j = 0; j < nums.size(); j++) {
				sum += (nums[j] & 1 << i) >> i;
			}
			if (sum % 3 != 0)
				ret += (sum % 3) << i;
		}
		return ret;
	}
};

int main() {
	vector<int> nums{ 1,1,1,2,2,2,3,3,34,4,4,4,3 };
	Solution a;
	cout << a.singleNumber(nums) << endl;


	return 0;
}