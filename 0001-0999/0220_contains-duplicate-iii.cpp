//Link: https://leetcode.com/problems/contains-duplicate-iii/ 
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if( nums.size() <= 1 ) return false;
        map<long long, int> m;
        int j = 0;
        for( int i = 0; i < nums.size(); i++ ){
            if( i - j > k) m.erase(nums[j++]);
            auto it = m.lower_bound((long long)(nums[i]) - t);
            if( it != m.end() && abs(it->first - nums[i] )<=t  )
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};