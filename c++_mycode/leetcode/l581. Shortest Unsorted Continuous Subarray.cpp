using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <list>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		bool flag_up = true, flag_down = true;
		int first_index = nums.size() - 1, end_index = 0;
		vector<int>::iterator  it_first = nums.begin();
		vector<int>::reverse_iterator  it_end = nums.rbegin();
		for (vector<int>::iterator it = nums.begin(); it != nums.end() - 1; ++it) {
			if (*it <= *(it + 1))
				continue;
			else {
				first_index = distance(it_first, it);
				break;
			}
		}
		for (vector<int>::reverse_iterator it = nums.rbegin(); it != nums.rend() - 1; ++it) {
			if (*it >= *(it + 1))
				continue;
			else {
				end_index = nums.size() - distance(it_end, it) -1;
				break;
			}
		}
		cout << first_index << "___" << end_index << endl;
		return 0;
	};
};
bool check_send(char * sout) {
	if (sout == NULL)
		return false;
	int i = 0;
	char target[9] = "/tmp/php";
	int cnt = 0;
	while (cnt < 8 && sout[cnt]!=NULL && sout[cnt]!='\0'){
		if (target[cnt] != sout[cnt])
			return false;
		cnt++;
	}
	if (cnt != 8)
		return false;
	return true;
}





void main()
{

	map<string, int> mp;
	vector<int> nums{ 1,2,3,4,5,6,5,4,1};
	//Solution a;
	//a.findUnsortedSubarray(nums);
	char *sout = "/tmp/php";
	cout << check_send(sout) << endl;

		 

}
int sss() {
	list<int> mylist;
	for (int i = 0; i < 10; i++) mylist.push_back(i * 10);

	list<int>::iterator first = mylist.begin();
	list<int>::iterator last = mylist.end();
	list<int>::iterator it = first;
	for (; it != last; ++it)
		cout << "第" << distance(first, it) << "个元素的值为：" << *it << endl;
	return 0;
}