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
	static bool cmp(pair<int, int> a, pair<int, int>b)
	{
		return a.first < b.first;
	}
	int findMinArrowShots(vector<pair<int, int>>& points) {
		if (points.size() == 0)
			return 0;
		sort(points.begin(), points.end(), cmp);
		int ans = 0, terminal = points[0].second;
		for (pair<int, int> p : points) {
			if (p.second < terminal)
				terminal = p.second;
			else if (p.first > terminal)
			{
				terminal = p.second;
				ans++;
			}
		}
		return ans;
	}
};

bool cmp2(int a, int b)
{
	return a < b;
}
void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<int> times{ 2, 1, 1 };
	show(times);
	sort(times.begin(), times.end(), cmp2);
	show(times);
	cout << "sys start!" << endl;
	vector<int> te{ 5,1 };


}