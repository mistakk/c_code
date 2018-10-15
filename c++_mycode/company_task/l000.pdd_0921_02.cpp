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


int main() {
    int n;
    cin >> n;
    if (n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<int>num(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int best_idx = -1;//updated if best_cnt updated
    int best_cnt = -1;
    int now_cnt = 0;
    for (int i = 1; i <= 1000; i++) {
        now_cnt = 0;
        vector<int>huancun(i, -1);
        for (int j = 0; j < n; j++) {
            if (huancun[num[j] % i] != num[j]) {
                huancun[num[j] % i] = num[j];
            }
            else {
                now_cnt += 1;
            }
        }
        if (now_cnt > best_cnt) {
            now_cnt = best_cnt;
            best_idx = i;
        }
    }
    cout << best_idx << endl;


    return 0;
}