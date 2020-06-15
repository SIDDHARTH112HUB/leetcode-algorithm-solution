[1012.numbers-with-repeated-digits](https://leetcode.com/problems/numbers-with-repeated-digits/)  

Given a positive integer `N`, return the number of positive integers less than or equal to `N` that have at least 1 repeated digit.

**Example 1:**

**Input:** 20
**Output:** 1
**Explanation:** The only positive number (<= 20) with at least 1 repeated digit is 11.

**Example 2:**

**Input:** 100
**Output:** 10
**Explanation:** The positive numbers (<= 100) with atleast 1 repeated digit are 11, 22, 33, 44, 55, 66, 77, 88, 99, and 100.

**Example 3:**

**Input:** 1000
**Output:** 262

**Note:**

1.  `1 <= N <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        int src = N;
        ++N;
        vector<int> nums;
        while(N > 0){
            nums.push_back(N%10);
            N /= 10;
        }
        reverse(nums.begin(), nums.end());
        int res = 0;
        for(int i = 1; i < nums.size(); i++){
            res += 9 * helper(9, i - 1);
        }
        set<int> seen;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i > 0 ? 0 : 1; j < nums[i]; ++j){
                if(!seen.count(j))
                    res += helper(9 - i, nums.size() - i - 1);
            }
            int n = nums[i];
            if(seen.count(n)) break;
            seen.insert(n);
        }
        return src - res;
    }
    
    int helper(int m, int n) {
        return n == 0 ? 1 : helper(m, n-1) * (m - n + 1);
    }
};
```
      