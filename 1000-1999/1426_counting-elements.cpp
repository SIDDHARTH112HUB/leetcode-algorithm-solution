//Link: https://leetcode.com/problems/counting-elements/ 
class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int, int> m;
        for(auto n : arr) ++m[n];
        int ans = 0;
        for(int i = 0; i < arr.size(); ++i) 
            ans += (m[arr[i] +1] > 0);
        return ans;
    }
};