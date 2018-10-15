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



// Employee info
class Employee {
	public:
	// It's the unique ID of each node.
	// unique id of this employee
		int id;
		// the importance value of this employee
		int importance;
		// the id of direct subordinates
		vector<int> subordinates;
};

class Solution {
public:
	int getImportance(vector<Employee*> employees, int id) {
		std::map<int, int> mp_val;
		std::map<int, vector<int>> mp_sub;
		for (int i = 0; i < employees.size(); ++i)
		{
			Employee *p = employees[i];
			mp_val[p->id] = p->importance;
			for(int j = 0; j < p->subordinates.size();++j)
				mp_sub[p->id].push_back(p->subordinates[j]);
		}
		int ret = mp_val[id];;
		vector<int> toadd{ id };
		while (!toadd.empty())
		{
			id = *toadd.end();
			toadd.pop_back();
			
			for (int i = 0; i < mp_sub[id].size(); ++i)
			{
				ret += mp_val[mp_sub[id][i]];
				toadd.push_back(mp_sub[id][i]);
			}
		}

		return ret;
	}
};


void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;
	std::vector<Employee*> employees;
	Employee *p = new Employee();
	p->id = 1;
	p->importance = 5;
	p->subordinates = { 2,3 };
	employees.push_back(p);

	Employee *p1 = new Employee();
	p1->id = 2;
	p1->importance = 3;
	p1->subordinates = { };
	employees.push_back(p1);


	Employee *p2 = new Employee();
	p2->id = 3;
	p2->importance = 3;
	p2->subordinates = { };
	employees.push_back(p2);

	int id = 1;

	std::map<int, int> mp_val;
	std::map<int, vector<int>> mp_sub;
	for (int i = 0; i < employees.size(); ++i)
	{
		Employee *p = employees[i];
		mp_val[p->id] = p->importance;
		for (int j = 0; j < p->subordinates.size(); ++j)
			mp_sub[p->id].push_back(p->subordinates[j]);
	}
	int ret = mp_val[id];;
	vector<int> toadd{ id };
	while (!toadd.empty())
	{
		id = *(toadd.end()-1);
		toadd.pop_back();

		for (int i = 0; i < mp_sub[id].size(); ++i)
		{
			ret += mp_val[mp_sub[id][i]];
			toadd.push_back(mp_sub[id][i]);
		}
	}
	cout << ret << endl;

}