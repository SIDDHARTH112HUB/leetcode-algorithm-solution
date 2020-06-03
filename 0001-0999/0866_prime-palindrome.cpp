//Link: https://leetcode.com/problems/prime-palindrome/ 
class Solution {
public:
    bool isPrime(int n){
        int sqrtn = sqrt(n)+1;
        if( n %2 == 0 )return false;
        for( int i = 3; i<=sqrtn; i+=2){
            if( n % i == 0 )
                return false;
        }
        return true;
    }
    bool isPalindrome(int n, int &dup){
        
        if( n >= 0 && n<10 )
            return n == dup %10;
        if( !isPalindrome(n/10, dup))
            return false;
        dup /= 10;
        return n % 10 == dup %10;
    }
    int primePalindrome(int N) {
        if( N <=2 ) return 2;
        if( N <=3 ) return 3;
        if( N >= 10000000 ) return 100030001;
        N = abs(N);
        while(true){
            int dup = N;
            if( isPalindrome(N, dup) ){
                if( isPrime(N) )
                    return N;
            }
            ++N;
        }
        return 0;
    }
};