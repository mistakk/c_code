using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
#include <vector>
#include <unordered_set>

//���ӣ�https://www.nowcoder.com/acm/contest/5/F
//���ŵ������кܶ�͹��Ż�ȯ���û����������ŵ���App�Ϲ���ÿ���Ż�ȯ��һ��Ψһ����������š����û�����Ӧ�͹ݾͲ�ʱ�������ڲ͹�ʹ���Ż�ȯ�������ѡ��Ż�ȯ�Ĺ����ʹ�ð���ʱ��˳�����м�¼����־�ļ��У���Ӫ��Ա�ᶨ�ڳ����־�ļ���ҵ���Ƿ���ȷ��ҵ����ȷ�Ķ���Ϊ��һ���Ż�ȯ�����ȱ�����Ȼ����ܱ�ʹ�á�


int main() {
	int m = 0; cin >> m;
	//����һ��ռ���������ÿһ�����Ż�ȯ��״̬  
	//��һλ��ʾ�Ż�ȯ����Ŀ���ڶ�λ��ʾ�Ż�ȯ���ϴα��õ���ʱ��  
	vector<vector<int>> coupons(500005, vector<int>(2, 0));
	set<int> marks;
	for (int i = 1; i <= m; i++) {
		char sign = ' '; cin >> sign;
		if (sign != '?') {
			int x = 0; cin >> x;
			//��¼�Ż�ȯ�Ĳ���  
			int opt = sign == 'I' ? 1 : -1;
			coupons[x][0] += opt;
			if (coupons[x][0] > 1 || coupons[x][0] < 0) {
				//��marks���棬����з�������һ���õ�����Ĳ�ȷ������  
				//���øò�ȷ�����������������̱�ú���  
				if (marks.lower_bound(coupons[x][1]) == marks.end()) {
					cout << i << endl;
					return 0;
				}
				marks.erase(marks.lower_bound(coupons[x][1]));
				coupons[x][0] = min(max(coupons[x][0], 0), 1);
			}
			//���¸������Ż�ȯ����һ�α��õ���ʱ��  
			coupons[x][1] = i;
		}
		else    
			marks.insert(i);
	}
	cout << -1 << endl;
	return 0;
}