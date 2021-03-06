[1010.pairs-of-songs-with-total-durations-divisible-by-60](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/)  

In a list of songs, the `i`\-th song has a duration of `time[i]` seconds. 

Return the number of pairs of songs for which their total duration in seconds is divisible by `60`.  Formally, we want the number of indices `i`, `j` such that `i < j` with `(time[i] + time[j]) % 60 == 0`.

**Example 1:**

  
**Input:** \[30,20,150,100,40\]  
**Output:** 3  
**Explanation:** Three pairs have a total duration divisible by 60:  
(time\[0\] = 30, time\[2\] = 150): total duration 180  
(time\[1\] = 20, time\[3\] = 100): total duration 120  
(time\[1\] = 20, time\[4\] = 40): total duration 60  

**Example 2:**

  
**Input:** \[60,60,60\]  
**Output:** 3  
**Explanation:** All three pairs have a total duration of 120, which is divisible by 60.  

**Note:**

*   `1 <= time.length <= 60000`
*   `1 <= time[i] <= 500`  



**Solution:**  

```cpp
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        for(int t : time)
            ++cnt[t%60];
        int ans = 0;
        for(int i = 0; i <=30; ++i){
            if(i % 30 == 0) {
                ans += cnt[i] * (cnt[i] - 1) / 2;
            }else{
                ans += cnt[i] * (cnt[60 - i]);
            }
        }
        return ans;
    }
};
```
      