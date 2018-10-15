#include <iostream>
#include <vector>
using namespace std;
void qsort2(vector<int>&num, int start, int end) {
	if (start >= end)
		return;
	int key = num[start], start_old = start, end_old = end;
	while (start < end) {
		while (start < end && key <= num[end])
			end--;
		num[start] = num[end];
		while (start < end&&key >= num[start])
			start++;
		num[end] = num[start];
	}
	num[start] = key;
	qsort2(num, start_old, start - 1);
	qsort2(num, start + 1, end_old);
}
int bserarch_0(vector<int>num, int key) {
	//找到就返回一个，没找到就返回-1
	int start = 0, end = num.size() - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (num[mid] == key)
			return mid;
		else if (num[mid] > key)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return -1;
}
int bsearch_1(vector<int>num, int key) {
	//如果有多个 返回最左边那个；如果没有返回-1
	int start = 0, end = num.size() - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (num[mid] >= key)
			end = mid - 1;
		else
			start = mid + 1;
	}
	if (start < num.size() && num[start] == key)
		return start;
	return -1;
}
int sort_3(vector<int>num, int val) {
	int left = 0, right = num.size() - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (num[mid] < val) 
			left = mid + 1;
		else
			right = mid - 1;
	}
	return right;
}
int main() {
	vector<int> num{ 7,6,6,4,696,1,2,3,6,4,1,0,4,6,6,5,4,1,2,6,4,5 };//
	qsort2(num, 0, num.size() - 1);
	for (int i = 0; i < num.size(); i++)
		cout << num[i] << " ";
	cout << endl;
	int idx = sort_3(num, 4);
	cout << idx << endl;
	return 0;
}
