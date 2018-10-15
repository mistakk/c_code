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


//  Example 1:
//  Input: num = "123", target = 6
//	Output : ["1+2+3", "1*2*3"]
//	Example 2 :
//	Input : num = "232", target = 8
//	Output : ["2*3+2", "2+3*2"]
//	Example 3 :
//	Input : num = "105", target = 5
//	Output : ["1*0+5", "10-5"]
//	Example 4 :
//	Input : num = "00", target = 0
//	Output : ["0+0", "0-0", "0*0"]
//	Example 5 :
//	Input : num = "3456237490", target = 9191
//	Output : []
class Solution {
public:
	string data;
	int size, allval;
	vector<string> res;
	vector<string> addOperators(string num, int target) {
		size = num.size();
		data = num;
		if (size == 0)
			return res;
		allval = target;
		helper("", 0, 0, 0);
		return res;
	}
	void helper(string path, int pos, long val, int mul) {
		if (pos == size)
			if (val == allval) {
				res.push_back(path);
				return;
			}
		long now = 0;
		for (int i = pos; i < size; i++) {
			if (i != pos && data[pos] - '0' == 0)
				break;
			now = now * 10 + data[i] - '0';
			if (pos == 0) {
				helper(data.substr(0, i + 1), i + 1, now, now);
			}
			else {
				helper(path + "+" + data.substr(pos, i + 1 - pos), i + 1, val + now, now);
				helper(path + "-" + data.substr(pos, i + 1 - pos), i + 1, val - now, -now);
				helper(path + "*" + data.substr(pos, i + 1 - pos), i + 1, val - mul + mul * now, now*mul);
			}
		}
	}
};

int main() {
	Solution a;
	string num = "112";
	int target = -11;
	vector<string>ss = a.addOperators(num, target);
	for (auto sss : ss)
		cout << sss << endl << endl;
	return 0;
}