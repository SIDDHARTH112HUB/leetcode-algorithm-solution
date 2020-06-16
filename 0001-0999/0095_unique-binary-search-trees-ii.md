[95.unique-binary-search-trees-ii](https://leetcode.com/problems/unique-binary-search-trees-ii/)  

Given an integer `n`, generate all structurally unique **BST's** (binary search trees) that store values 1 ... _n_.

**Example:**

  
**Input:** 3  
**Output:**  
\[  
  \[1,null,3,2\],  
  \[3,2,null,1\],  
  \[3,1,null,null,2\],  
  \[2,1,3\],  
  \[1,null,2,null,3\]  
\]  
**Explanation:**  
The above output corresponds to the 5 unique BST's shown below:  
  
   1         3     3      2      1  
    \\       /     /      / \\      \\  
     3     2     1      1   3      2  
    /     /       \\                 \\  
   2     1         2                 3  

**Constraints:**

*   `0 <= n <= 8`  



**Solution:**  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int, map<int, vector<TreeNode*> > > dp;
    vector<TreeNode*> generateTrees(int n) {
        if( n == 0 )return {};
        return solve(1, n);
    }
    
    vector<TreeNode*> solve(int min, int max){
        if( min > max ) return {nullptr};
        if( min == max) return {new TreeNode(min)};
        auto min_it = dp.find(min);
        if( min_it != dp.end()){
            auto max_it = min_it->second.find(max);
            if( max_it != min_it->second.end() )
                return max_it->second;
        }
        vector<TreeNode*> vec;
        for( int i = min; i<=max; i++ ){
            vector<TreeNode*> lvec = solve(min, i-1);
            vector<TreeNode*> rvec = solve(i+1, max);
            for( auto &left:lvec){
                for( auto &right:rvec){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    vec.push_back(root);
                }
            }
        }
        dp[min][max] = vec;
        return vec;
    }
};
```
      