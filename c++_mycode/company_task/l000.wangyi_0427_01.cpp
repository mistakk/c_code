#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct player {
	int score;
	int cnt;
	int net_cnt;
	string name;
};
bool comp(player* a, player* b) {
	if (a->score != b->score)
		return a->score > b->score;
	if (a->net_cnt != b->net_cnt)
		return a->net_cnt > b->net_cnt;
	if (a->cnt != b->cnt)
		return a->cnt > b->cnt;
	if (a->name > b->name)
		return true;
	else
		return false;
}
int main() {
	int n = 2;
	int m = 6;
	vector<map<string,player*>> players;
	vector<vector<string>> names;
	vector<vector<player*>> vec_players;
	for (int i = 0; i < n; i++) {
		map<string, player*> mmm;
		players.push_back(mmm);
		vector<string> mmmname;
		names.push_back(mmmname);
		vector<player*>  mmmvec;
		vec_players.push_back(mmmvec);

		for (int j = 0; j < m; j++) {
			string name1;
			string atob;
			string name2;
			cin >> name1;
			cin >> atob;
			cin >> name2;
			int t1_score = atob[0] - '0';
			int t2_score = atob[2] - '0';

			if (find(names[i].begin(), names[i].end(), name1) == names[i].end()) {
				names[i].push_back(name1);
				player *temp = new player();
				temp->score = 0;
				temp->cnt = 0;
				temp->net_cnt = 0;
				temp->name = name1;
				players[i][name1] = temp;
			}

			if (find(names[i].begin(), names[i].end(), name2) == names[i].end()) {
				names[i].push_back(name2);
				player *temp = new player();
				temp->score = 0;
				temp->cnt = 0;
				temp->net_cnt = 0;
				temp->name = name2;
				players[i][name2] = temp;
			}

			players[i][name1]->cnt += t1_score;
			players[i][name1]->net_cnt += t1_score - t2_score;
			if (t1_score == t2_score)
				players[i][name1]->score += 1;
			else if (t1_score < t2_score)
				players[i][name1]->score += 0;
			else
				players[i][name1]->score += 3;

			players[i][name2]->cnt += t2_score;
			players[i][name2]->net_cnt += t2_score - t1_score;
			if (t1_score == t2_score)
				players[i][name2]->score += 1;
			else if (t1_score > t2_score)
				players[i][name2]->score += 0;
			else
				players[i][name2]->score += 3;
		}

		for (int iii = 0; iii < names[i].size(); iii++) {
			vec_players[i].push_back(players[i][names[i][iii]]);
		}
		sort((vec_players[i]).begin(), (vec_players[i]).end(), comp);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cout << vec_players[i][j]->name;
			cout << " ";
		}
		cout << vec_players[i][3]->name<<endl;
	}
	return 0;
	
}