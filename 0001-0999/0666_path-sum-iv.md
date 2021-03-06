[666.path-sum-iv](https://leetcode.com/problems/path-sum-iv/)  

If the depth of a tree is smaller than `5`, then this tree can be represented by a list of three-digits integers.

For each integer in this list:

1.  The hundreds digit represents the depth `D` of this node, `1 <= D <= 4.`
2.  The tens digit represents the position `P` of this node in the level it belongs to, `1 <= P <= 8`. The position is the same as that in a full binary tree.
3.  The units digit represents the value `V` of this node, `0 <= V <= 9.`

Given a list of `ascending` three-digits integers representing a binary tree with the depth smaller than 5, you need to return the sum of all paths from the root towards the leaves.

It's guaranteed that the given list represents a valid connected binary tree.

**Example 1:**

  
**Input:** \[113, 215, 221\]  
**Output:** 12  
**Explanation:**   
The tree that the list represents is:  
    3  
   / \\  
  5   1  
  
The path sum is (3 + 5) + (3 + 1) = 12.  

**Example 2:**

  
**Input:** \[113, 221\]  
**Output:** 4  
**Explanation:**   
The tree that the list represents is:   
    3  
     \\  
      1  
  
The path sum is (3 + 1) = 4.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, int> m;
    int ans = 0;
    int pathSum(vector<int>& nums) {
        for(auto n : nums)
            m[n/10] = n % 10;
        dfs(nums[0] / 10, 0);
        return ans;
    }
    
    void dfs(int num, int cur) {
        if(!m.count(num)) return;
        int level = num / 10, pos = num % 10;
        int left = (level + 1) * 10 + 2 * pos - 1;
        int right = left + 1;
        cur += m[num];
        if(!m.count(left) && !m.count(right)) {
            ans += cur;
            return;
        }
        dfs(left, cur);
        dfs(right ,cur);
    }
};
```
      