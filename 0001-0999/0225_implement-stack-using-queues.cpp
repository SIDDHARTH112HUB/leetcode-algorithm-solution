//Link: https://leetcode.com/problems/implement-stack-using-queues/ 
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
   deque<int> mystack;
    /** Push element x onto stack. */
    void push(int x) {
        mystack.push_back(x) ;
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = mystack.back();
        mystack.pop_back();
        return temp;
        
        
    }
    
    /** Get the top element. */
    int top() {
        return mystack.back();
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mystack.empty();
        
    }

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */