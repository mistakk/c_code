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



struct Interval {
   int start;
   int end;
   Interval() : start(0), end(0) {}
   Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static bool cmp(Interval a, Interval b)
	{
		return a.start < b.start;
	}
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		if (intervals.size() == 0)
			return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int ans = 0, terminal = intervals.end;
		for (int i = 1; i < intervals.size(); ++i)
		{
			Interval p = intervals[i];
			if (p.start >= terminal)//depart
			{
				terminal = p.end;
			}
			else if (p.end > terminal)
			{
				ans++;
			}
			else
			{
				terminal = p.end;
			}
		}
		return ans;
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
	vector<int> te{ 5,1 };


}