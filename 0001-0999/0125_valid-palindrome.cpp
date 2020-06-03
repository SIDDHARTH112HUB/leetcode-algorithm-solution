//Link: https://leetcode.com/problems/valid-palindrome/ 
class Solution {
public:
    bool isAlphanumeric(char &c)
    {
        if( c<'0' || (c>'9' && c<'A') || (c>'Z' && c<'a') || c>'z')
            return false;
        if ( c>='a') c -=('a' - 'A');
        return true;
    }
    bool isPalindrome(string s) {
        int right_idx = s.length()-1;
        for(int i=0;i<s.length();i++)
        {
            char c = s.at(i);
            if( isAlphanumeric(c) == false ) continue;
            
            char rc;
            do
            {
                rc = s.at(right_idx--);
            }while( isAlphanumeric(rc) == false );
            
            if( c != rc ) return false;
        }
        return true;
    }
};