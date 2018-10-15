using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INT_MAX 0x7fffffff

#define INT_MIN 0x80000000

int findNumberOfLIS(vector<int>& nums) {
	int n = nums.size();
	if (n < 2)
		return n;
	vector<int> len(n, 1);
	vector<int> cnt(n, 1);
	int max_len = 0, max_static = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			if (nums[i] > nums[j]) {
				if (len[i] == len[j] + 1)
					cnt[i] += cnt[j];
				if (len[i] < len[j] + 1) {
					cnt[i] = cnt[j];
					len[i] = len[j] + 1;
				}
			}
		if (len[i] == max_len)
			max_static += cnt[i];
		if (len[i] > max_len) {
			max_static = cnt[i];
			max_len = len[i];
		}
	}
	return max_static;
}

void main()
{
	vector<int> prices{ 1,1,1,2 };
	cout << findNumberOfLIS(prices) << endl;

}
