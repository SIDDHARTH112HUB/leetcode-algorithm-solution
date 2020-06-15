[428.serialize-and-deserialize-n-ary-tree](https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/)  

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following `3-ary` tree

![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

as `[1 [3[5 6] 2 4]]`. Note that this is just an example, you do not necessarily need to follow this format.

Or you can follow LeetCode's level order traversal serialization format, where each group of children is separated by the null value.

![](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

For example, the above tree may be serialized as `[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]`.

You do not necessarily need to follow the above suggested formats, there are many more different formats that work so please be creative and come up with different approaches yourself.

**Constraints:**

*   The height of the n-ary tree is less than or equal to `1000`
*   The total number of nodes is between `[0, 10^4]`
*   Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.  



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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(!root) return "";
        string ans = to_string(root->val);
        for(int i = 0; i < root->children.size(); ++i) {
            ans += "(" + serialize(root->children[i]) + ")";
        }
        return ans;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int idx = 0;
        return dfs(data, idx);
    }
    
    
    Node* dfs(string &data, int &idx) {
        int sum = 0;
        Node* node = NULL;
        int sign = 1;
        while(idx < data.size()) {
            int c = data[idx];
            if(c <= '9' && c >= '0' ) {
                ++idx;
                sum = sum * 10 + c - '0';
                node = new Node(0);
            }
            else if(c == '(') {
                ++idx;
                auto child = dfs(data, idx);
                if(child) node->children.push_back(child);
            } else if(c == ')') {
                ++idx;
                break;
            } else {
                ++idx;
                sign = -1;
            }
            
        }
        if(node) node->val = sum*sign;
        return node;    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
```
      