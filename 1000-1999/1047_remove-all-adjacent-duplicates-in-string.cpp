//Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/ 
class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        for(auto c : S){
            if(ans.size() == 0 || ans.back() != c) {
                ans += c;
                continue;
            }
            while(ans.size() && ans.back() == c)
                ans.pop_back();
        }
        return ans;
    }
};