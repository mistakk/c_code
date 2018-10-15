using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size(), i = len - 1;
		while (i >= 0 && s[i] == ' ')
		{
			i--;
		}
		len =  i+1;
		while (i >= 0 && s[i] != ' ') {
			i--;
		}
		return len - i-1;
	}
};

void main()
{
	Solution a;
	string aa = "ffffs ";
	cout << a.lengthOfLastWord(aa);

}

