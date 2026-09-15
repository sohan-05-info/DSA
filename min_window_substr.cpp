#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
bool fun(vector<int> &have, vector<int> &need) {
    for(int i = 0; i < 256; i++) {
        if(have[i] < need[i])
        return false;
    }
    return true;

}
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<int> have(256,0);
        vector<int> need(256,0);
        if(m < n)
        return "";
        for(int i = 0; i < n; i++)
        need[t[i]]++;


        int low = 0;
        int high = 0;
        int res = INT_MAX;
        int start = -1;
        for(high = 0; high < m; high++) {
            have[s[high]]++;

            while(fun(have,need)) {
                int len = high - low + 1;
                if(res > len) {
                    res = len;
                    start = low;
                }

                have[s[low]]--;
                low++;

            }
        }
        if(res == INT_MAX)
        return "";
        return s.substr(start, res);

    }
};