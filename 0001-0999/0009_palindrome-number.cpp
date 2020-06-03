//Link: https://leetcode.com/problems/palindrome-number/ 
class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0)  return false;
        if( x < 10 ) return true;
        int check = 1000000000;
        while( x/check == 0)
        {
            check/=10;
        }
        while( x/check == x%10 )
        {
            
            x = x%check;
            x/=10;
            check/=100;
            if( x < 10 && check<=10 )
                return true;
        }
        return false;
    }
};