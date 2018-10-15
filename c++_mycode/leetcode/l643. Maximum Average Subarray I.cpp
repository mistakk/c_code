using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int n = nums.size(), i = 0;
		double maxsum, sum = 0;
		for (; i < k; ++i) {
			sum += nums[i];
		}
		maxsum = sum;
		for (; i < n; ++i) {
			sum = sum + nums[i] - nums[i - k];
			if (sum > maxsum)
				maxsum = sum;
		}
		return maxsum / k;
	}
};
void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}

void main()
{
	Solution a;
	vector<int> nums{ 1,12,-5,-6,50,3 };
	int k = 4;
	cout << a.findMaxAverage(nums, k);


}
