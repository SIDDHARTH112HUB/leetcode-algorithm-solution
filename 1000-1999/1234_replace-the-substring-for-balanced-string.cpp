//Link: https://leetcode.com/problems/replace-the-substring-for-balanced-string/ 
class Solution {
public:
    bool check(vector<int> &cnt) {
        for(auto n : cnt){
            if(n > 0)
                return false;
        }
        return true;
    }
    int balancedString(string s) {
        int n = s.size() / 4;
        vector<char> v = {'Q', 'R', 'E', 'W'};
        unordered_map<int, int> m;
        vector<int> cnt(128);
        for(auto c : s) {
            ++m[c];
        }
        for(auto c : v) {
            if(m[c] > n){
                cnt[c] = m[c] - n;
                //cout<<c<<" "<<cnt[c]<<endl;
            }
        }
        if(check(cnt)) return 0;
        int ans = INT_MAX;
        int j = 0;
        int tmp = 0;
        int res = INT_MAX;
        for(int i = 0; i < s.size(); ++i) {
            //cout<<cnt[s[i]]<<endl;
            --cnt[s[i]];
            bool f = check(cnt);
            
            if(!f) continue;
            while(check(cnt)) {
                ++cnt[s[j++]];
            }
            //cout<<"i :"<<i<<" j:"<<j<<endl;
            res = min(res, i - j + 2);
        }
        return res;
    }
};