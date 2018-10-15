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
		int res = 0;
		int flag = 1;
		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (c <= '9'&&c >= '0') {
				int num = 0;
				while (s[i] <= '9'&&s[i] >= '0') {
					num = num * 10 + s[i++] - '0';
				}
				i--;
				res += num * flag;
			}
			else if (c == '+')
				flag = 1;
			else if (c == '-')
				flag = -1;
			else if (c == '(') {
				st.push(res);
				st.push(flag);
				res = 0;
				flag = 1;
			}
			else if (c == ')') {
				res *= st.top();
				st.pop();
				res += st.top();
				st.pop();
			}
			else
				continue;
		}
		return res;
	}



	int calculate3(string s) {
		stack<int> stk;
		int res = 0;
		int sign = 1;
		int n = s.size();
		for (int i = 0; i < n; i++) {
			char c = s[i];
			if (c >= '0'&&c <= '9') {
				int num = 0;
				while (i < n&&s[i] >= '0') {
					num = num * 10 + s[i++] - '0';
				}
				res += sign * num;
				i--;
			}
			else if (c == '+') {
				sign = 1;
			}
			else if (c == '-') {
				sign = -1;
			}
			else if (c == '(') {
				stk.push(res);
				stk.push(sign);
				res = 0;
				sign = 1;
			}
			else if (c == ')') {
				res *= stk.top();
				stk.pop();
				res += stk.top();
				stk.pop();
			}
		}
		return res;
	}

	int calculate2(string s) {
		int n = s.size();
		int ret = 0;
		int tem_val = 0;
		bool flag = true;
		s += "#";
		for (int i = 0; i < n + 1; i++) {
			if (s[i] == ' ')
				continue;
			if (s[i] == '(') {
				int cntx = 1;
				int valnow = 0;
				string subs = "";
				for (int k = i + 1; k < n; k++) {
					if (s[k] == '(')
						cntx++;
					else if (s[k] == ')')
						cntx--;
					else if (s[k] == ' ')
						continue;
					if (cntx == 0 && s[k] == ')')
						break;
					subs += s[k];
					i = k + 1;
				}
				valnow = calculate(subs);
				if (flag)
					ret += valnow;
				else {
					ret -= valnow;
					flag = true;
				}
				continue;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				tem_val = tem_val * 10 + s[i] - '0';
				continue;
			}
			if (flag == false)
				ret -= tem_val;
			else
				ret += tem_val;
			tem_val = 0;
			if (s[i] == '-') {
				flag = false;
			}
			else if (s[i] == '+') {
				flag = true;
			}
		}
		return ret;
	}
};

int main() {
	Solution a;
	string s = "-(2-1+2)";
	cout << a.calculate(s) << endl;
	return 0;
}