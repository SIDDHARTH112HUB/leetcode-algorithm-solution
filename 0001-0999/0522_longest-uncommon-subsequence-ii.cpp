//Link: https://leetcode.com/problems/longest-uncommon-subsequence-ii/ 
class Solution {
public:
    int h(string &s1, string &s2) {
        int i = 0, j = 0;
        for(; i < s2.size() && j < s1.size(); ++j) {
            if(s2[i] == s1[j])
                ++i;
        }
        return i == s2.size();
    }
    int findLUSlength(vector<string> &strs) {
        // write your code here
        sort(strs.begin(), strs.end(), [](auto &s1, auto &s2){
            if(s1.size() == s2.size()) {
                return s1 < s2;
            }
            return s1.size() > s2.size();
        });
        int i = 1;
        for(int i = 0; i < strs.size(); ++i) {
            int flag = false;
            for(int j = 0; j < strs.size(); ++j) {
                if(i == j) continue;
                flag = flag || h(strs[j], strs[i]);
                if(flag) break; 
            }
            if(!flag) return strs[i].size();
        }
        return -1;
    }
};