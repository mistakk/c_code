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
int dfs(vector<int> nums, int target) {
	return 0;
}
//nums = [1, 2, 3]
//target = 4
//
//The possible combination ways are :
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
int combinationSum4(vector<int> num, int target) {
	int n = num.size();
	vector<vector<int>> dp(n + 1, vector<int>(target + 1));
	for (int i = 1; i <= n; i++)
		if (num[i-1] <= target)
			dp[i][num[i-1]] = 1;
	for (int t = 1; t <= target; t++)
		for (int i = 1; i <= n; i++) {
			dp[i][t] += dp[i-1][t];
			if (t - num[i-1] >0)
				dp[i][t] += dp[i-1][t - num[i-1]];
		}
	return dp[n][target];
}

void main1()
{
	vector<int> prices{ 1,2,3 };
	int result = combinationSum4(prices, 6);
	cout << result << endl;

}
#include <iostream>
#include <ctime>
#include <string>
#include <stringstream>

using namespace std;
int timenow() {
	time_t timep;
	struct tm *p;

	time(&timep);
	int l;
	l = (int)timep;
	return l;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char buffer[33];
	printf("Enter a number: ");
	scanf("%d", &i);
	itoa(i, buffer, 10);
	printf("decimal: %s\n", buffer);
	itoa(i, buffer, 16);
	printf("hexadecimal: %s\n", buffer);
	itoa(i, buffer, 2);
	printf("binary: %s\n", buffer);
	return 0;
}



template <typename T>
std::string NumberToString(T Number)
{
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}
int main()
{
	// 基于当前系统的当前日期/时间
	time_t now = time(0);
	int n = timenow();
	tm *ltm = localtime(&now);
	string date_now = NumberToString(1900 + ltm->tm_year);
	string month = NumberToString(1 + ltm->tm_mon);
	if (month.size() == 1)
		month = '0' + month;
	date_now += month;
	string day = NumberToString(ltm->tm_mday);
	if (day.size() == 1)
		month = '0' + day;
	date_now += day;
	cout << date_now << endl;
}



int main()
{
	// 基于当前系统的当前日期/时间
	time_t now = time(0);
	int n = timenow();
	cout << "1970 到目前经过秒数:" << n << endl;


	cout << "1970 到目前经过秒数:" << now << endl;
	tm *ltm = localtime(&now);



	cout << "年: " << 1900 + ltm->tm_year << endl;
	cout << "月: " << 1 + ltm->tm_mon << endl;
	cout << "日: " << ltm->tm_mday << endl;
	cout << "时间: " << ltm->tm_hour << ":";
	cout << ltm->tm_min << ":";
	cout << ltm->tm_sec << endl;
}



