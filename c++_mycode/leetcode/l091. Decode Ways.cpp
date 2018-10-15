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

#include <functional>

class Solution2 {
public:
	int numDecodings(string s) {
		int ways_1 = 0, ways_2 = 0, ways = 0; // read as ways minus 1, ways minus 2 and ways

		if (s.size() == 0 || s[0] == '0')
			return 0;

		ways_1 = ways_2 = ways = 1;

		for (int i = 1; i < s.size(); ++i) {
			if (s[i] == '0') {
				ways = (s[i - 1] == '1' || s[i - 1] == '2') ? ways_2 : 0;
			}
			else {
				ways = (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <'7')) ?
					(ways_1 + ways_2) : ways_1;
			}
			ways_2 = ways_1;
			ways_1 = ways;
		}
		return ways;
	}
};
class Solution {
public:
	int numDecodings(string nums) {
		if (nums.size() == 0 || nums[0]=='0')
			return 0;
		int x = 1, y = 0, y_, last=nums[0]-'0', now;
		for (int i = 1; i < nums.size(); i++) {
			now = nums[i] - '0';
			if (now == 0) {
				if (last <1 || last > 2)
					return 0;
				y = x;
				x = 0;
			}
			else {
				if (last *10 + now <=26)
					y_ = x;
				else
					y_ = 0;
				x += y;
				y = y_;
			}
			last = now;
				
		}
		return x + y;
	}
};
int main() {
	Solution a;
	string nums = "110";
	cout << a.numDecodings(nums) << endl;
	return 0;
}
