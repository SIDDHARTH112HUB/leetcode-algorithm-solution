[528.random-pick-with-weight](https://leetcode.com/problems/random-pick-with-weight/)  

Given an array `w` of positive integers, where `w[i]` describes the weight of index `i`(0-indexed), write a function `pickIndex` which randomly picks an index in proportion to its weight.

_For example, given an input list of values \[1, 9\], when we pick up a number out of it, the chance is that 9 times out of 10 we should pick the number 9 as the answer._

**Example 1:**

**Input**
\["Solution","pickIndex"\]
\[\[\[1\]\],\[\]\]
**Output**
\[null,0\]

**Explanation**
Solution solution = new Solution(\[1\]);
solution.pickIndex(); // return 0. Since there is only one single element on the array the only option is to return the first element.

**Example 2:**

**Input**
\["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"\]
\[\[\[1,3\]\],\[\],\[\],\[\],\[\],\[\]\]
**Output**
\[null,1,1,1,1,0\]

**Explanation**
Solution solution = new Solution(\[1, 3\]);
solution.pickIndex(); // return 1. It's returning the second element (index = 1) that has probability of 3/4.
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 0. It's returning the first element (index = 0) that has probability of 1/4.

**Constraints:**

*   `1 <= w.length <= 10000`
*   `1 <= w[i] <= 10^5`
*   `pickIndex` will be called at most `10000` times.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> ww;
    Solution(vector<int>& w) {
        for(int i = 1; i < w.size(); ++i) {
            w[i] += w[i-1];
        }
        ww = w;
    }
    
    int pickIndex() {
        int n = rand() % ww.back();
        return upper_bound(ww.begin(), ww.end(), n) - ww.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
```
      