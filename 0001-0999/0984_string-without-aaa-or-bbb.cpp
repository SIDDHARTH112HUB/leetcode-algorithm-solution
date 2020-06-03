//Link: https://leetcode.com/problems/string-without-aaa-or-bbb/ 
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        if( A >= B )
            return helper(A, B, 'a', 'b');
        return helper(B, A, 'b', 'a');
    }
    
    string helper(int n1, int n2, char a, char b){
        string ans;
        while( n1 > n2 && n1 >= 2 && n2 > 0 ){
            ans += a;
            ans += a;
            n1 -= 2;
            ans += b;
            n2 -= 1;
        }
        while( n1 > 0 || n2 > 0 ){
            if( n1-- > 0 )
                ans += a;
            if( n2-- > 0)
                ans+=b;
        }
        return ans;
    }
};