//Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/ 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        for( int n : nums1)
            ++m1[n];
        for( int n : nums2)
            ++m2[n];
        vector<int> ans;
        for( auto it : m1){
            if( m2.count(it.first)){
                int n = min(it.second, m2[it.first]);
                for( int i = 0; i< n; i++)
                    ans.push_back(it.first);
            }
        }
        return ans;
    }
};