using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
	std::string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}
void split(const string& s, vector<int>& sv, const char flag = ' ') {
	sv.clear();
	istringstream iss(s);
	string temp;

	while (getline(iss, temp, flag)) {
		sv.push_back(stoi(temp));
	}
	return;
}
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}	
};
vector<Interval> merge(vector<Interval>& intervals) {
	if (intervals.empty()) return intervals;

	map<int, int> Map;
	for (Interval item : intervals) {
		Map[item.start]++;
		Map[item.end]--;
	}
	int num = 0;
	int last = 0;
	int start = 0;
	vector<Interval> ans;
	for (map<int, int>::iterator iter = Map.begin(); iter != Map.end(); iter++) {
		int pos = iter->first;
		int inter = iter->second;

		last = num;
		num += inter;

		if (last == 0) {
			start = pos;
		}
		if (num == 0) {
			Interval interval(start, pos);
			ans.push_back(interval);
		}
	}
	return ans;
}
int main() {
	int n;
	string s;
	vector<int>sv;
	getline(cin, s);
	n = atoi(s.c_str());
	vector<Interval> intervals;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		vector<string> str_vec;
		SplitString(s, str_vec, ";");

		for (int j = 0; j < str_vec.size(); j++) {
			vector<int> nn;
			split(str_vec[j], nn, ',');
			intervals.push_back(Interval(nn[0], nn[1]));
		}
	}
	intervals = merge(intervals);
	for (int i = 0; i < intervals.size() - 1; i++)
		cout << intervals[i].start << "," << intervals[i].end << ";";
	cout << intervals[intervals.size() - 1].start << "," << intervals[intervals.size() - 1].end;
}