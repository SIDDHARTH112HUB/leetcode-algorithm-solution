[987.vertical-order-traversal-of-a-binary-tree](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)  

Given a binary tree, return the _vertical order_ traversal of its nodes values.

For each node at position `(X, Y)`, its left and right children respectively will be at positions `(X-1, Y-1)` and `(X+1, Y-1)`.

Running a vertical line from `X = -infinity` to `X = +infinity`, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing `Y` coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of `X` coordinate.  Every report will have a list of values of nodes.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/01/31/1236_example_1.PNG)

**Input:** \[3,9,20,null,null,15,7\]
**Output:** \[\[9\],\[3,15\],\[20\],\[7\]\]
**Explanation:** 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/01/31/tree2.png)**

**Input:** \[1,2,3,4,5,6,7\]
**Output:** \[\[4\],\[2\],\[1,5,6\],\[3\],\[7\]\]
**Explanation:** 
The node with value 5 and the node with value 6 have the same position according to the given scheme.
However, in the report "\[1,5,6\]", the node value of 5 comes first since 5 is smaller than 6.

**Note:**

1.  The tree will have between 1 and `1000` nodes.
2.  Each node's value will be between `0` and `1000`.  



**Solution:**  

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var m = {}
var verticalTraversal = function(root) {
    if( !root ) return [];
    m = {};
    solve(root, 1000, 1);
    var ans = [];
    for( var idx in m){
        ans.push([]);
        for( var height in m[idx]){
            m[idx][height].sort((a,b)=>a-b);
            m[idx][height].forEach(n=>ans[ans.length-1].push(n));
        }
    }
    return ans;
};

var solve = function(node, idx, height){
    if( !node ) return;
    if( !m[idx] )
        m[idx] = {}
    if( !m[idx][height])
        m[idx][height] = [];
    m[idx][height].push(node.val);
    solve(node.left, idx-1, height+1);
    solve(node.right, idx+1, height+1);
}
```
      