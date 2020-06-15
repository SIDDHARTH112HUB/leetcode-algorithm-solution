//Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/ 
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m * k > bloomDay.size()) return -1;
        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        while(l < r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            int total = 0;
            for(int i = 0; i < bloomDay.size(); ++i) {
                int b = bloomDay[i];
                if(b <= mid) {
                    ++cnt;
                }else{
                    total += cnt / k;
                    cnt = 0;
                }
            }
            total += cnt / k;
            if(total >= m)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};