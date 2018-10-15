using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

//���ӣ�https://www.nowcoder.com/acm/contest/5/B
//��һ��һ������n(1 �� n �� 1000)����ʾ��һ����Ƶ�ĳ��ȡ�
//�ڶ���n��������ʾ��һ����Ƶ�����ߣ�0 �� ���� �� 1000����
//������һ������m(1 �� n �� m �� 1000)����ʾ�ڶ�����Ƶ�ĳ��ȡ�
//������m��������ʾ�ڶ�����Ƶ�����ߣ�0 �� ���� �� 1000����


int main() {
	vector<int> first(1001, 0);
	vector<int> second(1001, 0);
	int m = 0, n = 0, cnt = 0;

	cin >> n;
	while (cnt < n) {
		cin >> first[cnt++];
	}
	cin >> m;
	cnt = 0;
	while (cnt < m) {
		cin >> second[cnt++];
	}

	long long tempval = 0x3f3f3f3f3f3f3f3f;
	for (int i = 0; i < m - n; i++) {
		long long res = 0;
		for (int j = 0; j < n; j++) {
			res += pow(first[j] - second[i + j], 2);
		}
		tempval = min(tempval, res);
	}
	cout << tempval << endl;
	return 0;
}