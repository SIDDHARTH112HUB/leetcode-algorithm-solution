//Link: https://leetcode.com/problems/palindrome-partitioning-iii/ 
class Solution {
public:
    map<int, map<int, int> > m;
    int palindromePartition(string s, int k) {
        //cout<<"begin"<<endl;
        if(s.size() <= k) return 0;
        return h(s, 0, k);
    }
    int diff(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != s[s.size()-i-1])++ans;
        }
        return ans/2;
    }
    int h(string &s, int idx, int k) {
        if(m[idx].count(k)) return m[idx][k];
        if(k == 1) {
            return diff(s.substr(idx));
        }
        if(idx >= s.size()) {
            if(k == 0) return 0;
            return 100;
            //return 0;
        }
        int res = INT_MAX;
        for(int i = idx+1; i <= s.size(); ++i) {
            int d = diff(s.substr(idx, i-idx));
            //cout<<s.substr(idx, i-idx)<<" "<<d<<endl;
            res = min(res, d + h(s, i, k-1));
        }
        if(res >= 100) res = 100;
        m[idx][k] = res;
        return res;
    }
};