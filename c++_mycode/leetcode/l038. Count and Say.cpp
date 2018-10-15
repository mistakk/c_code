using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	string countAndSay(int n) {
		if (n < 0)
			return "";
		string re = "1";
		if (n == 1)
			return re;
		string news="";
		int flag;
		for (int i = 1; i < n; i++) 
		{
			flag = 0;
			while (flag < re.size()) 
			{
				char x = re[flag];
				int j = 1;
				while (flag + j< re.size() &&re[flag + j] == x) 
					j++;
				news += '0' + j;
				news += x;
				flag += j;
			}
			re = news;
			news = "";
		}
		return re;
	}
};

void main()
{
	Solution a;
	cout << a.countAndSay(5);
}

