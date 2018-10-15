using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1, INT_MAX));
        for (int i = 1; i <= n1; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n2; j++)
            dp[0][j] = j;
        for (int i = 1; i <= n1; i++)
            for (int j = 1; j <= n2; j++)
            {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        return dp[n1][n2];
    }
};



int main()
{
    string word1 = "horse";
    string word2 = "ros";
    Solution a;
    cout << a.minDistance(word1, word2);
    return 0;
}

