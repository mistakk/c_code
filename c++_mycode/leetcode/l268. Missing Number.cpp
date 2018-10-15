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
	int missingNumber(vector<int>& nums) {
		int n = nums.size();
		long long int all = n * (n - 1) / 2;
		long long int now = 0;
		for (int i = 0; i < nums.size(); i++)
			now += nums[i];
		return all - now;
	}
};


int main() {


	return 0;
}