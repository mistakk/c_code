using namespace std;
#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> stk;
		string name_tmp = "";
		path.push_back('/');
		cout << path << endl;
		for (int i = 0; i < path.size(); i++) {
			if (path[i] == '/') {
				if (name_tmp.size() == 0)
					continue;
				else if (name_tmp == "..") {
					if (!stk.empty())
						stk.pop_back();
				}
				else if (name_tmp == ".") {
					//no nothing
				}
				else {
					stk.push_back(name_tmp);
				}
				name_tmp.clear();
			}
			else
				name_tmp.push_back(path[i]);
		}
	
		if (stk.empty())
			return "/";
		for (int i = 0; i < stk.size()-1; i++) {
			name_tmp = name_tmp + "/" + stk[i];
		}
		return name_tmp;
	
	}

	
};


void main()
{
	Solution a;
	cout << a.simplifyPath("/...") << endl;
}