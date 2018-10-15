using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		int lowest=prices[0], maxv = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			lowest = min(lowest, prices[i]);
			maxv = max(maxv, prices[i] - lowest);
		}
		return maxv;
	}
};
 
void main()
{
	Solution a;
	vector<int>  prices{ 7, 1, 5, 3, 6, 4 };
	cout << a.maxProfit(prices) << endl;

}








