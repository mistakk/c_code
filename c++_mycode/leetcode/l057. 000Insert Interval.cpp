using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
/**
* Definition for an interval.*/
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {

	}
	vector<int>search(vector<Interval> intervals, Interval newInterval) {
		int start = newInterval.start, end = newInterval.end, len = intervals.size(), i = 0;
		int x = intervals[i].start, y = intervals[i].end;
		vector<int> re0,re1;
		int flag = 1;

		while ((i <= len - 1) && (start >= intervals[i].start)) {
			i++;
		}
		if (i == 0)
		{
			re0.push_back(0);
			re0.push_back(-1);
		}
		else {
			i--;
			re0.push_back(0);
			if (intervals[i].start == start)
				re0.push_back(1);
			else if (start < intervals[i].end)
				re0.push_back(2);
			else if (start = intervals[i].end)
				re0.push_back(3);
			else
				re0.push_back(4);
		}

		i = 0;
		while ((i <= len - 1) && (start >= intervals[i].start)) {
			i++;
		}
		if (i == 0)
		{
			re1.push_back(0);
			re1.push_back(-1);
		}
		else {
			i--;
			re0.push_back(0);
			if (intervals[i].start == start)
				re1.push_back(1);
			else if (start < intervals[i].end)
				re1.push_back(2);
			else if (start = intervals[i].end)
				re1.push_back(3);
			else
				re1.push_back(4);
		}










	}
};

void main()
{
	Solution a;


}

