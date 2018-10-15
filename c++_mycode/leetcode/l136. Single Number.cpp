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
		int ret =0;
		for (int i = 0; i < nums.size(); i++)
			ret = ret ^ nums[i];
		return ret;
	}
};

int main() {


	return 0;
}