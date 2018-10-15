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
	int maximumSwap(int num) {
		int max_val = -1, max_idx = -1, replace_val = -1, replace_idx = -1, temp, num_raw = num, i0, might_maxval, might_maxidx;
		for (int i = 0; i < 8 && num != 0; i++) {
			temp = num % 10;
			num = num / 10;
			if (temp == max_val)
				continue;
			if (temp < max_val) {
				replace_val = temp;
				replace_idx = i;
				might_maxval = max_val;
				might_maxidx = max_idx;
			}
			else {
				i0 = i;
				while (num % 10 == temp) {
					i++;
					num = num / 10;
				}
				if (num == 0)
					break;
				max_val = temp;
				max_idx = i0;
			}
		}
		if (replace_idx != -1)
			return num_raw + (might_maxval - replace_val) * pow(10, replace_idx) - (might_maxval - replace_val) * pow(10, might_maxidx);
		else
			return num_raw;
	}
};
int main() {
	Solution a;
	int aa = 9801;
	cout << a.maximumSwap(aa) << endl;
	return 0;
}
