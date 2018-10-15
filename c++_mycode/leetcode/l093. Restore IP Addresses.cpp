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


class Solution {
public:
	//8.40
	vector<string> restoreIpAddresses2(string s) {
		vector<string> res;
		string path;
		helper(s, 0, s.size(), 1, res, path);
		return res;
	}
	void helper(string& s, int idx, int len, int th, vector<string>& res, string& path) {
		if (th > 4) {
			res.push_back(path);
			res.back().pop_back();
			return;
		}
		for (int i = 1; i < 4; i++) {
			string temp = s.substr(idx, i);
			if (temp[0] == '0' && temp.size() > 1) continue;
			if (len - i <= 3 * (4 - th) && len - i >= 4 - th && 255 - stoi(temp) >= 0) {
				path += temp;
				path += '.';
				helper(s, idx + i, len - i, th + 1, res, path);
				path.erase(path.end() - i - 1, path.end());
			}
		}
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		if (s.size() < 4 || s.size() > 12)
			return res;
		queue<vector<int>>q;
		int cnt = q.size(), thisval;
		int loop = 4, nowlen = 0;
		bool flag_first = true;
		vector<int>temp{ 0 };
		while (--loop >= 0) {
			//3 2 1 0
			while (--cnt >= 0 || flag_first) {
				if (!flag_first) {
					temp = q.front(), q.pop();
				}
				flag_first = false;
				nowlen = temp[0];
				thisval = 0;
				for (int i = 1; i < 4 && nowlen + i - 1 < s.size(); i++) {
					// len is 1 2 3
					if (thisval == 0 && i != 1)
						break;
					thisval = thisval * 10 + s[nowlen + i - 1] - '0';
					if ((s.size() - nowlen - i) > 3 * loop)
						continue;
					if (thisval < 256 && nowlen + i + loop <= s.size()) {
						vector<int>newa(temp);
						newa.push_back(i);
						newa[0] += i;
						q.push(newa);
					}
					else
						break;
				}
			}
			cnt = q.size();
		}
		while (!q.empty()) {
			temp = q.front(), q.pop();
			nowlen = 0;
			if (temp[0] == s.size()) {
				string end = "";
				for (int i = 1; i <= 3; i++) {
					end += s.substr(nowlen, temp[i]) + ".";
					nowlen += temp[i];
				}
				end += s.substr(nowlen, temp[4]);

				res.push_back(end);
			}
		}
		return res;
	}
	vector<string> restoreIpAddresses3(string s) {
		vector<string> res;
		string path;
		helper2(s, 0, 1, res, path);
		return res;
	}
	void helper2(string &s, int nowidx, int th, vector<string> &res, string path) {
		if (th >4) {
			res.push_back(path);
			res.back().pop_back();
			return;
		}
		for (int i = 1; i < 4 && nowidx + i <= s.size(); i++) {
			string val = s.substr(nowidx, i);
			if (val[0] == '0'&&val.size() > 1)
				continue;
			if (atoi(val.c_str()) < 256 && s.size() - nowidx - i >= 4 - th && s.size() - nowidx - i <= 3 * (4 - th)) {
				helper2(s, nowidx + i, th + 1, res, path + val + ".");
			}
		}
	}
};
int main() {
	Solution a;
	string s = "48651320";
	vector<string> res1 = a.restoreIpAddresses2(s);
	vector<string> res2 = a.restoreIpAddresses3(s);
	for (auto ss : res1) {
		cout << ss << endl;
	}
	cout << endl;
	for (auto ss : res2) {
		cout << ss << endl;
	}
	return 0;
}
