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
	int triangleNumber(vector<int>& nums) {
		if (nums.size() < 3)
			return 0;
		vector<int> cnt(1001, 0);
		int sum = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
			cnt[*it]++;
		}
		int size = 0,tmp;
		for (int first = 1; first < 1001; ++first) {
			if (cnt[first] == 0)
				continue;
			for (int second = first ;second < 1001; ++second) {
				if (cnt[second] == 0)
					continue;
				for (int k = second ; k < first + second; ++k) {
					if (cnt[k] == 0)
						continue;
					if (first != second && second != k)
						sum += cnt[first] * cnt[second] * cnt[k];
					else if (first == second && first != k && cnt[second] >= 2)
						sum += cnt[first] * (cnt[first] - 1) / 2 * cnt[k];
					else if (k == second && first != k && cnt[second] >= 2)
						sum += cnt[second] * (cnt[second] - 1) / 2 * cnt[first];
					else if (k == second && first == k && cnt[second] >= 3)
						sum += cnt[first] * (cnt[first] - 1) * (cnt[first] - 2) / 6;
				}
			}
		}
		return sum;
		
	}
};
void main()
{

	map<string, int> mp;
	string s = "123456789123456789";
	vector<int> nums{ 2,3,4 };
	Solution a;
	printf("%d\n", a.triangleNumber(nums));

}