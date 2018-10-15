using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

template<typename T>
void show(vector<T> vec) {
	for (int i = 0; i != vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;

}
void show(map<string, int> mp) {
	std::map<string, int>::iterator m = mp.begin();
	for (; m != mp.end(); ++m)
		cout << "key is " << m->first << "  value is " << m->second << endl;
}
void show(vector<pair<string, int>> pairvec) {
	std::vector<pair<string, int>>::iterator p = pairvec.begin();
	for (; p != pairvec.end(); ++p)
		cout << "key is " << p->first << "  value is " << p->second << endl;
}


class Solution {
public:
	//Time complexity:  O(n^2)
	//Space complexity:  O(n^2)
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		std::map<int, int> mp;
		int cnt = 0;
		for(int i:C)
			for (int j : D)
				mp[i + j]++;
		for(int i:A)
			for (int j : B)
				cnt += mp[- i - j];
		return cnt;
	}
};





void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;
	vector<int>mp{ 1,3,2,4,5 };

	int ret = a.monotoneIncreasingDigits(1234);
	cout << ret << endl;

}