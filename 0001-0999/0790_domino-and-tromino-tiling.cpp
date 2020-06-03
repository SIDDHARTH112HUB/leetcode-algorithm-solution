//Link: https://leetcode.com/problems/domino-and-tromino-tiling/ 
class Solution {
public:
    int numTilings(int N) {
        if( N ==1 ) return 1;
        if( N ==2 ) return 2;
        if( N== 3 ) return 5;
        if( N == 4 ) return 11;
        //if(N ==5 ) return 24;
        //if( N ==6 ) return 53;
        //if( N == 7 ) return 117;
        //if(N == 8 ) return 258;
        int prev=3;
        int cur = 5;
        int ans = 5;
        long long NN[1010];
        NN[1] = 1;
        NN[2] = 2;
        NN[3] = 5;
        NN[4] = 11;
        for( int i = 5; i<=N; i++){
            NN[i] = (NN[i-1]*2 + NN[i-3])%1000000007;
        }
        return NN[N];
    }
};