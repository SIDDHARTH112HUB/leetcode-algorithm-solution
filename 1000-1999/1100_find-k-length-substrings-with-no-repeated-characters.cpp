//Link: https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/ 
class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if(S.size() < K ) return 0;
        int prev = 0, cur = 0, ans = 0;
        map<int, int> m;
        for(int  i = 0; i < S.size(); ++i) {
            
            int c = S[i];
            if(i - prev > K-1){
                --m[S[prev]];
                ++prev;
            }
            ++m[c];
            while(m[c] > 1){
                --m[S[prev]];
                ++prev;
            }
            if(i - prev >= K-1){
                ++ans;
            }
        }
        return ans;
    }
};