[275.h-index-ii](https://leetcode.com/problems/h-index-ii/)  

Given an array of citations **sorted in ascending order** (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the [definition of h-index on Wikipedia](https://en.wikipedia.org/wiki/H-index): "A scientist has index _h_ if _h_ of his/her _N_ papers have **at least** _h_ citations each, and the other _N − h_ papers have **no more than** _h_ citations each."

**Example:**

  
**Input:** `citations = [0,1,3,5,6]`
  
**Output:** 3 
  
**Explanation:** `[0,1,3,5,6]` means the researcher has `5` papers in total and each of them had 
  
             received 0`, 1, 3, 5, 6` citations respectively. 
  
             Since the researcher has `3` papers with **at least** `3` citations each and the remaining 
  
             two with **no more than** `3` citations each, her h-index is `3`.

**Note:**

If there are several possible values for _h_, the maximum one is taken as the h-index.

**Follow up:**

*   This is a follow up problem to [H-Index](/problems/h-index/description/), where `citations` is now guaranteed to be sorted in ascending order.
*   Could you solve it in logarithmic time complexity?  



**Solution:**  

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        int l = 0, r = citations.back()+1;
        int ans = 0;
        while(l < r) {
            int mid = (l+r) / 2;
            int h = citations.end() - lower_bound(citations.begin(), citations.end(), mid);
            if(h >= mid) {
                l = mid + 1;   
                ans = max(ans, mid);
            }else
                r = mid;
        }
        return ans;
    }
};
```
      