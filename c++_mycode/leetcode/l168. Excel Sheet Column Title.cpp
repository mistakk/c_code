using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

class Solution {
public:
	string convertToTitle(int n) {
		string ret = "";
		while (n != 0) {
			char x = n % 26 + 'A' - 1;
			ret = x + ret;
			n = n / 26;
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
string convertToTitle(int n) {
	string ret = "";
	while (n > 0) {
		char x = (n-1) % 26 + 'A';
		ret = x + ret;
		n = (n - (n - 1) % 26 )/26;
	}
	return ret;
}
void main()
{
	cout << convertToTitle(701) << endl;

}