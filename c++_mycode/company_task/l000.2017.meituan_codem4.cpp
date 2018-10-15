using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#include <fstream>

//链接：https://www.nowcoder.com/acm/contest/5/C
//		 来源：牛客网
//
//			 第一行一个整数 n (1≤n≤ 2 ^ 20)，表示参加比赛的总人数。
//
//			 接下来 n 个数字（数字范围： - 1000000…1000000），表示每个参赛者的积分。
//
//			 小美是第一个参赛者。
//			 输出描述 :
//		 小美最多参赛的轮次。

int niceSolve(vector<int>& points, int n) {
	int index = points[0];
	int count = 0;
	for (int i = 1; i<n; i++)    count += points[i]<index ? 1 : 0;
	return log2(count + 1);
}
int main2() {
	int n = 0;
	cin >> n;
	vector<int> points(n, 0);
	for (int i = 0; i<n; i++)    cin >> points[i];
	cout << niceSolve(points, n) << endl;
	return 0;
}
int main() {
	int n = 0;
	cin >> n;
	int xiaoming = 0, other = 0;
	cin >> xiaoming;
	int cnt = 1;
	for (int i = 0; i < n - 1; i++) {
		cin >> other;
		if (xiaoming >= other)
			cnt++;
	}
	cout << log2(cnt) << endl;
	return 0;
}