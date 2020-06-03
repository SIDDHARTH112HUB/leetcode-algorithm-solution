//Link: https://leetcode.com/problems/next-greater-element-i/ 
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        unordered_map<int, int> m;
        for(int i = 0; i < nums2.size(); ++i) {
            int num = nums2[i];
            while(arr.size() && arr.back() < num) {
                m[arr.back()] = num;
                arr.pop_back();
            }
            arr.push_back(num);
        }
        vector<int> ans;
        for(auto n : nums1) {
            ans.push_back(m.count(n) ? m[n] : -1);
        }
        return ans;
    }
};