[313.super-ugly-number](https://leetcode.com/problems/super-ugly-number/)  

Write a program to find the `nth` super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list `primes` of size `k`.

**Example:**

  
**Input:** n = 12, `primes` = `[2,7,13,19]`
  
**Output:** 32 
  
**Explanation:** `[1,2,4,7,8,13,14,16,19,26,28,32]` is the sequence of the first 12 
  
             super ugly numbers given `primes` = `[2,7,13,19]` of size 4.

**Note:**

*   `1` is a super ugly number for any given `primes`.
*   The given numbers in `primes` are in ascending order.
*   0 < `k` ≤ 100, 0 < `n` ≤ 106, 0 < `primes[i]` < 1000.
*   The nth super ugly number is guaranteed to fit in a 32-bit signed integer.  



**Solution:**  

```cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        if( n <= 1 ) return n;
        int dp[n+1] = {0};
        vector<int> vidx(primes.size());
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
        
        for( int i = 0; i<primes.size(); i++){
            pq.push({primes[i], i});
        }
        dp[0] = 1;
        for( int i = 1; i<n; i++){
            pair<int, int> p = pq.top();
            dp[i] = p.first;
            int next;
            //cout<<dp[i]<<endl;
            do{
                p = pq.top();
                pq.pop();
                int &idx = vidx[p.second];
                idx++;
                if( pq.size() > 0 )
                    next = pq.top().first;
                pq.push({dp[idx]*primes[p.second],p.second});
                if(pq.size() == 1 )
                    break;
            }while(p.first == next);
        }
        return dp[n-1];
    }
};
```
      