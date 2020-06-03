//Link: https://leetcode.com/problems/largest-number/ 
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        vector<string> str;
        for(int n : nums)
            str.push_back(to_string(n));
        sort(str.begin(), str.end(), [](string &a, string &b){
            
            return a+b > b+a;
        });
        string ans;
        for( string &s:str)
            ans+=s;
        if( ans[0] == '0') return "0";
        return ans;
    }
};