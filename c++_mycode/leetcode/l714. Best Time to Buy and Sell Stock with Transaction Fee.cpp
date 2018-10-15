using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;
#include <vector>

class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		if (prices.size() < 2)
			return 0;
		int cash = 0;
		int hold = -prices[0];
		for (int i = 1; i < prices.size(); i++) {
			cash = max(cash, hold + prices[i] - fee);
			hold = max(hold, cash - prices[i]);
		}
		return cash;
	}
};

[1, 3, 2, 8, 4, 9]

int main() {


	return 0;
}