//Link: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/ 
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto n : nums) ++m[n];
        while(m.size()) {
            auto it = m.begin();
            int s = it->first;
            int c = it->second;
            for(int i = 0; i <k; ++i) {
                if(m[s + i] < c) return false;
                m[s+i] -= c;
                if(m[s+i] == 0)
                    m.erase(s+i);
            }
        }
        return true;
    }
};