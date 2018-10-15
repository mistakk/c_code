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
	bool isOneBitCharacter(vector<int>& bits) {
		for (int i = 0; i < bits.size(); i++) {
			if (bits[i] == 1) {
				i += 1;
				if (i == bits.size()-1)
					return false;
			}
		}
		return true;
	}
};
void main()
{

	map<string, int> mp;
	Solution a;
	vector<int> bits{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 };
	cout << a.isOneBitCharacter(bits);

}