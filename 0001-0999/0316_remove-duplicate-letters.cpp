//Link: https://leetcode.com/problems/remove-duplicate-letters/ 
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<int, int> m;
        unordered_set<int> v;
        for(auto c : s)
            ++m[c];
        string ans;
        for(auto c : s) {
            --m[c];
            if(v.count(c)) continue;
            while(ans.size() && ans.back() > c && m[ans.back()] > 0) {
                v.erase(ans.back());
                ans.pop_back();
            }
            ans += c;
            v.insert(c);
        }
        return ans;
    }
};