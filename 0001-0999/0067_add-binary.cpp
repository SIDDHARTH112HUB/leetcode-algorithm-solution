//Link: https://leetcode.com/problems/add-binary/ 
class Solution {
public:
    string addBinary(string a, string b) {
        int endA = a.size()-1;
        int endB = b.size()-1;
        string ans;
        int carry  = 0;
        while( endA>=0 || endB >=0){
            int sum = (endA>=0?a[endA--] -'0':0) + (endB>=0?b[endB--]-'0':0) + carry;
            carry = sum /2;
            ans+= sum%2>0?'1':'0';
        }
        if( carry > 0 )
            ans+='1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};