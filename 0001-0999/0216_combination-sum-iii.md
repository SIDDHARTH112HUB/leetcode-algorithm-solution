[216.combination-sum-iii](https://leetcode.com/problems/combination-sum-iii/)  

Find all possible combinations of _**k**_ numbers that add up to a number _**n**_, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

**Note:**

*   All numbers will be positive integers.
*   The solution set must not contain duplicate combinations.

**Example 1:**

**Input:** _**k**_ = 3, _**n**_ = 7
**Output:** \[\[1,2,4\]\]

**Example 2:**

**Input:** _**k**_ = 3, _**n**_ = 9
**Output:** \[\[1,2,6\], \[1,3,5\], \[2,3,4\]\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> item;
        solve(k, n, 1, item);
        return ans;
    }
    
    void solve( int k , int n, int idx, vector<int> &item){
        if( n < 0 )
            return;
        if( k == 0 ){
            if( n == 0 )
                ans.push_back(item);
            return;
        }
        for( int i = idx; i<=9; i++){
            item.push_back(i);
            solve( k-1, n-i, i+1, item);
            item.pop_back();
        }
    }
};
```
      