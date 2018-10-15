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
	//20.00
	int bsearch(vector<int> &ages, int flag, int score) {
		if (ages[flag] <= score)
			return 0;
		//返回大于score的第一个元素idx
		int start = 0, end = flag, mid;
		while (start <= end) {
			mid = (start + end) / 2;
			if (ages[mid] > score)
				end = mid - 1;
			else
				start = mid + 1;
		}
		return flag - start;
	}

	int numFriendRequests(vector<int>& ages) {
		sort(ages.begin(), ages.end());
		int cnt = 0;
		int last = -1;
		for (int i = ages.size() - 1; i >= 0; i--) {
			if (last > 0 && ages[i] == ages[i + 1]) {
				cnt = cnt + last;
			}
			else {
				last = bsearch(ages, i, ages[i] * 0.5 + 7);
				cnt += last;
			}
		}

		return cnt;
	}
};
int main() {
	Solution a;
	vector<int>num{ 20,30,100,110,120 };
	a.numFriendRequests(num);

	return 0;
}
