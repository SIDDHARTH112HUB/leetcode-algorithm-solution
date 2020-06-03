//Link: https://leetcode.com/problems/orderly-queue/ 
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if( K>1)
            sort(S.begin(), S.end());
        else{
            string minS = S;
            for( int i = 0; i <S.size(); i++){
                S= S.substr(1) + S.substr(0,1);
                minS = min(S, minS);
            }
            return minS;
        }
        return S;
    }
};