using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INT_MAX 0x7fffffff

#define INT_MIN 0x80000000

void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}

int maxProfit(vector<int>& prices) {
	int n = prices.size();
	if (n < 2)
		return 0;
	vector<int> rest(n);
	vector<int> buy(n);
	vector<int> sell(n);
	rest[0] = 0;
	buy[0] = -prices[0];
	sell[0] = INT_MIN;
	for (int i = 1; i < n; i++) {
		rest[i] = max(rest[i - 1], sell[i - 1]);
		buy[i] = max(buy[i - 1], rest[i - 1]-prices[i]);
		sell[i] = buy[i - 1] + prices[i];
	}
	return max(sell[n - 1], rest[n - 1]);
}
int maxProfit2(vector<int>& prices) {
	int n = prices.size();
	if (n < 2)
		return 0;
	int rest = 0, sell = -1, buy = -prices[0], sell_temp;
	for (int i = 1; i < n; i++) {
		sell_temp = sell;
		sell = buy + prices[i];
		buy = max(buy, rest - prices[i]);
		rest = max(rest, sell_temp);
	}
	return max(sell, rest);
}
void main()
{

	map<string, int> mp;
	string s = "123456789123456789";
	printf("s\n", s);
	cout << "checkbad letter" << endl;

}