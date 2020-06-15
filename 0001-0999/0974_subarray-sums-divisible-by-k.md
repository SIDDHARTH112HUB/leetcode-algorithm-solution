[974.subarray-sums-divisible-by-k](https://leetcode.com/problems/subarray-sums-divisible-by-k/)  

Given an array `A` of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by `K`.

**Example 1:**

**Input:** A = \[4,5,0,-2,-3,1\], K = 5
**Output:** 7
**Explanation:** There are 7 subarrays with a sum divisible by K = 5:
\[4, 5, 0, -2, -3, 1\], \[5\], \[5, 0\], \[5, 0, -2, -3\], \[0\], \[0, -2, -3\], \[-2, -3\]

**Note:**

1.  `1 <= A.length <= 30000`
2.  `-10000 <= A[i] <= 10000`
3.  `2 <= K <= 10000`  



**Solution:**  

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> m;
        int sum = 0;
        int ans = 0;
        m[0] = 1;
        
        cout<<"Begin"<<endl;
        for( int a : A){
            sum = (sum + a%K +K) % K;
            
            /*if( sum % K == 0 ){
                ans++;
            }*/
            //ans += m[K - sum % K ];
            //ans += m[-(K-(sum % K) )];
            ans += m[sum ];
            ++m[sum];
            /*
            if( m[sum%K] == 0 )
                m[sum%K] = 1;
            else
                m[sum%K]+=m[sum%K];*/
        }
        return ans;
    }
};


```
      