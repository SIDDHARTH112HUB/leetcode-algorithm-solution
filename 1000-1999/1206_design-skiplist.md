[1206.design-skiplist](https://leetcode.com/problems/design-skiplist/)  

Design a Skiplist without using any built-in libraries.

_A Skiplist is a data structure that takes O(log(n)) time to `add`, `erase` and `search`. Comparing with treap and red-black tree which has the same function and performance, the code length of Skiplist can be comparatively short and the idea behind Skiplists are just simple linked lists._

_For example: we have a Skiplist containing `[30,40,50,60,70,90]` and we want to add `80` and `45` into it. The Skiplist works this way:_

![](https://assets.leetcode.com/uploads/2019/09/27/1506_skiplist.gif)  
Artyom Kalinin \[CC BY-SA 3.0\], via [Wikimedia Commons](https://commons.wikimedia.org/wiki/File:Skip_list_add_element-en.gif "Artyom Kalinin [CC BY-SA 3.0 (https://creativecommons.org/licenses/by-sa/3.0)], via Wikimedia Commons")

_You can see there are many layers in the Skiplist. Each layer is a sorted linked list. With the help of the top layers, `add` , `erase` and `search` can be faster than O(n). It can be proven that the average time complexity for each operation is O(log(n)) and space complexity is O(n)._

To be specific, your design should include these functions:

*   `bool search(int target)` : Return whether the `target` exists in the Skiplist or not.
*   `void add(int num)`: Insert a value into the SkipList. 
*   `bool erase(int num)`: Remove a value in the Skiplist. If `num` does not exist in the Skiplist, do nothing and return false. If there exists multiple `num` values, removing any one of them is fine.

See more about Skiplist : [https://en.wikipedia.org/wiki/Skip\_list](https://en.wikipedia.org/wiki/Skip_list)

Note that duplicates may exist in the Skiplist, your code needs to handle this situation.

**Example:**

Skiplist skiplist = new Skiplist();

skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0);   // return false.
skiplist.add(4);
skiplist.search(1);   // return true.
skiplist.erase(0);    // return false, 0 is not in skiplist.
skiplist.erase(1);    // return true.
skiplist.search(1);   // return false, 1 has already been erased.

**Constraints:**

*   `0 <= num, target <= 20000`
*   At most `50000` calls will be made to `search`, `add`, and `erase`.  



**Solution:**  

```cpp
struct Node{
    Node *right;
    Node *down;
    int val;
    Node(int num = INT_MIN) {
        right = nullptr;
        down = nullptr;
        val = num;
    }
};
class Skiplist {
public:
    Node* head;
    Skiplist() {
        head = new Node();
    }
    
    bool search(int target) {
        auto node = head;
        while(node) {
            while(node->right && node->right->val < target)
                node = node->right;
            if(node->right && node->right->val == target) return true;
            node = node->down;
        }
        return false;
    }
    
    Node* help(int num, Node* prev) {
        while(prev->right && prev->right->val < num) 
            prev = prev->right;
        auto right = prev->right;
        if(prev->down) {
            auto newDownNode = help(num, prev->down);
            if(newDownNode) {
                prev->right = new Node(num);
                prev->right->down = newDownNode;
                prev->right->right = right;
                return rand() % 2 ? prev->right :NULL;
            }
            return NULL;
        }else {
            prev->right = new Node(num);
            prev->right->right = right;
            return rand() % 2 ? prev->right: NULL;
        }
    }
    void add(int num) {
        auto newDownNode = help(num, head);
        if(newDownNode) {
            auto newHead = new Node();
            newHead->right = new Node(newDownNode->val);
            newHead->down = head;
            newHead->right->down = newDownNode;
            head = newHead;
        }
    }
    
    bool erase(int num) {
        auto node = head;
        while(node) {
            while(node->right && node->right->val < num)
                node = node->right;
            if(node->right && node->right->val == num) break;
            node = node->down;
        }
        if(!node) return false;
        auto deleteNode = node->right;
        while(deleteNode) {
            node->right = deleteNode->right;
            auto nextDown = deleteNode->down;
            node = node->down;
            while(node && node->right != nextDown)
                node = node->right;
            delete deleteNode;
            deleteNode = nextDown;
        }
        return true;
        
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
```
      