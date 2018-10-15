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
	//ֻҪsum(gas)>=sum(cost) ��ô��һ�������
	//֤��������������i��ʼ�����val = gas(i)-cost(i) <0 
	//		�Ǿʹ�i-1��ʼ����ô val = gas(i-1, i) - cost(i-1, i) ���С��0����i--
	//      ��Ϊ sum(gas) >= sum(cost) ����valһ������ڵ���0
	//˼·���������start��ʼ��ʹ��start��������ʱ�̶���val>=0������start�����һ����
	//      �����е㶼check���֮�󣬼��val>=0 ������ÿһ���㶼����;���ǣ��������ǰstart
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