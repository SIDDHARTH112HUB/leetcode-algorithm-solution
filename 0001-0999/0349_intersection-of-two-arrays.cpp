//Link: https://leetcode.com/problems/intersection-of-two-arrays/ 
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m(nums1.begin(), nums1.end());
        unordered_set<int> m1(nums2.begin(), nums2.end());
        vector<int> ans;
        for( int n : m1 )
            if( m.count(n))
                ans.push_back(n);
        return ans;
    }
};