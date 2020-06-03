//Link: https://leetcode.com/problems/add-strings/ 
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size()-1, j=num2.size()-1;
        int carry = 0;
        while( i >= 0 || j >= 0 || carry > 0){
            int a = 0, b= 0;
            if( i >= 0 )
                a = num1[i] - '0';
            if( j >= 0 )
                b = num2[j] - '0';
            ans += ((a+b+carry) % 10) +'0';
            carry = int( a+b+carry >= 10 );
            i--;j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};