using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	
	bool validPalindrome(string s) {
		int start = 0, end = s.size() - 1;
		bool flag = true;
		while (start < end)
		{

			while (!is_letter(s[start]) && start < end)
				start++;
			while (!is_letter(s[end]) && start < end)
				end--;

			if (!letter_same(s[start], s[end]) && start < end)
				if (flag)
					return isPalindrome(s.substr(start, end - start)) || isPalindrome(s.substr(start + 1, end - start));
				else
					return false;
			start++;
			end--;
		}
		return true;
	}

	bool isPalindrome(string s) {
		int start = 0, end = s.size() - 1;
		while (start < end)
		{
			while (!is_letter(s[start]) && start < end)
				start++;
			while (!is_letter(s[end]) && start < end)
				end--;

			if (!letter_same(s[start], s[end]) && start < end)
				return false;
			start++;
			end--;
		}
		return true;
	}

	bool letter_same(char a, char b)
	{
		if ((b >= 'a' && b <= 'z') && (b == a - 'A' + 'a'))
			return true;
		if ((b >= 'A' && b <= 'Z') && (b == a - 'a' + 'A'))
			return true;
		if (b == a)
			return true;
		return false;
	}

	bool is_letter(char a)
	{
		if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z') || (a >= '0' && a <= '9'))
			return true;
		return false;
	}
};

void main()
{
	Solution x;
	cout << x.validPalindrome("aydmda") << endl;

}