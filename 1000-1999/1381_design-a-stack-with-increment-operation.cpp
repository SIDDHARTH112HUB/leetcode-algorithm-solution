//Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/ 
class CustomStack {
public:
    vector<int> v;
    int mx;
    CustomStack(int maxSize) {
        mx = maxSize;  
    }
    
    void push(int x) {
        if(v.size() >= mx) return;
        v.push_back(x);
    }
    
    int pop() {
        if(v.size() == 0) return -1;
        int a = v.back();
        v.pop_back();
        return a;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < min(k, (int)v.size()); ++i) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */