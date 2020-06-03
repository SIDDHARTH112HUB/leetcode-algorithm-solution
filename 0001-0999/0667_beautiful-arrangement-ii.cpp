//Link: https://leetcode.com/problems/beautiful-arrangement-ii/ 
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int begin = 1, end=k+1;
        while(begin<=end){
            ans.push_back(begin++);
            if( begin <= end )
                ans.push_back(end--);
        }
        for( int i = k+2; i<=n; i++ ){
            ans.push_back(i);
        }
        return ans;
    }
};