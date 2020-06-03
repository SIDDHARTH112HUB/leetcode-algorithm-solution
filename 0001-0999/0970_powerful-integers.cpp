//Link: https://leetcode.com/problems/powerful-integers/ 
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> m;
        for( int i = 0; i<=30; i++){
            if( pow(x, i) > bound )
                break;
            for( int j = 0; j<=30; j++){
                if( pow(y, j) > bound )break;
                long long num = pow(x, i) +pow(y, j);
                if( num <= bound )
                    m.insert(num);
            }
        }
        vector<int> ans(m.begin(), m.end());
        return ans;
    }
};