[866.prime-palindrome](https://leetcode.com/problems/prime-palindrome/)  

Find the smallest prime palindrome greater than or equal to `N`.

Recall that a number is _prime_ if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a _palindrome_ if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

**Example 1:**

  
**Input:** 6
  
**Output:** 7
  

**Example 2:**

  
**Input:** 8
  
**Output:** 11
  

**Example 3:**

  
**Input:** 13
  
**Output:** 101

**Note:**

*   `1 <= N <= 10^8`
*   The answer is guaranteed to exist and be less than `2 * 10^8`.  



**Solution:**  

```cpp
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
```
      