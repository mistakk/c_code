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
	vector<vector<int> > subsetsWithDup2(vector<int> &S) {
		vector<vector<int> > totalset = { {} };
		sort(S.begin(), S.end());
		for (int i = 0; i<S.size();) {
			int count = 0; // num of elements are the same
			while (count + i<S.size() && S[count + i] == S[i])
				count++;
			int previousN = totalset.size();
			for (int k = 0; k<previousN; k++) {
				vector<int> instance = totalset[k];
				for (int j = 0; j<count; j++) {
					instance.push_back(S[i]);
					totalset.push_back(instance);
				}
			}
			i += count;
		}
		return totalset;
	}
	
	
	
	vector<vector<int>> subsetsWithDup(vector<int> &S) {
		vector<vector<int>> ret = { {} };
		sort(S.begin(), S.end());
		for (int i = 0; i < S.size();) {
			int count = 0;
			while (i + count < S.size() && S[i] == S[i + count]){
				count++;
			}
			int previous_cnt = ret.size();
			for (int ii = 0; ii < previous_cnt; ii++) {
				vector<int> temp = ret[ii];
				for (int j = 0; j < count; j++) {
					temp.push_back(S[i]);
					ret.push_back(temp);
				}
			}
			i += count;
		}
		return ret;
	}
};
void main()
{
	Solution a;
	vector<int> nums{ 1,2,2 };
	cout << "sys start!" << endl;
	vector<vector<int>> aa = a.subsetsWithDup(nums);
	for (auto s : aa) {
		for (auto ss : s) {
			cout << ss;
			cout << "";
		}
		cout << endl;
	}

}