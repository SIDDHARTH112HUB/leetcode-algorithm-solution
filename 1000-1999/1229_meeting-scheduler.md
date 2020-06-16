[1229.meeting-scheduler](https://leetcode.com/problems/meeting-scheduler/)  

Given the availability time slots arrays `slots1` and `slots2` of two people and a meeting duration `duration`, return the **earliest time slot** that works for both of them and is of duration `duration`.

If there is no common time slot that satisfies the requirements, return an **empty array**.

The format of a time slot is an array of two elements `[start, end]` representing an inclusive time range from `start` to `end`.  

It is guaranteed that no two availability slots of the same person intersect with each other. That is, for any two time slots `[start1, end1]` and `[start2, end2]` of the same person, either `start1 > end2` or `start2 > end1`.

**Example 1:**

  
**Input:** slots1 = \[\[10,50\],\[60,120\],\[140,210\]\], slots2 = \[\[0,15\],\[60,70\]\], duration = 8  
**Output:** \[60,68\]  

**Example 2:**

  
**Input:** slots1 = \[\[10,50\],\[60,120\],\[140,210\]\], slots2 = \[\[0,15\],\[60,70\]\], duration = 12  
**Output:** \[\]  

**Constraints:**

*   `1 <= slots1.length, slots2.length <= 10^4`
*   `slots1[i].length, slots2[i].length == 2`
*   `slots1[i][0] < slots1[i][1]`
*   `slots2[i][0] < slots2[i][1]`
*   `0 <= slots1[i][j], slots2[i][j] <= 10^9`
*   `1 <= duration <= 10^6`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int j = 0,i = 0;
        while(i < slots1.size() && j < slots2.size()){
            if(slots1[i][0] > slots2[j][1]) {
                ++j;
                continue;
            }
            if(slots2[j][0] > slots1[i][1]){
                ++i;
                continue;
            }
            int start = max(slots1[i][0], slots2[j][0]);
            int end = min(slots1[i][1], slots2[j][1]);
            if(end - start >= duration){
                return {start, start + duration};
            }
            if(slots1[i][1] > slots2[j][1])
                ++j;
            else
                ++i;
        }
        return {};
        /*
        int s1c=0, s2c = 0;
        int last = 0;
        map<int, int> m;
        for(auto &s : slots1) {
            m[s[0]] = 1;
            m[s[1]] = -1;
        }
        for(auto &s : slots2) {
            m[s[0]] = 2;
            m[s[1]] = -2;
        }
        int cnt = 0;
        for(auto it1 : m) {
            int t = it1.first;
            int v = it1.second;
            if(v < 0 && s1c >0 && s2c > 0) {
                if(duration <= t - last) {
                    return {last, duration};
                }
            }
            if(v == 1) {
                if(s1c == 0)
                    last = t;
                ++s1c;
            }
            else if(v == 2){
                if(s2c == 0)
                    last = t;
                ++s2c;
            }
            else if(v == -1) 
                --s1c;
            else if(v == -2)
                --s2c;
            
        }
        return {};*/
    }
};
```
      