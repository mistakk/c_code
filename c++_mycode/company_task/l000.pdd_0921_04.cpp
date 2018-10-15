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
#include <iomanip>


int dfs(vector<int>&num, vector<vector<int>>&coup, int cost) {
    int m = cost;
    for (int j = 0; j < coup.size(); j++) {
        if (coup[j][0] < 0)
            continue;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] > 0 && coup[j][0] < num[i]) {

                cost -= coup[j][1];
                num[i] *= -1;
                coup[j][0] *= -1;

                m = min(m, dfs(num, coup, cost));

                cost += coup[j][1];
                num[i] *= -1;
                coup[j][0] *= -1;

            }
        }
    }
    return m;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<int>num(n, 0);
    vector<vector<int>>coup;
    int cost = 0;
    for (int i = 0; i > n; i++) {
        cin >> num[i];
        cost += num[i];
    }

    for (int i = 0; i <  m; i++) {
        cin >> a >> b;
        vector<int>mm{ a,b };
        coup.push_back(mm);
    }
    int mincost = cost;
    int ret = dfs(num, coup, cost);
    cout << ret;
    return 0;
}
