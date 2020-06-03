//Link: https://leetcode.com/problems/create-maximum-number/ 
class Solution {
public:
    
    vector<int> maxArray(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            if(ans.size() == 0){
                ans.push_back(n);
                continue;
            }
            while(ans.size() && nums.size() - i + ans.size() > k && ans.back() < n){
                ans.pop_back();
            }
            ans.push_back(n);
        }
        while(ans.size() > k)
            ans.pop_back();
        return ans;
    }
    
    vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
        auto b1 = nums1.cbegin();
        auto e1 = nums1.cend();
        auto b2 = nums2.cbegin();
        auto e2 = nums2.cend();
        vector<int> ans;
        while(b1 != e1 || b2 != e2) {
            bool res = lexicographical_compare(b1, e1, b2, e2);
            ans.push_back(res ? *b2++ : *b1++);
        }
        return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for(int i = 0; i <=k; ++i){
            if( i > nums1.size() || k - i > nums2.size())continue;
            auto a1 = maxArray(nums1, i);
            auto a2 = maxArray(nums2, k-i);
            ans = max(ans, merge(a1, a2) );
        }
        return ans;
    }
};