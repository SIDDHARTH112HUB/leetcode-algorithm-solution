//Link: https://leetcode.com/problems/plus-one/ 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for( int i = digits.size()-1; i>=0; i--){
            int &n = digits[i];
            n+=carry;
            carry = n/10;
            n = n%10;
            if( !carry )
                return digits;
        }
        if( carry ){
            vector<int> ans(digits.size()+1, 0);
            ans[0] = 1;
            return ans;
        }else{
            return digits;
        }
        
    }
};