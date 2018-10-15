using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>

int main()
{
	int n;
	cin >> n;
	vector<int>num(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	if (n < 2)
		return n;
	vector<vector<int>>res;
	queue<vector<pair<int, int>>>q;
	pair<int, int> pa = make_pair(num[0], num[0]);
	vector<pair<int, int>>re{ pa };
	q.push(re);
	int idx = 1;
	int minval = n;
	while (idx < n) {
		//process num[idx];
		int cnt = q.size();
		while (cnt--) {
			re = q.front(), q.pop(); // 1,2   3,3
			for (int i = 0; i < re.size(); i++) {
				pa = re[i];
				if (pa.first == pa.second) {
					if (num[idx] != pa.second) {
						pair<int, int>new_pair1 = make_pair(pa.first, num[idx]);
						pair<int, int>new_pair2 = make_pair(num[idx], pa.first);
						vector<pair<int, int>>re_new1(re);
						vector<pair<int, int>>re_new2(re);
						re_new1[i] = new_pair1;
						q.push(re_new1);
						re_new2[i] = new_pair2;
						q.push(re_new2);
					}
				}
				else if (pa.first < pa.second) {
					if (num[idx] > pa.second) {
						pair<int, int>new_pair = make_pair(pa.first, num[idx]);
						vector<pair<int, int>>re_new(re);
						re_new[i] = new_pair;
						q.push(re_new);
					}
				}
				else if (pa.first > pa.second) {
					if (num[idx] < pa.second) {
						pair<int, int>new_pair = make_pair(num[idx], pa.second);
						vector<pair<int, int>>re_new(re);
						re_new[i] = new_pair;
						q.push(re_new);
					}
				}
			}
			pair<int, int>new_pair = make_pair(num[idx], num[idx]);
			re.push_back(new_pair);
			q.push(re);
		}
		idx++;
	}
	int cnt = q.size();
	while (cnt--) {
		re = q.front(), q.pop(); // 1,2   3,3
		if (minval > re.size())
			minval = re.size();
	}
	cout << "minval is " << minval << endl;

	return 0;
}
