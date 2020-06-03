//Link: https://leetcode.com/problems/daily-temperatures/ 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans;
        if(size == 0 ) return ans;
        for( int i =0; i<size-1; i++ ){
            int cur = temperatures[i];
            int warm_idx = 0;
            bool flag = false;
            for( int j = i+1; j<size; j++ ){
                if( temperatures[j] > cur){
                    warm_idx = j;
                    ans.push_back(j-i);
                    flag = true;
                    break;
                }
            }
            if( !flag ){
                ans.push_back(0);
            }
        }
        ans.push_back(0);
        return ans;
    }
};