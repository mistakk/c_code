using namespace std;
#include <string>
#include <iostream>
#include <vector>


class Solution {
public:
	string multiply(string num1, string num2) {
		num1 = reverse(num1);
		num2 = reverse(num2);
		int multiply, add;
		int lensum = num1.size() + num2.size();
		string re(lensum, '0');
		for (int i = 0; i <num1.size(); i++) {
			multiply = 0, add = 0;
			for (int j = 0; j < num2.size(); j++) {
				int temp = (num1[i] - '0')*(num2[j] - '0') + multiply;
				multiply = temp / 10;
				int left = temp % 10;

				int temp2 = left + re[i + j] - '0' + add;
				re[i + j] = temp2 % 10 + '0';
				add = temp2 / 10;
			}
			re[i + num2.size()] = add + multiply + '0';
		}
		re = reverse(re);
		while (re[0] == '0')
			re.erase(0, 1);
		if (re.length() == 0)
			re = '0';
		return re;
	}
	string reverse(string &s) {
		int i = 0, j = s.size() - 1;
		char temp;
		while (i < j) {
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;
		}
		
		return s;
	}
};

void main()
{
	Solution a;
	cout << a.multiply("123", "000000") << endl;
}

