//Link: https://leetcode.com/problems/implement-queue-using-stacks/ 
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