using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		map<int, int> mp; //����ʼ�㵽 ��mp[x]����� ��Ϊ x��
		int cnt = 0;
		mp[0] = 1;
		int sum = 0;
		for (auto i : nums) {
			sum += i;			//��ʼ�㵽���µ�ĺ�Ϊsum
			mp[sum] += 1;		//��ʼ�㵽��Ϊsum�ĵ����Ϊmp[sum]
			cnt += mp[k - sum];	//��ʼ�㵽ĳ��ĺ�Ϊsum-k�� �м������ĵ��Ϊk   �ܺ�Ϊk         �м��ļ���Ϊmp[k-sum]
		}
		return cnt;
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<vector<int>> times;
	times.push_back(vector<int>{2, 1, 1});
	times.push_back(vector<int>{2, 3, 1});
	times.push_back(vector<int>{3, 4, 111});

	cout << "sys start!" << endl;
	vector<int> te{ 5,1 };


}