using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

class Solution {
public:
	int titleToNumber(string s) {
		int ret = 0;
		for (auto c : s) {
			ret = ret * 26 + c - 'A' + 1;
		}
		return ret;
	}

};
int titleToNumber(string s) {
	int ret = 0;
	for (auto c : s) {
		ret = ret * 26 + c - 'A' + 1;
	}
	return ret;
}
void main()
{
	cout << titleToNumber("ZY") << endl;
	 
}