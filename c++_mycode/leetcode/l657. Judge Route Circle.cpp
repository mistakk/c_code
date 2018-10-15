using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INT_MAX 0x7fffffff

#define INT_MIN 0x80000000

void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}
class Solution {
public:
	bool judgeCircle(string moves) {
		int c1 = 0;
		int c2 = 0;
		string::reverse_iterator  it = moves.rbegin();
		for (string::iterator it = moves.begin(); it != moves.end(); ++it) {

			switch (*it){
				case 'R':
					c1 = c1 + 1;
					break;
				case 'L':
					c1 = c1 - 1;
					break;
				case 'U':
					c2 = c2 +1;
					break;
				case 'D':
					c2 = c2 - 1;
					break;
			}
		}
		if (c1 != 0 || c2 != 0)
			return false;
		else
			return true;
	}
};

void main()
{
	string s = "LRLRDUDU";
	Solution a;
	printf("result is %d", a.judgeCircle(s));



}
