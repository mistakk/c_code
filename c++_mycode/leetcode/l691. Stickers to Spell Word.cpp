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
	vector<int> memo;
	string target;
	vector<string> stickers;

	// Returns the best solution if I've already covered the target letters indicated in mask.
	int f(int mask) {
		if (mask == (1 << target.size()) - 1) 
			return 0; // All letters are done!
		if (memo[mask] != -1) return memo[mask];

		int best = INT_MAX / 2; // I divide by 2 to avoid overflow.
		for (const string &s : stickers) { // Brute-force the next sticker.

			int new_mask = mask;
			for (const char &c : s) {
				for (int i = 0; i < target.size(); ++i) {
					if (new_mask & (1 << i)) 
						continue;
					if (target[i] == c) {
						new_mask |= (1 << i);
						break;
					}
				}
			}
			if (new_mask != mask) {
				best = min(best, f(new_mask) + 1);
			}
		}
		return memo[mask] = best;
	}

public:
	int minStickers(vector<string>& s, string t) {
		stickers = std::move(s);
		target = std::move(t);
		memo.assign(1 << target.size(), -1);
		int ans = f(0);
		if (ans > target.size()) 
			return -1;
		return ans;
	}
};
class Solution2 {
public:
	int minStickers(vector<string>& stickers, string target) {
		map<char, int>mp;
		for (auto s : target) {
			mp[s]++;
		}
		int n = mp.size();
		vector<int>tarlist(n, 0);
		int i = 0, j, k;
		map<char, int>::iterator it;
		for (it = mp.begin(); it != mp.end(); it++) {
			tarlist[i] = mp[it->second];
			mp[it->second] = i++;
		}

		vector<vector<int>> source(stickers.size(), vector<int>(n, 0));
		for (i = 0; i < stickers.size(); i++) {
			j = 0;
			for (k = 0; k < stickers[i].size(); k++) {
				it = find(mp.begin(), mp.end(), stickers[i][k]);
				if(it!=mp.end()){
					source[i][it->second]++;
				}
			}
		}
		int minval = INT_MAX;
		helper(source, tarlist, minval, 0, 0);
		return minval == INT_MAX ? -1 : minval;
	}
private:
	void helper(vector<vector<int>>& source, vector<int> tarlist, int mincount, int count, int idx) {
		vector<int> nowval = source[idx];
		if (idx == source.size()) {
			for (int i = 0; i < tarlist.size(); i++) {
				if (tarlist[i] - source[idx][i] != 0)
					return;
			}
			mincount = min(mincount, count + 1);
		}
	}
	vector<int> heplerstr(string a, string demo) {


	}
};
int main() {
	Solution a;
	vector<int> coins{ 1,2,5 };
	cout << a.coinChange(coins, 11) << endl;
	return 0;
}



