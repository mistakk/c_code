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
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.size() == 0)
			return 0;
		int val = 0, last = 0;

		for (auto t : timeSeries) {
			if (t < last) {
				val += duration - (last - t);
				last += duration - (last - t);
			}
			else {
				val += duration;
				last = t + duration ;
			}
		}
		return val;
	}
};



void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<vector<int>> times;
	times.push_back(vector<int>{2, 1, 1});
	times.push_back(vector<int>{2, 3, 1});
	times.push_back(vector<int>{3, 4, 111});

	cout << "sys start!" << endl;
	vector<int> te{ 1,2,3,4,5 };
	cout << a.findPoisonedDuration(te, 5) << endl;


}