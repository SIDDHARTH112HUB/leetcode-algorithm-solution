//Link: https://leetcode.com/problems/next-greater-element-ii/ 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        vector<int> arr;
        vector<int> ans(nums2.size(), -1);
        unordered_map<int, int> m;
        for(int i = 0; i < nums2.size() *2; ++i) {
            int idx = i % nums2.size();
            int num = nums2[idx];
            while(arr.size() && nums2[arr.back()] < num) {
                ans[arr.back()] = num;
                arr.pop_back();
            }
            if(i < nums2.size())
                arr.push_back(i);
        }
        return ans;
    }
};