using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int i = 0, count = 0;
		while (i < flowerbed.size()) {
			if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
				flowerbed[i++] = 1;
				count++;
			}
			if (count >= n)
				return true;
			i++;
		}
		return false;
	}
};
void main()
{

	vector<int> mp{ 1,0,0,0,0,0,1 };
	Solution a;
	cout << a.canPlaceFlowers(mp,1)<< endl;



}