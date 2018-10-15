using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;



class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		helper(S, 0);
		return res;
	}
	void helper(string s, int idx) {
		if (idx == s.size())
			res.push_back(s);
		else if (s[idx] >= '0' && s[idx] <= '9')
			helper(s, idx + 1);
		else if (s[idx] >= 'a' && s[idx] <= 'z') {
			helper(s, idx + 1);
			s[idx] = s[idx] + 'A' - 'a';
			helper(s, idx + 1);
		}
		else if (s[idx] >= 'A' && s[idx] <= 'Z') {
			helper(s, idx + 1);
			s[idx] = s[idx] + 'a' - 'A';
			helper(s, idx + 1);
		}
	}
	vector<string> res;
};

int main() {


	return 0;
}