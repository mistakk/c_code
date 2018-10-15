#include <string>                                                                                                                                             
#include <vector>
#include <iostream>
using namespace std;

vector<string> strsplit(string s) {
    vector<string> ret;
    string tmp;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.' || s[i] == ':') {
            ret.push_back(tmp);
            tmp = "";
        }
        else
            tmp += s[i];
    }
    return ret;
}

class Solution {
public:
    int vvalidIPAddress(string IP)
    {
        vector<string> ret = strsplit(IP);
        int iptype = ret.size(); //4 8
        if (iptype != 4 && iptype != 8)
            return 0;
        if (iptype == 4) {
            for (int i = 0; i < iptype; ++i) {
                string now = ret[i];
                if (now.size() > 3)
                    return 0;
                int nowval = 0;
                for (int j = 0; j < now.size(); ++j) {
                    if (now[j] >= '0' && now[j] <= '9') {
                        nowval = nowval * 10 + now[j] - '0';
                        if (nowval > 255)
                            return 0;
                        if (j == 0 && now[j] == '0' && now.size() != 1)
                            return 0;
                    }
                    else
                        return 0;
                }
            }
        }
        else if (iptype == 8) {
            for (int i = 0; i < iptype; ++i) {
                string now = ret[i];
                if (now.size() > 4)
                    return 0;
                int nowval = 0;
                for (int j = 0; j < now.size(); ++j) {
                    if (now[j] >= '0' && now[j] <= '9') {
                        nowval = nowval * 10 + now[j] - 'a' + 10;
                        if (nowval > 255)
                            return 0;
                        if (j == 0 && now[j] == '0' && now.size() != 1)
                            return 0;
                    }
                    else  if (now[j] >= 'a' && now[j] <= 'f') {
                        {

                    }
                }
            }
        }
        else
            return 0
           
    }
    string validIPAddress(string IP)
    {
        int ret = vvalidIPAddress(IP);

        if (ret == 4)
            return "IPv4";
        else if (ret == 6)
            return "IPv6";
        return "Neither";
    }
};

int main() {
    vector<string> iplist{ "172.16.254.1" ,"01.01.01.01","0.0.0.0","0.0.0." };
    Solution a;
    for (auto ip : iplist)
        cout << a.validIPAddress("0.0.0.0") << endl;
    return 0;
}
