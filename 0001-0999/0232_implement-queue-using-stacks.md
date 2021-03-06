[232.implement-queue-using-stacks](https://leetcode.com/problems/implement-queue-using-stacks/)  

Implement the following operations of a queue using stacks.

*   push(x) -- Push element x to the back of queue.
*   pop() -- Removes the element from in front of queue.
*   peek() -- Get the front element.
*   empty() -- Return whether the queue is empty.

**Example:**

  
MyQueue queue = new MyQueue();
  

  
queue.push(1);
  
queue.push(2);  
  
queue.peek();  // returns 1
  
queue.pop();   // returns 1
  
queue.empty(); // returns false

**Notes:**

*   You must use _only_ standard operations of a stack -- which means only `push to top`, `peek/pop from top`, `size`, and `is empty` operations are valid.
*   Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
*   You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).  



**Solution:**  

```cpp
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    stack<int> s1;
    stack<int> s2;
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int src = peek();
        s2.pop();
        return src;
    }
    
    /** Get the front element. */
    int peek() {
        if(s2.size() > 0)
            return s2.top();
        while(s1.size() > 0){
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return !(s1.size() || s2.size());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```
      