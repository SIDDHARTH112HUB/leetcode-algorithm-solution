//Link: https://leetcode.com/problems/contains-duplicate-ii/ 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, set<int> > m;
        for(int i = 0; i < nums.size(); ++i){
            int n =  nums[i];
            
            if(m[n].size() > 0){
                if(i - k <= 0)
                    return true;
                auto it = m[n].lower_bound(abs(i - k));
                if(it != m[n].end())
                    return true;
                if(it == m[n].begin() && *it >= abs(i-k))
                    return true;
            }
            m[n].insert(i);
        }
        return false;
    }
};