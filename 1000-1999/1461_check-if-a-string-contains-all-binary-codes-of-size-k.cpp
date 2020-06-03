//Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/ 
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() <= k) return false;
        unordered_map<string, int> m;
        // cout<<"begin"<<endl;
        for(int i = 0; i <= s.size() - k; ++i) {
            // cout<<s.substr(i, k)<<" ";
            ++m[s.substr(i, k)];
        }
        return m.size() >= (1 << k);
    }
};