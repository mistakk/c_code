using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>

#include <fstream>
#include <numeric>




class Solution {
public:
	int calculate(string s) {
		stack<int> st;
		int num1, flag = 0, num2;
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c <= '9'&&c >= '0') {
				int num = 0;
				while (s[i] <= '9'&&s[i] >= '0') {
					num = num * 10 + s[i++] - '0';
				}
				i--;
				if (flag == 1) {
					flag = st.top(); st.pop();
					num1 = st.top(); st.pop();
					st.push(cal(num1, flag, num));
				}
				else if (flag == 0 && st.size() >= 3) {
					flag = st.top(); st.pop();
					num2 = st.top(); st.pop();
					int flag2 = st.top(); st.pop();
					num1 = st.top(); st.pop();
					st.push(cal(num1, flag2, num2));
					st.push(flag);
					st.push(num);
				}
				else
					st.push(num);
			}
			else if (c == '+' || c == '-') {
				st.push(c);
				flag = 0;
			}
			else if (c == '*' || c == '/') {
				st.push(c);
				flag = 1;
			}
			else
				continue;
		}
		if (st.size() == 1)
			return st.top();
		else {
			int num2 = st.top(); st.pop();
			flag = st.top(); st.pop();
			int num1 = st.top(); st.pop();
			return cal(num1, flag, num2);
		}
	}
	int cal(int num1, int flag, int num2) {
		if (flag == '+')
			return num1 + num2;
		else if (flag == '-')
			return num1 - num2;
		else if (flag == '*')
			return num1 * num2;
		return num1 / num2;
	}
};

int main() {
	Solution a;
	string s = "1*2-3/4+5*6-7*8+9/10";
	cout << a.calculate(s) << endl;
	return 0;
}