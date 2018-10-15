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
class Solution4 {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.size() < 1)
			return -1;
		vector<int>dp(amount + 1, 0);
		for (int i = 1; i <= amount; i++) {
			int minval = INT_MAX;
			for (int j = 0; j < coins.size(); j++) {
				if (i - coins[j] >= 0 && dp[i - coins[j]] != -1)
					minval = min(minval, dp[i - coins[j]] + 1);
			}
			dp[i] = minval == INT_MAX ? -1 : minval;
		}
		return dp[amount];
	}
};
class Solution3 {
public:
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.rbegin(), coins.rend());
		int minval = INT_MAX;
		coinhelper(coins, amount, minval, 0, 0);
		return minval == INT_MAX ? -1 : minval;
	}
private:
	void coinhelper(vector<int>& coins, int amount, int& countmin, int count, int idx) {
		int coinval = coins[idx];
		if (idx == coins.size() - 1) {
			if (amount % coinval == 0) {
				countmin = min(countmin, count + amount / coinval);
			}
		}
		else {
			for (int k = amount / coinval; k + count < countmin && k >= 0; k--) {
				coinhelper(coins, amount - k * coinval, countmin, count + k, idx + 1);
			}
		}
		return;
	}
};

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.size() < 1)
			return -1;
		vector<int> dp(amount + 1, 0);

		for (int i = 1; i < amount + 1; i++) {
			int minval = INT_MAX;
			for (int j = 0; j < coins.size(); j++) {
				if (i - coins[j] >= 0 && dp[i - coins[j]] != -1)
					minval = min(minval, dp[i - coins[j]] + 1);
			}
			dp[i] = minval == INT_MAX ? -1 : minval;
		}
		return dp[amount];
	}
};
class Solution2 {
public:
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.rbegin(), coins.rend()); //Greedy Algorithm: Decending sort (use rbegin())
		int min_count = INT_MAX;
		coinChange(coins, amount, min_count, 0, 0);//function overloading
		return (min_count == INT_MAX) ? -1 : min_count;
	}
private:
	void coinChange(vector<int>& coins, int amount, int& min_count, int count, int coin_idx) {
		int coin_val = coins[coin_idx];
		//if the last coin
		if (coin_idx == coins.size() - 1) {
			if (amount % coin_val == 0) {
				min_count = min(min_count, count + amount / coin_val);
			}
		}
		else {
			for (int k = amount / coin_val; k >= 0 && count + k < min_count; k--) { ///////multiple break condition
																					//Greedy: use as much as possible of the biggest val
																					//count + k < min_count: pruning the unessary branch
				coinChange(coins, amount - k * coin_val, min_count, count + k, coin_idx + 1);
			}
		}
		return;
	}
};
int main() {
	Solution3 a;
	vector<int> coins{ 1,2,5 };
	cout << a.coinChange(coins, 11) << endl;
	return 0;
}



