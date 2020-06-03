//Link: https://leetcode.com/problems/reordered-power-of-2/ 
class Solution {
public:
    vector<int> num;
    bool reorderedPowerOf2(int N) {
        if( N == 0 ) return false;
        
        while( N > 0 ){
            num.push_back( N%10);
            N /= 10;
        }
        
        return dfs(0, 0, 0);
    }
    bool dfs( int idx, int res, bool zero ){
        
        if( idx >= num.size() ){
            if( zero )
                return false;
            return !(res & (res-1));
        }
        for( int i = 0; i<num.size(); i++ ){
            if( num[i] != -1 ){
                int src = num[i];
                num[i] = -1;
                
                bool b = dfs(idx+1, res + pow(10, idx) * src, src == 0);
                if( b == true )
                    return true;
                num[i] = src;
            }
        }
        return false;
    }
};