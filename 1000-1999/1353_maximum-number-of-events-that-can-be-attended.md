[1353.maximum-number-of-events-that-can-be-attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)  

Given an array of `events` where `events[i] = [startDayi, endDayi]`. Every event `i` starts at `startDayi` and ends at `endDayi`.

You can attend an event `i` at any day `d` where `startTimei <= d <= endTimei`. Notice that you can only attend one event at any time `d`.

Return _the maximum number of events_ you can attend.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/02/05/e1.png)

**Input:** events = \[\[1,2\],\[2,3\],\[3,4\]\]
**Output:** 3
**Explanation:** You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.

**Example 2:**

**Input:** events= \[\[1,2\],\[2,3\],\[3,4\],\[1,2\]\]
**Output:** 4

**Example 3:**

**Input:** events = \[\[1,4\],\[4,4\],\[2,2\],\[3,4\],\[1,1\]\]
**Output:** 4

**Example 4:**

**Input:** events = \[\[1,100000\]\]
**Output:** 1

**Example 5:**

**Input:** events = \[\[1,1\],\[1,2\],\[1,3\],\[1,4\],\[1,5\],\[1,6\],\[1,7\]\]
**Output:** 7

**Constraints:**

*   `1 <= events.length <= 10^5`
*   `events[i].length == 2`
*   `1 <= events[i][0] <= events[i][1] <= 10^5`  



**Solution:**  

```cpp
struct BIT{
    vector<int> nums;
    BIT(){}
    void init(int size){
        nums.resize(size+1);
        for(int i = 1; i <= size; ++i) {
            update(i, 1);
        }
    }
    BIT(int size) : nums(size+1){}
    int lowbit(int x) { return x & -x; }
    void update(int x, int cnt){
        //x++;
        while (x < nums.size()) {
            nums[x] += cnt;
            x += lowbit(x);
        }
    }
    
    int query(int x) {
        if(x < 0) return 0;
        //++x;
        int sum = 0;
        while(x > 0) {
            sum += nums[x];
            x -= lowbit(x);
        }
        return sum;
    }
    
    int h(int l, int r) {
        while(l < r) {
            int mid = (l + r) / 2;
            int res = query(mid) - (l > 0 ? query(l-1) : 0);
            if(res > 0) {
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        int cnt = query(l) - (l > 0 ? query(l -1) : 0);
        return cnt > 0 ? l : -1;
    }
};
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        int ans = 0;
        BIT bit;
        bit.init(events.back()[1]);
        for(auto &e : events) {
            int l = e[0];
            int r = e[1];
            int idx = bit.h(l, r);
            if(idx > 0) {
                ++ans;
                bit.update(idx, -1);
            }
        }
        return ans;
    }
};
```
      