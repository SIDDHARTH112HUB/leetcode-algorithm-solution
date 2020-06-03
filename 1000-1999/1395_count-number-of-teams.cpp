//Link: https://leetcode.com/problems/count-number-of-teams/ 
class Solution {
public:
    int numTeams(vector<int>& r) {
        int size = r.size();
        int ans = 0;
        for(int i = 0; i < size; ++i) {
            for(int j = i + 1; j < size; ++j) {
                for(int k = j + 1; k < size; ++k){
                    if(r[i] > r[j] && r[j] > r[k])
                        ++ans;
                    else if(r[i] < r[j] && r[j] < r[k])
                        ++ans;
                }
            }
        }
        return ans;
    }
};