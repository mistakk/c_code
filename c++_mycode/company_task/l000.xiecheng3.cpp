using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <unordered_map>
#include <stdio.h>
class lrucache {
public:
	struct triple {
		int older;
		int younger;
		int value;
	};

	int capacity;
	unordered_map<int, triple> cache;  //key, next younger key, next older key, value
	int o_key;//oldest key, valid only if cache is non-empty
	int y_key;//youngest key, valid only if cache is non-empty
	lrucache(int capacity) { //assume capacity>0
		this->capacity = capacity;
		cache.clear();
	}

	int get(int key) {
		if (cache.count(key) > 0) {

			if (key != y_key) {  //need to update the ordering 
				if (key == o_key) {  //accessed key is the oldest one
					o_key = cache[key].younger;
					cache[key].older = y_key;
					cache[y_key].younger = key;
					y_key = key;
				}
				else {
					cache[cache[key].younger].older = cache[key].older;
					cache[cache[key].older].younger = cache[key].younger;
					cache[key].older = y_key;
					cache[y_key].younger = key;
					y_key = key;
				}
			}
			return cache[key].value;
		}
		return -1;
	}

	void set(int key, int value) {
		if (cache.empty()) {
			o_key = key;
			y_key = key;
			cache[key].value = value;
			return;
		}
		if (cache.count(key) > 0) { //already present
			cache[key].value = value;  //update value
			//get(key);
		}
		else {
			cache[key].value = value;  //insert entry
			cache[key].older = y_key;
			cache[y_key].younger = key;
			y_key = key;
			if (cache.size() > capacity) { //delete the oldest one
				o_key = cache[o_key].younger;
				cache.erase(cache[o_key].older);
			}
		}
	}
};
void split(const string& s, vector<int>& sv, const char flag = ' ') {
	sv.clear();
	istringstream iss(s);
	string temp;
	while (getline(iss, temp, flag)) {
		sv.push_back(stoi(temp));
	}
	return;
}
int main()
{
	vector<int> res;
	vector<int> temp;
	string s;
	getline(cin, s);
	int k = atoi(s.c_str());
	lrucache cache(k);
	getline(cin, s);
	while (s.size() > 1) {
		string s2(s.begin() + 2, s.end());
		split(s2, temp, ' ');
		if (s[0] == 'g')
		{
			res.push_back(cache.get(temp[0]));
		}
		else {
			cache.set(temp[0], temp[1]);
		}
		getline(cin, s);
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}

