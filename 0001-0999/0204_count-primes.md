[204.count-primes](https://leetcode.com/problems/count-primes/)  

Count the number of prime numbers less than a non-negative number, **_n_**.

**Example:**

**Input:** 10
**Output:** 4
**Explanation:** There are 4 prime numbers less than 10, they are 2, 3, 5, 7.  



**Solution:**  

```cpp
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> vec(n+1, true);
        int ans = 0;
        for(int i = 2; i<n ; i++){
            if( vec[i] == false)
                continue;
            ans++;
            for(int j = i*i; j<=n;j+=i){
                vec[j] = false;
            }
        }
        return ans;
    }
};
```
      