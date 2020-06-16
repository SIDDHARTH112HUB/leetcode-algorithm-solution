[1383.maximum-performance-of-a-team](https://leetcode.com/problems/maximum-performance-of-a-team/)  

There are `n` engineers numbered from 1 to `n` and two arrays: `speed` and `efficiency`, where `speed[i]` and `efficiency[i]` represent the speed and efficiency for the i-th engineer respectively. _Return the maximum **performance** of a team composed of at most `k` engineers, since the answer can be a huge number, return this modulo 10^9 + 7._

The **performance** of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers. 

**Example 1:**

  
**Input:** n = 6, speed = \[2,10,3,1,5,8\], efficiency = \[5,4,3,9,7,2\], k = 2
  
**Output:** 60
  
**Explanation:** 
  
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) \* min(4, 7) = 60.
  

**Example 2:**

  
**Input:** n = 6, speed = \[2,10,3,1,5,8\], efficiency = \[5,4,3,9,7,2\], k = 3
  
**Output:** 68
  
**Explanation:** This is the same example as the first but k = 3. We can select engineer 1, engineer 2 and engineer 5 to get the maximum performance of the team. That is, performance = (2 + 10 + 5) \* min(5, 4, 7) = 68.
  

**Example 3:**

  
**Input:** n = 6, speed = \[2,10,3,1,5,8\], efficiency = \[5,4,3,9,7,2\], k = 4
  
**Output:** 72
  

**Constraints:**

*   `1 <= n <= 10^5`
*   `speed.length == n`
*   `efficiency.length == n`
*   `1 <= speed[i] <= 10^5`
*   `1 <= efficiency[i] <= 10^8`
*   `1 <= k <= n`  



**Solution:**  

```cpp
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<long long, long long> > arr;
        long long ans = 0, sumS = 0;
        for(int i = 0; i < speed.size(); ++i) {
            ans = max(ans, (long long)speed[i] * (long long)eff[i]);
            arr.push_back({eff[i], speed[i]});
        }
        //cout<<"begin"<<endl;
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        
        priority_queue<long long, vector<long long >, greater<long long > > pq;
        for(int i = 0; i < arr.size(); ++i) {
            long long sig = arr[i].second * arr[i].first;
            sumS += arr[i].second;
            pq.push(arr[i].second);
            if(pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            ans = max(ans, sumS * arr[i].first);
        }
        ans = ans % (1000000007);
        return ans;
    }
};
```
      