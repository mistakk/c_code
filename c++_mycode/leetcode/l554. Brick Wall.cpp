using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	int leastBricks2(vector<vector<int>>& wall) {
		int h = wall.size(), m = 0, i, j, cnt;
		for(i = 0; i < wall[0].size(); i++)
			m += wall[0][i];
		vector<int> num;
		for (i = 0; i < m; i++) {
			num.push_back(h);
		}
		for (j = 0; j < h; h++) {
			cnt = 0;
			for (i = 0; i < wall[j].size(); i++) {
				cnt += wall[j][i];
				num[cnt]--;
			}
		}
		int minv = h;
		for (i = 0; i < m; i++)
			if (num[i] < minv)
				minv = num[i];
		return minv;
	}

	int leastBricks(vector<vector<int>>& wall) {
		map<int, int> mp;
		int count = 0, i, j, cnt;
		for (i = 0; i < wall.size(); i++) {
			cnt = 0;
			for (j = 0; j < wall[i].size()-1; j++) {
				cnt += wall[i][j];
				mp[cnt] += 1;
				map<int, int>::iterator it = mp.find(cnt);
				if (it == mp.end())
					mp[cnt] = 1;
				else
					mp[cnt] += 1;
			}
		}
		for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
			if (count < it->second)
				count = it->second;
		return wall.size() - count;
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	string s = "123456789123456789";
	printf("s\n", s);
	cout << "checkbad letter" << endl;

}