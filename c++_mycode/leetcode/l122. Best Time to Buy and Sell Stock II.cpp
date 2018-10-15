using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n <2)
			return 0;
		int buy = -prices[0], sell = 0, buy_temp, sell_temp;
		for (int i = 1; i < n; i++) {
			buy_temp = buy;
			sell_temp = sell;
			buy = max(buy, sell_temp - prices[i]);
			sell = max(sell, buy_temp + prices[i]);
		}
		return sell;
	}
};

void main()
{
	Solution a;
	vector<int>  prices{ 7, 1, 5, 3, 6, 4 };
	cout << a.maxProfit(prices) << endl;

}








