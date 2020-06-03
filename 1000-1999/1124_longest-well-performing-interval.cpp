//Link: https://leetcode.com/problems/longest-well-performing-interval/ 
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans = 0;
        for(int &h : hours)
            h = h > 8 ? 1 : -1;
        for(int i = 0; i < hours.size(); ++i){
            int cnt = 0;
            for(int j = i; j < hours.size(); ++j){
                cnt += hours[j];
                if(cnt > 0)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};