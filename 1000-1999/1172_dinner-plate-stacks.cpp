//Link: https://leetcode.com/problems/dinner-plate-stacks/ 
class DinnerPlates {
public:
    int cap;
    vector<vector<int> > vec;
    map<int, int> lack;
    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
        if(lack.begin() != lack.end()) {
            int idx = lack.begin()->first;
            vec[idx].push_back(val);
            if(vec[idx].size() == cap )
                lack.erase(idx);
            return;
        }
        if(vec.size() == 0 || vec.back().size() == cap) {
            vec.push_back({val});
            return;
        }
        vec.back().push_back(val);
    }
    
    int pop() {
        if(vec.size() == 0) return -1;
        int idx = vec.size() - 1;
        int val = vec.back().back();
        vec.back().pop_back();
        while(vec.size() && vec.back().size() == 0) {
            vec.pop_back();
            lack.erase(vec.size());
        }
        return val;
    }
    
    int popAtStack(int index) {
        if(index >= vec.size() ) return -1;
        if(vec[index].size() == 0) return -1;
        int val = vec[index].back();
        vec[index].pop_back();
        while(vec.size() && vec.back().size() == 0) {
            vec.pop_back();
            lack.erase(vec.size());
        }
        if(index < vec.size()) {
            lack[index] = 1;
        }
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */