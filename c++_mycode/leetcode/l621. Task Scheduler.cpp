using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int>mp(26,0);
		int length_tasks = tasks.size();
		for (int i = 0; i < length_tasks; ++i) {
			mp[tasks[i]-'A']++;
		}
		int maxmp = 0, max_cnt=0;
		for (int it = 0; it < 26; ++it) {
			if (maxmp < mp[it]) {
				maxmp = mp[it];
				max_cnt = 1;
			}else if (maxmp == mp[it])
				max_cnt++;
		}
		int need = (n+1)*(maxmp-1)+ max_cnt - length_tasks;
		if (need > 0)
			return length_tasks + need;
		else
			return length_tasks;
	}
};
void main()
{

	vector<char> tasks{'A','A','A','B','B','B'};
	Solution a;

	cout <<a.leastInterval(tasks,2)<< endl;

}