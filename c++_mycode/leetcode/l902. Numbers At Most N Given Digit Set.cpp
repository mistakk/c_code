#include <vector>
#include <iostream>
#include <map>
using namespace std;







//14.25 - 14.53
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int idx = 0;
        int cnt = 0;
        int data = N;
        int size = D.size();
        vector<int>foo(12, 0);
        vector<int>vec(11, 0);
        for (int i = 0; i < size; ++i)
            for (int j = (D[i][0] - '0'); j < 10; ++j)
            {
                vec[j + 1] += 1;
            }
        while (N != 0)
        {
            N = N / 10;
            idx++;
        }
        //init foo
        foo[1] = size;
        for (int i = 2; i <= idx; i++)
        {
            foo[i] = foo[i - 1] + pow(size, i);
        }

        cnt += foo[idx - 1];
        while (data != 0)
        {
            int nowmax = data / pow(10, idx - 1);
            data = data - nowmax * pow(10, idx - 1);
            
            if (idx - 1 != 0)
                cnt += vec[nowmax] * pow(size, idx - 1);
            else
                cnt += vec[nowmax + 1];
            
            idx--;
            if (vec[nowmax + 1] == vec[nowmax])
                break;
        }
        return cnt;
    }
};

int main() {
    Solution a;
    vector<string> st = { "3","5" };
    cout << a.atMostNGivenDigitSet(st, 3);
    return 0;
}