using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		for (int i = 0; i < n; i++)
		{
			int gasval = 0;
			for (int j = i; j < n+i; j++)
			{
				int jj = j % n;
				gasval += gas[jj] - cost[jj];
				if (gasval < 0)
					break;
			}
			if(gasval>=0)
				return i;
		}
		return -1;
	}
	//只要sum(gas)>=sum(cost) 那么就一定会完成
	//证明：假如从任意点i开始，如果val = gas(i)-cost(i) <0 
	//		那就从i-1开始，那么 val = gas(i-1, i) - cost(i-1, i) 如果小于0继续i--
	//      因为 sum(gas) >= sum(cost) 所以val一定会大于等于0
	//思路：从任意点start开始，使得start保持任意时刻都有val>=0，否则start向后推一个；
	//      在所有点都check完毕之后，检查val>=0 若非则每一个点都不行;若是，则输出当前start
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int start = gas.size()-1, end = 0;
		int gasval = 0;
		gasval += gas[start] - cost[start];
		cout << "ssss" << endl;
		while(start>end)
		{
			if (gasval > 0)
			{
				gasval += gas[end] - cost[end];
				end++;
			}
			else
			{
				start--;
				gasval += gas[start] - cost[start];
			}
		}
		return gasval >= 0 ? start : -1;
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<int> gas{ 1,2 };
	vector<int> cost{ 2,1};
	cout << a.canCompleteCircuit(gas,cost) << endl;
	vector<int> te{ 5,1 };


}