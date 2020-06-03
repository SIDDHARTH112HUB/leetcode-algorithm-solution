//Link: https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/ 
class Solution {
public:
    int uniqueLetterString(string S) {
        unordered_map<int, vector<int> >m;
        for(int i = 0; i < S.size(); ++i) {
            m[S[i]].push_back(i);
        }
        long long ans = 0;
        int M = 1e9 + 7;
        for(auto it : m) {
            auto &v = it.second;
            for(int i = 0; i < v.size(); ++i) {
                int l = (i > 0 ? v[i-1]  : -1)+1;
                int r = (i == v.size() -1 ? S.size() : v[i+1])-1;
                int cur = v[i];
                int sum = cur - l + r - cur + (cur - l ) *  (r-cur) + 1;
                (ans += sum) %= M;
            }
        }
        return ans;
    }
};