//Link: https://leetcode.com/problems/divide-chocolate/ 
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        long long l = 1, r = 1e9 / (K + 1);
        long long res = 0;
        while(l < r) {
            long long mid = (l + r + 1) / 2;
            int cnt = 0;
            long long sum = 0;
            for(auto sw : sweetness) {
                if((sum += sw) >= mid) {
                    if(++cnt > K) break;
                    sum = 0;
                }
            }
            if(cnt > K) {
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
};