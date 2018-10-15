using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>

#include <fstream>
#include <numeric>


class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int m = 0, cm = 0;
		for (auto &i : nums) {
			if (i == m)
				++cm;
			else if (cm == 0) {
				++cm;
				m = i;
			}
			else {
				--cm;
			}
		}
		vector<int>ret{m};
		return ret;
	}
};
int main() {
	Solution a;
	vector<int> num{ 1,2,2,2,3,3 };
	vector<int>vec = a.majorityElement(num);
	for (auto aa : vec)
		cout << aa << endl;
	return 0;
}
