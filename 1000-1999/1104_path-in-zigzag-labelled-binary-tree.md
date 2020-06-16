[1104.path-in-zigzag-labelled-binary-tree](https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/)  

In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.

![](https://assets.leetcode.com/uploads/2019/06/24/tree.png)

Given the `label` of a node in this tree, return the labels in the path from the root of the tree to the node with that `label`.

**Example 1:**

  
**Input:** label = 14  
**Output:** \[1,3,4,14\]  

**Example 2:**

  
**Input:** label = 26  
**Output:** \[1,2,6,10,26\]  

**Constraints:**

*   `1 <= label <= 10^6`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        while(label>0){
            ans.push_back(label);
            label /= 2;
            if(label == 0)
                break;
            int p = 0;
            while(pow(2, p) <= label)++p;
            label = pow(2, p ) -1 - (label- pow(2, p-1));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      