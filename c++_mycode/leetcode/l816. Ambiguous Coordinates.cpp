using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#include <fstream>




class Solution {
public:
	vector<string> res;
	vector<string> ambiguousCoordinates(string S) {
		S = S.substr(1, S.size() - 2);
		for (int i = 1; i < S.size(); i++) {
			string s1 = S.substr(0, i);
			string s2 = S.substr(i, S.size() - i);
			if (check(s1) && check(s2)) {
				vector<string> ret1 = form(s1);
				vector<string> ret2 = form(s2);
				for (int j = 0; j < ret1.size(); j++) {
					for (int k = 0; k < ret2.size(); k++) {
						string last = "(";
						last += ret1[j];
						last += ",";
						last += ret2[k];
						last += ")";
						res.push_back(last);
					}
				}
			}
		}
		return res;
	}
	bool check(string s) {
		if (s.size() <= 1)
			return s.size();
		else if (s[0] == '0' && s[s.size() - 1] == '0')
			return false;
		return true;
	}
	vector<string> form(string s) { //12034 -> 1.2034 12.034 120.34 1203.4 12304
		vector<string> ret;
		if (s.size() == 1 || s[s.size()-1]=='0') {
			ret.push_back(s);
			return ret;
		}
		else {
			if (s[0] == '0') {
				string temp = "0.";
				temp += s.substr(1, s.size() - 1);
				ret.push_back(temp);
				return ret;
			}
			int idx = 0;
			while (idx < s.size() - 1) {
				string temp = s.substr(0, idx + 1) + ".";
				temp += s.substr(idx + 1, s.size() - 1 - idx);
				ret.push_back(temp);
				idx++;
			}
			ret.push_back(s);
		}
		return ret;
	}
};

int main() {
	Solution a;
	string ss = "(100)";
	vector<string>ret = a.ambiguousCoordinates(ss);
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;
	return 0;
}