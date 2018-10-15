using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int r = nums[0];
		int imax = r;
		int imin = r;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < 0)
				swap(imax, imin);
			imax = max(nums[i], nums[i] * imax);
			imin = max(nums[i], nums[i] * imin);
			r = max(r, imax);
		}
		return r;
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<vector<int>> times;
	times.push_back(vector<int>{2, 1, 1});
	times.push_back(vector<int>{2, 3, 1});
	times.push_back(vector<int>{3, 4, 111});

	cout << "sys start!" << endl;
	vector<int> te{ 5,1 };


}