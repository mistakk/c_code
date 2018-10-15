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
	bool checkRecord(string s) {
		int cnt1 = 0, cnt2 = 0, flag=0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'L') {
				if (flag) {
					cnt2++;
					if (cnt2 == 3)
						return false;
				}
				flag = 1;
				continue;
			}
			if (s[i] == 'A') {
				cnt1++;
				if (cnt1 == 2)
					return false;
			}
			flag = 0;
		}
		return true;
	}
};

int main() {
	Solution a;

	return 0;
}
