using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#include <fstream>



class Solution {
public:
	map<vector<bool>, int> mp;
	int n;
	int m;
	bool canIWin2(int maxChoosableInteger, int desiredTotal) {
		n = maxChoosableInteger;
		m = desiredTotal;
		cout << n << "   " << m << endl;
		if (2 * desiredTotal > (1 + maxChoosableInteger)*maxChoosableInteger)
			return false;
		vector<bool>key(n, false);
		return helper(key, 0);
	}

	bool helper(vector<bool> key, int nowval) {
		if (mp[key] != 0)
			return mp[key]; 
		if (nowval >= m) {
			mp[key] = 1;
			return true;
		}
		for (int i = 0; i < n; i++) {
			if (key[i] == false) {
				key[i] = true;
				bool ret = helper(key, nowval + i + 1);
				if (nowval + i + 1 >= m || !ret) {
					mp[key] = 1;
					return true;
				}
			}
		}
		mp[key] = -1;
		return false;
	}
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal % (maxChoosableInteger + 1) == 0)
            return false;
        else
            return true;
    }
};

int main() {
	Solution a;
	int maxChoosableInteger = 3;
	int desiredTotal = 5;
	cout << a.canIWin(maxChoosableInteger, desiredTotal) << endl;
	return 0;
}