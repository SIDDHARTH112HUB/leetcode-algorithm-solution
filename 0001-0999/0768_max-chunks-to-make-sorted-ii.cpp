//Link: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/ 
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<pair<int, int> > arr2;
        for(int i = 0; i < arr.size(); ++i) {
            arr2.push_back({arr[i], i});
        }
        sort(arr2.begin(), arr2.end());
        int mx = 0, ans = 0;
        for(int i = 0; i < arr2.size(); ++i) {
            mx = max(arr2[i].second, mx);
            if(mx == i)
                ++ans;
        }
        return ans;
    }
};