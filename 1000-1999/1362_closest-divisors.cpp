//Link: https://leetcode.com/problems/closest-divisors/ 
class Solution {
public:
    vector<int> closestDivisors(int num) {
        int sq = sqrt(num + 2);
        vector<int> ans;
        int diff = INT_MAX;
        for(int i = 1; i <= sq; ++i) {
            if( (num + 1) % i == 0 ){
                int x = (num+1) / i;
                if(abs(x - i) < diff){
                    ans = {i, x};
                    diff = abs(x - i);
                }
            }
            if( (num + 2) % i == 0 ){
                int x = (num+2) / i;
                if(abs(x - i) < diff){
                    ans = {i, x};
                    diff = abs(x - i);
                }
            }
                
        }
        return ans;
    }
};