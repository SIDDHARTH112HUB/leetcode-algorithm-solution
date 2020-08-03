[1530.number-of-good-leaf-nodes-pairs](https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/)  

Given the `root` of a binary tree and an integer `distance`. A pair of two different **leaf** nodes of a binary tree is said to be good if the length of **the shortest path** between them is less than or equal to `distance`.

Return _the number of good leaf node pairs_ in the tree.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/07/09/e1.jpg)

  
**Input:** root = \[1,2,3,null,4\], distance = 3
  
**Output:** 1
  
**Explanation:** The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
  

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/07/09/e2.jpg)

  
**Input:** root = \[1,2,3,4,5,6,7\], distance = 3
  
**Output:** 2
  
**Explanation:** The good pairs are \[4,5\] and \[6,7\] with shortest path = 2. The pair \[4,6\] is not good because the length of ther shortest path between them is 4.
  

**Example 3:**

  
**Input:** root = \[7,1,4,6,null,5,3,null,null,null,null,null,2\], distance = 3
  
**Output:** 1
  
**Explanation:** The only good pair is \[2,5\].
  

**Example 4:**

  
**Input:** root = \[100\], distance = 1
  
**Output:** 0
  

**Example 5:**

  
**Input:** root = \[1,1,1\], distance = 2
  
**Output:** 1
  

**Constraints:**

*   The number of nodes in the `tree` is in the range `[1, 2^10].`
*   Each node's value is between `[1, 100]`.
*   `1 <= distance <= 10`  



**Solution:**  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    map<int, int> dfs(TreeNode* root, int d, int dist) {
        if(!root) return {};
        map<int, int> m;
        if(!root->left && !root->right) {
            ++m[d]; return m;
        }
        
        auto l = dfs(root->left, d + 1, dist);
        auto r = dfs(root->right, d + 1, dist);
        for(auto &lit : l) {
            
            int dl = lit.first - d;
            for(auto &rit : r){
                int dr = rit.first - d;
                if((dl + dr) <= dist) {
                    ans += lit.second * rit.second;
                }
            }
        }
        for(auto &rit : r) {
            l[rit.first] += rit.second;
        }
        return l;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, 0, distance);
        return ans;
    }
};
```
      