//using namespace std;
//#include <string>
//using namespace std;
//#include <string>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//#include <iostream>
//#include <sstream>
//#include <queue>
//#include <set>
//
//set<char>st1{ 'q', 'w', 'e', 'r', 't', 'a','s', 'd', 'f', 'g', 'z', 'x', 'c', 'v' };
//set<char>st2{ 'y','u', 'i', 'o', 'p', 'h', 'j' ,'k', 'l', 'b', 'n', 'm' };
//void split(const string& s, vector<string>& sv, const char flag = ' ') {
//    sv.clear();
//    istringstream iss(s);
//    string temp;
//
//    while (getline(iss, temp, flag)) {
//        sv.push_back(temp);
//    }
//    return;
//}
//int minDistance(string word1, string word2) {
//    int m = word1.length(), n = word2.length();
//    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
//    for (int i = 1; i <= m; i++)
//        dp[i][0] = 3 * i;
//    for (int j = 1; j <= n; j++)
//        dp[0][j] = 3 * j;
//    for (int i = 1; i <= m; i++) {
//        for (int j = 1; j <= n; j++) {
//            if (word1[i - 1] == word2[j - 1])
//                dp[i][j] = dp[i - 1][j - 1];
//            else {
//                bool same1 = (find(st2.begin(), st2.end(), word1[i - 1]) != st2.end());
//                bool same2 = (find(st2.begin(), st2.end(), word1[j - 1]) != st2.end());
//                if (same1 == same2) {
//                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
//                }
//                else {
//                    dp[i][j] = min(dp[i - 1][j - 1] + 2, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
//                }
//            }
//        }
//    }
//    return dp[m][n];
//}
//int main() {
//    string s;
//    vector<string>sv;
//    getline(cin, s);
//    split(s, sv, ' ');
//    int n = sv.size() - 1;
//    vector<pair<string, int>> vtMap;
//    for (int i = 1; i <= n; ++i) {
//        vtMap.push_back(make_pair(sv[i], minDistance(sv[0], sv[i])));
//    }
//    int min1 = INTMAX_MAX, cnt1 = 0;
//    for (int i = 0; i < vtMap.size(); i++) {
//        min1 = min(min1, vtMap[i].second);
//    }
//    for (int i = 0; i < vtMap.size(); i++) {
//        if (vtMap[i].second == min1) {
//            cnt1++;
//            cout << vtMap[i].first;
//            if (cnt1 != 3) {
//                cout << " ";
//            }
//            else {
//                return 0;
//            }
//        }
//    }
//
//    for (int i = 0; i < vtMap.size(); i++) {
//        cout << vtMap[i].first;
//        if (i != vtMap.size() - 1 && i < 2)
//            cout << " ";
//        if (i == 2)
//            break;
//    }
//    return 0;
//}


using namespace std;
#include <string>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
int main() {
    int a, b, c;
    //cin >> a >> b >> c;
    a = 2, b = 1, c = 1;
    vector<vector<vector<int>>>dp1(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, 0)));
    vector<vector<vector<int>>>dp2(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, 0)));
    vector<vector<vector<int>>>dp3(a + 1, vector<vector<int>>(b + 1, vector<int>(c + 1, 0)));
    dp1[1][0][0] = 1;
    dp2[0][1][0] = 1;
    dp3[0][0][1] = 1;
    for (int i = 0; i <= a; ++i)
        for (int j = 0; j <= b; ++j)
            for (int k = 0; k <= c; ++k) {
                if (i != 0)
                    dp1[i][j][k] = max(dp1[i][j][k], dp2[i - 1][j][k] + dp3[i - 1][j][k]);
                if (j != 0)
                    dp2[i][j][k] = max(dp2[i][j][k], dp1[i][j - 1][k] + dp3[i][j - 1][k]);
                if (k != 0)
                    dp3[i][j][k] = max(dp3[i][j][k], dp1[i][j][k - 1] + dp2[i][j][k - 1]);

            }
    cout << dp1[a][b][c] + dp2[a][b][c] + dp3[a][b][c] << endl;
    return 0;
}