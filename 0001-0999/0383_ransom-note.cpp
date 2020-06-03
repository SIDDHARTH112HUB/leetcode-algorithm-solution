//Link: https://leetcode.com/problems/ransom-note/ 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(128);
        for(auto c : magazine) {
            ++cnt[c];
        }
        for(auto c : ransomNote) {
            if(--cnt[c] < 0)
                return false;
        }
        return true;
    }
};