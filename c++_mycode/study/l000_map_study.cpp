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


typedef pair<string, int> T;
bool cmp_by_size(T lhs, T rhs)
{
	return lhs.first.size() > rhs.first.size();
};

typedef pair<string, int> T;
struct CmpByvalue
{
	bool operator()(T lhs, T rhs)
	{
		return lhs.second > rhs.second;
	}
};


//
//class Map_study {
//public:
//	
//};



void main()
{
	std::map<string, int> mp;
	mp["abceeeee"] = 1;
	mp["abcd"] = 3;
	mp["abcde"] = 2;
	mp["abcdef"] = 4;
	vector<pair<string,int>> name_score_vec(mp.begin(), mp.end());
	show(name_score_vec);

	sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_size);
	//show(mp);

	show(name_score_vec);
}