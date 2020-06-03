//Link: https://leetcode.com/problems/first-unique-number/ 
class FirstUnique {
public:
    queue<int> q;
    int cur = 0;
    unordered_map<int, int> dup;
    FirstUnique(vector<int>& nums) {
        for(auto n : nums) {
            add(n);
        }
    }
    
    int showFirstUnique() {
        while(q.size()){
            int n = q.front();
            if(dup[n] <= 1)
                break;
            q.pop();
        }
        return q.size() ? q.front() : - 1;
    }
    
    void add(int value) {
        ++dup[value];
        q.push(value);
    }
};
