[1361.validate-binary-tree-nodes](https://leetcode.com/problems/validate-binary-tree-nodes/)  

You have `n` binary tree nodes numbered from `0` to `n - 1` where node `i` has two children `leftChild[i]` and `rightChild[i]`, return `true` if and only if **all** the given nodes form **exactly one** valid binary tree.

If node `i` has no left child then `leftChild[i]` will equal `-1`, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/08/23/1503_ex1.png)**

  
**Input:** n = 4, leftChild = \[1,-1,3,-1\], rightChild = \[2,-1,-1,-1\]  
**Output:** true  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/08/23/1503_ex2.png)**

  
**Input:** n = 4, leftChild = \[1,-1,3,-1\], rightChild = \[2,3,-1,-1\]  
**Output:** false  

**Example 3:**

**![](https://assets.leetcode.com/uploads/2019/08/23/1503_ex3.png)**

  
**Input:** n = 2, leftChild = \[1,0\], rightChild = \[-1,-1\]  
**Output:** false  

**Example 4:**

**![](https://assets.leetcode.com/uploads/2019/08/23/1503_ex4.png)**

  
**Input:** n = 6, leftChild = \[1,-1,-1,4,-1,-1\], rightChild = \[2,-1,-1,5,-1,-1\]  
**Output:** false  

**Constraints:**

*   `1 <= n <= 10^4`
*   `leftChild.length == rightChild.length == n`
*   `-1 <= leftChild[i], rightChild[i] <= n - 1`  



**Solution:**  

```cpp
class Solution {
public:
    map<int, set<int> > m;
    map<int, int> p;
    set<int> v;
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i = 0; i < leftChild.size(); ++i) {
            if(leftChild[i] == rightChild[i] && leftChild[i] >= 0)
                return false;
            if(leftChild[i] >= 0) {
                m[i].insert(leftChild[i]);
                p[leftChild[i]] = i;
            }
            if(rightChild[i] >= 0) {
                m[i].insert(rightChild[i]);
                p[rightChild[i]] = i;
            }
        }
        int root = -1;
        for(int i = 0; i < n; ++i) {
            if(p.count(i) == 0) {
                if(root != -1 ) return false;
                root = i;
            }
        }
        if(!dfs(root)) return false;
        return v.size() == n;
    }
    
    bool dfs(int root) {
        if(v.count(root)) return false;
        v.insert(root);
        for(auto next : m[root]) {
            if(!dfs(next)) return false;
        }
        return true;
    }
};
```
      