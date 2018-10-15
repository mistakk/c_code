using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>

#include <fstream>
#include <numeric>


struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};



class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		int n = intervals.size();
		if (intervals.size() == 0) {
			intervals.push_back(newInterval);
			return intervals;
		}
		if (newInterval.end < intervals[0].start) {
			intervals.push_back(newInterval);
			return intervals;
		}
		if (newInterval.start > intervals[0].end) {
			intervals.push_back(newInterval);
			return intervals;
		}
		if (newInterval.end == intervals[0].start) {
			intervals[0].start = newInterval.start;
			return intervals;
		}
		if (newInterval.start == intervals[n - 1].end) {
			intervals[n - 1].end = newInterval.end;
			return intervals;
		}
		int start_idx = 0, end_idx = 0;
		int left = newInterval.start, right = newInterval.end;

		//search start_idx :left
		if (left < intervals[0].start)
			start_idx = 0;
		else if (left > intervals[n - 1].end)
			start_idx = 4 * n;
		else
			for (int i = 0; i < n - 2; i++) {
				if (left == intervals[i].start) {
					start_idx = 4 * i + 1;
					break;
				}
				else if (left > intervals[i].start &&left > intervals[i].end) {
					start_idx = 4 * i + 2;
					break;
				}
				else if (left == intervals[i].end) {
					start_idx = 4 * i + 3;
					break;
				}
				else if (left > intervals[i].end &&left > intervals[i + 1].start) {
					start_idx = 4 * i + 4;
					break;
				}
			}

		//search end_idx :right
		if (right < intervals[0].start)
			end_idx = 0;
		else if (right > intervals[n - 1].end)
			end_idx = 4 * n;
		else
			for (int i = 0; i < n - 2; i++) {
				if (right == intervals[i].start) {
					end_idx = 4 * i + 1;
					break;
				}
				else if (right > intervals[i].start &&right > intervals[i].end) {
					end_idx = 4 * i + 2;
					break;
				}
				else if (right == intervals[i].end) {
					end_idx = 4 * i + 3;
					break;
				}
				else if (right > intervals[i].end &&right > intervals[i + 1].start) {
					end_idx = 4 * i + 4;
					break;
				}
			}
		if (start_idx == 0 && end_idx == 4 * n) {
			intervals.clear();
			intervals.push_back(newInterval);
			return intervals;
		}
		if (start_idx == 0) {
			if (end_idx % 4 == 1 || end_idx == 2 || end_idx == 3) {
				intervals.erase(intervals.begin(), intervals.begin() + end_idx / 4);
				intervals[0].start = newInterval.start;
				return intervals;
			}
			else if (end_idx == 4) {
				intervals.erase(intervals.begin(), intervals.begin() + end_idx / 4);
				intervals[0].start = newInterval.start;
				intervals.push_back(newInterval);
				return intervals;
			}
		}
		if (end_idx == 4 * n) {
			if (start_idx % 4 == 1 || start_idx == 2 || start_idx == 3) {
				intervals.erase(intervals.begin() + end_idx / 4 + 1, intervals.end()); 
				intervals[intervals.size() - 1].end = newInterval.end;
				return intervals;
			}
			else if (start_idx == 4) {
				intervals.erase(intervals.begin() + end_idx / 4, intervals.end());
				intervals.push_back(newInterval);
				return intervals;
			}
		}
		{

		}

	}
};