[427.construct-quad-tree](https://leetcode.com/problems/construct-quad-tree/)  

Given a `n * n` matrix `grid` of `0's` and `1's` only. We want to represent the `grid` with a Quad-Tree.

Return _the root of the Quad-Tree_ representing the `grid`.

Notice that you can assign the value of a node to **True** or **False** when `isLeaf` is **False**, and both are **accepted** in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

*   `val`: True if the node represents a grid of 1's or False if the node represents a grid of 0's. 
*   `isLeaf`: True if the node is leaf node on the tree or False if the node has the four children.

  
class Node {
  
    public boolean val;
  
    public boolean isLeaf;
  
    public Node topLeft;
  
    public Node topRight;
  
    public Node bottomLeft;
  
    public Node bottomRight;
  
}

We can construct a Quad-Tree from a two-dimensional area using the following steps:

1.  If the current grid has the same value (i.e all `1's` or all `0's`) set `isLeaf` True and set `val` to the value of the grid and set the four children to Null and stop.
2.  If the current grid has different values, set `isLeaf` to False and set `val` to any value and divide the current grid into four sub-grids as shown in the photo.
3.  Recurse for each of the children with the proper sub-grid.

![](https://assets.leetcode.com/uploads/2020/02/11/new_top.png)

If you want to know more about the Quad-Tree, you can refer to the [wiki](https://en.wikipedia.org/wiki/Quadtree).

**Quad-Tree format:**

The output represents the serialized format of a Quad-Tree using level order traversal, where `null` signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list `[isLeaf, val]`.

If the value of `isLeaf` or `val` is True we represent it as **1** in the list `[isLeaf, val]` and if the value of `isLeaf` or `val` is False we represent it as **0**.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/02/11/grid1.png)

  
**Input:** grid = \[\[0,1\],\[1,0\]\]  
**Output:** \[\[0,1\],\[1,0\],\[1,1\],\[1,1\],\[1,0\]\]  
**Explanation:** The explanation of this example is shown below:  
Notice that 0 represnts False and 1 represents True in the photo representing the Quad-Tree.  
![](https://assets.leetcode.com/uploads/2020/02/12/e1tree.png)  

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/02/12/e2mat.png)

  
**Input:** grid = \[\[1,1,1,1,0,0,0,0\],\[1,1,1,1,0,0,0,0\],\[1,1,1,1,1,1,1,1\],\[1,1,1,1,1,1,1,1\],\[1,1,1,1,0,0,0,0\],\[1,1,1,1,0,0,0,0\],\[1,1,1,1,0,0,0,0\],\[1,1,1,1,0,0,0,0\]\]  
**Output:** \[\[0,1\],\[1,1\],\[0,1\],\[1,1\],\[1,0\],null,null,null,null,\[1,0\],\[1,0\],\[1,1\],\[1,1\]\]  
**Explanation:** All values in the grid are not the same. We divide the grid into four sub-grids.  
The topLeft, bottomLeft and bottomRight each has the same value.  
The topRight have different values so we divide it into 4 sub-grids where each has the same value.  
Explanation is shown in the photo below:  
![](https://assets.leetcode.com/uploads/2020/02/12/e2tree.png)  

**Example 3:**

  
**Input:** grid = \[\[1,1\],\[1,1\]\]  
**Output:** \[\[1,1\]\]  

**Example 4:**

  
**Input:** grid = \[\[0\]\]  
**Output:** \[\[1,0\]\]  

**Example 5:**

  
**Input:** grid = \[\[1,1,0,0\],\[1,1,0,0\],\[0,0,1,1\],\[0,0,1,1\]\]  
**Output:** \[\[0,1\],\[1,1\],\[1,0\],\[1,0\],\[1,1\]\]  

**Constraints:**

*   `n == grid.length == grid[i].length`
*   `n == 2^x` where `0 <= x <= 6`  



**Solution:**  

```cpp
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
       /* for(int i = 0; i < grid.size(); ++i){
            int sum = 0;
            for(int j = 0; j < grid[0].size(); ++j) {
                int t = grid[i][j];
                grid[i][j] += sum + (i > 0 ? grid[i-1][j] : 0);
                sum += t;
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return h(grid, 0, 0, grid.size()-1, grid[0].size()-1);
    }
    
    Node *h(vector<vector<int>>& grid, int t, int l, int b, int r) {
        if(t > b || l > r) return NULL;
       // cout<<t<<" "<<l<<" "<<b<<" "<<r<<endl;
        int p = (b - t + 1) * (r-l+1);
        int sum = grid[b][r] + ((t > 0 && l > 0) ? grid[t-1][l-1] :0) - (t > 0 ? grid[t-1][r]: 0) - (l > 0 ? grid[b][l-1]: 0);
        bool isLeaf = true;
        for(int i = t; i <=b; ++i) {
            for(int j = l; j <=r; ++j) {
                if(grid[i][j]!= grid[b][r]){
                    isLeaf = false;
                    break;
                }
            }
            if(!isLeaf) break;
        }
        if(isLeaf == true) return new Node(grid[b][r], true, NULL, NULL, NULL, NULL);
        
        int ht = (b + t) / 2, hr = (l + r) / 2;
        auto node = new Node(0, false,
                             h(grid, t, l, ht, hr),
                             h(grid, t, hr+1, ht, r),
                             h(grid, ht+1, l, b, hr),
                             h(grid, ht+1, hr+1, b, r));
        return node;
    }
};
```
      