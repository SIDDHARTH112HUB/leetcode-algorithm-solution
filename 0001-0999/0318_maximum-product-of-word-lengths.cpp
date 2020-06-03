//Link: https://leetcode.com/problems/maximum-product-of-word-lengths/ 
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> m;
        int ans = 0;
        for(auto &w : words) {
            int n = 0;
            for(auto c : w) 
                n |=  1 << (c - 'a');
            m[n] = max(m[n], (int)w.size());
            for(auto &it : m) {
                if((n & it.first) ==0)
                    ans = max(ans, (int)w.size() * it.second);
            }
        }
        return ans;
    }
};