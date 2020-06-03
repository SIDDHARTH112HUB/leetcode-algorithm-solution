//Link: https://leetcode.com/problems/maximum-frequency-stack/ 
class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> stk_map;
    int max_freq;
    
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int x) {
        max_freq = max( max_freq, ++freq[x]);
        stk_map[freq[x]].push(x);
    }
    
    int pop() {
        int n = stk_map[max_freq].top();
        stk_map[max_freq].pop();
        if( stk_map[freq[n]--].size() == 0 ) --max_freq;
        
        return n;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */