using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

template<typename T>
void show(vector<T> vec) {
	for (int i = 0; i != vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}


class Solution {
public:
	int monotoneIncreasingDigits(int N) {
		int ret = 0,ret2 = 0;
		int po = 1000000000;
		int top = 0;
		int gap = 0;
		while(po!=0)
		{
			int now = N / po;
			N = N % po;
			po /= 10;
			if (now > top)
			{
				ret = ret2 * 10 + now;
				ret2 = ret;
				gap = po;
			}
			else if (now < top)
			{
				ret = ret * gap * 10 - 1;
				return ret;
			}
			else
				ret2 = ret2 * 10 + now;
			top = now;
		}
		return ret2;
	}
};



void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;

	int ret = a.monotoneIncreasingDigits(668841);
	cout << ret << endl;

}