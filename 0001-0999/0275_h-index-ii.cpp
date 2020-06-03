//Link: https://leetcode.com/problems/h-index-ii/ 
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        int l = 0, r = citations.back()+1;
        int ans = 0;
        while(l < r) {
            int mid = (l+r) / 2;
            int h = citations.end() - lower_bound(citations.begin(), citations.end(), mid);
            if(h >= mid) {
                l = mid + 1;   
                ans = max(ans, mid);
            }else
                r = mid;
        }
        return ans;
    }
};