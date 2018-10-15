using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}
#define Interval vector<int>
bool comp(Interval a, Interval b) // 注意comp函数可以为static bool或者bool，返回值为bool类型。a.start<b.start为升序  
{
	return a[0] < b[0];
}
class Solution2 {
private:
	static bool comp(Interval a, Interval b) // 注意comp函数必须为static bool，返回值为bool类型。a.start<b.start为升序  
	{
		return a[0] < b[0];
	}
public:
	int intersectionSizeTwo(vector<Interval>& intervals) {
		sort(intervals.begin(), intervals.end(), comp);
		int s = intervals.size();
		for (int i = s - 1; i >= 0; i--)
			cout << intervals[i][0] << "  " << intervals[i][1] << endl;
		return 0;
	}
};


class Solution {
public:
	int intersectionSizeTwo(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), compare);
		int s = intervals.size();
		vector<int> num(s, 2);
		int abs = 0;
		//for (int i = 0; i < s; i++)
		//	cout << intervals[i][0] << "  " << intervals[i][1] << endl;
		//cout << "sort over!!" << endl;
		for (int i = s - 1; i >= 0; i--) {
			//cout << intervals[i][0] << "  " << intervals[i][1] << endl;
			int start = intervals[i][0];
			int end = intervals[i][1];
			int count = num[i];
			for (int p = start; p < start + count; p++) {
				for (int j = 0; j < i; j++)
					if (num[j] > 0 && p <= intervals[j][1])
						num[j] --;
				abs += 1;
			}
		}
		return abs;
	}
	static bool compare(vector<int> a, vector<int> b) {
		if (a[0] != b[0])
			return a[0] < b[0];
		return a[1] > b[1];
	}
};



void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<vector<int>> times;
	times.push_back(vector<int>{2, 11, 1});
	times.push_back(vector<int>{2, 13, 1});
	times.push_back(vector<int>{2, 10, 1});
	times.push_back(vector<int>{3, 4, 111});
	times.push_back(vector<int>{3, 5, 111});
	times.push_back(vector<int>{3, 6, 111});
	times.push_back(vector<int>{7, 8, 111});
	int x = a.intersectionSizeTwo(times);
	cout << x << endl;

}