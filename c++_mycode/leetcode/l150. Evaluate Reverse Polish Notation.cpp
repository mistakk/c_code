using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>

#include <fstream>
#include <numeric>



class Solution {
public:
	vector<string> getRPN(string s) {
		stack<char> s1;
		stack<int> s2;
		map<char, int>mp;
		vector<string> res;
		int s1top = -1;
		char c;
		mp['+'] = 1;
		mp['-'] = 1;
		mp['*'] = 2;
		mp['/'] = 2;
		mp['#'] = -1;

		for (int i = 0; i < s.size(); i++) {
			c = s[i];
			if (c <= '9'&& c >= '0') {
				int num = 0;
				while (s[i] <= '9'&&s[i] >= '0') {
					num = num * 10 + s[i++] - '0';
				}
				i--;
				res.push_back(to_string(num));
			}
			else if (c == '(') {
				s1.push(c);
			}
			else if (c == ')') {
				c = s1.top();
				while (c != '(') {
					string n = "";
					n += c;
					res.push_back(n);
					s1.pop();
					c = s1.top();
				}
				s1.pop();
			}
			else if (s1top < mp[c]) {
				s1.push(c);
				s1top = mp[c];
			}
			else if (s1top >= mp[c]) {
				c = s1.top(); s1.pop();
				string n = "";
				n += c;
				res.push_back(n);
				s1.push(s[i]);
				s1top = mp[c];
			}
			else
				continue;
		}
		while (!s1.empty()) {
			c = s1.top(); s1.pop();
			string n = "";
			n += c;
			res.push_back(n);
		}
		return res;
	}
	int evalRPN(vector<string>& tokens) {
		stack<int> s1;
		int num1, num2, flag;
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i].size()==1 && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/')) {
				num2 = s1.top(); s1.pop();
				num1 = s1.top(); s1.pop();
				cout << num1 << "  " << tokens[i][0] << " " << num2 << endl;
				s1.push(cal(num1, tokens[i][0], num2));
			}
			else
				s1.push(atoi(tokens[i].c_str()));
		}
		return s1.top();
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
	string s = "(1+2)*3";
	vector<string> ss = a.getRPN(s);
	for (auto aa : ss);
		//cout << aa << endl;
	ss = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
	cout << a.evalRPN(ss) << endl;
	return 0;
}