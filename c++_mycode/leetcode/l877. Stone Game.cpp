#include <vector>
using namespace std;

//12.45 - 13.17
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<pair<int, int>>> num(n, vector<pair<int, int>>(n));
        for (int i = 0; i < n; i++) {
            num[i][i] = make_pair(piles[i], 0);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                int row = j;
                int col = i + j;
                int left_val = piles[row] + num[row + 1][col].second;
                int right_val = piles[col] + num[row][col - 1].second;
                num[row][col] = left_val > right_val ? make_pair(left_val, num[row + 1][col].first) : make_pair(right_val, num[row][col - 1].first);
            }
        }
        return num[0][n - 1].first > num[0][n - 1].second;
    }
};

int main() {
    Solution a;
    vector<int> num{ 5,3,4,5 };
    a.stoneGame(num);
    return 0;
}