using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		int maxval = 1;
		int temp_val = 1;
		for (int i = 0; i < len ; i++) {
			if (nums[i] == -1)
				continue;
			temp_val = 1;
			int k = i;
			int zero = nums[k];
			nums[k] = -1;
			while (zero < len && nums[zero] !=-1) {
				int t = zero;
				zero = nums[zero];
				nums[t] = -1;
				temp_val += 1;
			}
			maxval = max(maxval, temp_val);
		}
		return maxval;
	}
	int arrayNesting2(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		int maxval = 1;
		int temp_val = 1;
		for (int i = 0; i < len; i++) {
			if (nums[i] == -1)
				continue;
			temp_val = 1;
			int start = nums[i];
			int k = i;
			do {
				temp_val += 1;
				int temp = k;
				k = nums[k];
				nums[temp] = -1;
			} while (start != nums[k]);
			maxval = max(maxval, temp_val);
		}
		return maxval;
	}


};
void main()
{
	vector<int> nums = { 1, 0, 3, 4, 2 };
	map<string, int> mp;
	string s = "123456789123456789";
	Solution a;
	cout << a.arrayNesting(nums);


}