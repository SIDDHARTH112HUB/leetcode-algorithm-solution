//Link: https://leetcode.com/problems/min-stack/ 
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> min_stk;
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if( min_stk.size() ){
            if( min_stk.top() > x )
                min_stk.push(x);
            else
                min_stk.push(min_stk.top());
        }else
            min_stk.push(x);
    }
    
    void pop() {
        if( stk.size() ){
            stk.pop();
            min_stk.pop();
        }
    }
    
    int top() {
        if( stk.size() )
            return stk.top();
        return INT_MIN;
    }
    
    int getMin() {
        if( min_stk.size())
            return min_stk.top();
        return INT_MIN;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */