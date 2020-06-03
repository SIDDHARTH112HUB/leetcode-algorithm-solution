//Link: https://leetcode.com/problems/can-i-win/ 
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        long long state = 0;
        if( desiredTotal <= maxChoosableInteger ) return true;
        if( (1 + maxChoosableInteger ) * maxChoosableInteger / 2 < desiredTotal ) return false;
        return getTotal(maxChoosableInteger, desiredTotal, state);
    }
    
    unordered_map<long long, int> m;
    bool getTotal(int maxNum, int dt, long long state){
        if( dt <= 0  ) return false;
        if( m.count(state)) return m[state];
        bool res = false;
        for( long long i = 1; i<= maxNum; i++ ){
            if(state & (1 << i ) ) continue;
            if( !getTotal(maxNum, dt-i, state | (1 << i ) ) ){
                res = true;
                break;
            }
        }
        m[state] = res;
        return res;
    }
};