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

bool checkPossibility(vector<int>& nums) {
	int n = nums.size();
	if (n < 2)
		return true;

}

void main()
{
	vector<int> prices{ 1,3,5,4,5 };
	cout << checkPossibility(prices) << endl;

}
