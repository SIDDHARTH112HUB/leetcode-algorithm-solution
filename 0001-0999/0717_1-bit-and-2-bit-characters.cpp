//Link: https://leetcode.com/problems/1-bit-and-2-bit-characters/ 
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int N = bits.size();
        if( N == 1 ){
            if( bits[0] == 0 ) return true;
            if( bits[0] == 1 ) return false;
        }
        if( bits[N-2] == 0 ) return true;
        int cnt = 0;
        while(cnt < N-1 ){
            if(bits[cnt] == 0 ){
                cnt++;
                continue;
            }else{
                cnt+=2;
            }
        }
        return cnt == (N-1);
    }
};