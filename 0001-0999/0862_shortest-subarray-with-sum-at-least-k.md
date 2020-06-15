[862.shortest-subarray-with-sum-at-least-k](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)  

Return the **length** of the shortest, non-empty, contiguous subarray of `A` with sum at least `K`.

If there is no non-empty subarray with sum at least `K`, return `-1`.

**Example 1:**

**Input:** A = \[1\], K = 1
**Output:** 1

**Example 2:**

**Input:** A = \[1,2\], K = 4
**Output:** \-1

**Example 3:**

**Input:** A = \[2,-1,2\], K = 3
**Output:** 3

**Note:**

1.  `1 <= A.length <= 50000`
2.  `-10 ^ 5 <= A[i] <= 10 ^ 5`
3.  `1 <= K <= 10 ^ 9`  



**Solution:**  

```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > pq;
        int sum = 0;
        int ans = INT_MAX;
        for( int i = 0; i<A.size(); i++){
            sum += A[i];
            if( sum >= K ){
                ans = min(ans, i+1);
            }
            while( pq.size() && sum - pq.top().first >= K ){
                auto &p = pq.top();
                ans = min(ans, i-p.second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans == INT_MAX?-1:ans;
    }
};
```
      