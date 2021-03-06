[707.design-linked-list](https://leetcode.com/problems/design-linked-list/)  

Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: `val` and `next`. `val` is the value of the current node, and `next` is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute `prev` to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

*   `get(index)` : Get the value of the `index`\-th node in the linked list. If the index is invalid, return `-1`.
*   `addAtHead(val)` : Add a node of value `val` before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
*   `addAtTail(val)` : Append a node of value `val` to the last element of the linked list.
*   `addAtIndex(index, val)` : Add a node of value `val` before the `index`\-th node in the linked list. If `index` equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
*   `deleteAtIndex(index)` : Delete the `index`\-th node in the linked list, if the index is valid.

**Example:**

  
**Input: **  
\["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"\]  
\[\[\],\[1\],\[3\],\[1,2\],\[1\],\[1\],\[1\]\]  
**Output: **   
\[null,null,null,null,2,null,3\]  
  
**Explanation:**  
MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList  
linkedList.addAtHead(1);  
linkedList.addAtTail(3);  
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3  
linkedList.get(1);            // returns 2  
linkedList.deleteAtIndex(1);  // now the linked list is 1->3  
linkedList.get(1);            // returns 3  

**Constraints:**

*   `0 <= index,val <= 1000`
*   Please do not use the built-in LinkedList library.
*   At most `2000` calls will be made to `get`, `addAtHead`, `addAtTail`,  `addAtIndex` and `deleteAtIndex`.  



**Solution:**  

```cpp
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct Node{
        
        Node* next;
        int val;
        Node(int val){this->val = val;this->next = NULL;}
    };
    Node* head;
    int count;
    MyLinkedList() {
        head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    
    Node* getNode(int index ){
        auto node = head;
        while(node && index-->0)
            node = node->next;
        return node;
    }
    int get(int index) {
        auto node = this->getNode(index);
        return node == NULL?-1:node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto node = new Node(val);
        node->next = this->head;
        this->head = node;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
        auto node = head;
        while(node && node->next)
            node = node->next;
        if( node ){
            node->next = new Node(val);
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if( index == 0 ){
            this->addAtHead(val);
            return;
        }
        auto node = this->getNode(index-1);
        
        if( node ){
            auto nn = new Node(val);
            nn->next = node->next;
            node->next = nn;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if( index == 0 ){
            if( !head ) return;
            auto tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        auto node =this->getNode(index-1);
        if( node){
         
            auto tmp = node->next;
            if( tmp ){
                node->next = tmp->next;
                delete tmp;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
```
      