

using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#include <fstream>
#include <numeric>



//632
//17.23
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int>num1(n, 0);
        vector<int>num2(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            if (dominoes[i] == 'R') {
                int val = 0;
                while (i + 1 < n && dominoes[i + 1] == '.') {
                    num1[++i] = ++val;
                }
            }
        }
        for (int i = n - 1; i > 0; --i) {
            if (dominoes[i] == 'L') {
                int val = 0;
                while (i - 1 >= 0 && dominoes[i - 1] == '.') {
                    num2[--i] = ++val;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (num1[i] == 0 && num2[i] == 0)
                continue;
            else if (num1[i] == 0 && num2[i] != 0)
                dominoes[i] = 'L';
            else if (num2[i] == 0 && num1[i] != 0)
                dominoes[i] = 'R';
            if (num1[i] < num2[i])
                dominoes[i] = 'R';
            else if (num1[i] > num2[i])
                dominoes[i] = 'L';
        }
        return dominoes;
    }
};

int main() {
    string s = "RR.L";
    Solution a;
    a.pushDominoes(s);
    return 0;
}