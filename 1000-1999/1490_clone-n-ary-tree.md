[1490.clone-n-ary-tree](https://leetcode.com/problems/clone-n-ary-tree/)  

Given a `root` of an N-ary tree, return a [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) (clone) of the tree.

Each node in the n-ary tree contains a val (`int`) and a list (`List[Node]`) of its children.

  
class Node {  
    public int val;  
    public List<Node> children;  
}  

_Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples)._

**Follow up:** Can your solution work for the [graph problem](https://leetcode.com/problems/clone-graph/)?

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

  
**Input:** root = \[1,null,3,2,4,null,5,6\]  
**Output:** \[1,null,3,2,4,null,5,6\]  

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

  
**Input:** root = \[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14\]  
**Output:** \[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14\]  

**Constraints:**

*   The depth of the n-ary tree is less than or equal to `1000`.
*   The total number of nodes is between `[0, 10^4]`.  



**Solution:**  

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if(!root) return NULL;
        auto copy = new Node(root->val);
        for(auto node : root->children)
            copy->children.push_back(cloneTree(node));
        return copy;
    }
};
```
      