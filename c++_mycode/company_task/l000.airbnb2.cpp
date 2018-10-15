using namespace std;
//#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>


vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    int maxval = 0, ret = 0;
    vector<long>num(n + 1, 0);
    for (int i = 0; i < queries.size(); ++i) {
        int p = queries[i][0];
        int q = queries[i][1];
        int val = queries[i][2];
        num[p] += val;
        if (q + 1 < n)
            num[q + 1] -= val;
    }
    for (int i = 0; i <= n; ++i) {
        maxval = maxval + num[i];
        ret = max(maxval, ret);
    }
    return ret;
}

int main()
{
    vector<vector<int>>queries;
    queries = { {1,5,3}, {5,8,7}, {6,9,1} };
    cout<<arrayManipulation(10, queries);
    return 0;
}
