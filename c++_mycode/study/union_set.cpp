using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

int findp(vector<int>&father, int k) 
{       
    if (k != father[k])                         //there must be reference call
    {
        father[k] = findp(father, father[k]);   //path compress
    }
    return father[k];
}

int unionp(vector<int>&father, int a, int b)
{
    int pa = findp(father, a);
    int pb = findp(father,b);
    if (pa != pb)
    {
        father[b] = pa;
    }
    return father[b];                           //after return, every onde should run find to mantaince the poprotity
}

int main() {
    int n = 4;
    vector<int>father{ 1,2,3,3 };
    findp(father, 0);
    return 0;
}