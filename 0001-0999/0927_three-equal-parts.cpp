//Link: https://leetcode.com/problems/three-equal-parts/ 
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int lastzeros = 0, ones = 0;
        for( int i = A.size()-1; i >= 0; i--){
            int n = A[i];
            if( n == 0 && ones == 0 )
                lastzeros++;
            if( n == 1 )
                ones++;
        }
        if( ones == 0 )
            return {0,A.size()-1};
        if( ones % 3 ) return {-1,-1};
        int first = 0, second = 0;
        int fone  = ones/3;
        for( int i = 0; i< A.size(); i++ ){
            if( fone > 0 && A[i] == 1){
                fone--;
                if( fone == 0 ){
                    first = i+lastzeros;
                    break;
                }
                continue;
            }
        }
        fone = ones/3;
        for( int i = first+1; i< A.size(); i++ ){
            if( fone > 0 && A[i] == 1){
                fone--;
                if( fone == 0 ){
                    second = i+lastzeros;
                    break;
                }
                continue;
            }
        }
        int f = 0, s = first+1, t = second + 1;
        while( A[f] == 0 )f++;
        while( A[s] == 0 )s++;
        while( A[t] == 0 )t++;
        string fs, ss, ts;
        while( f<=first)
            fs+= A[f++]+'0';
        while( s <= second)
            ss+= A[s++]+'0';
        while( t < A.size() )
            ts+= A[t++]+'0';
        if( fs == ss && ss == ts )
            return {first, second+1};
        else
            return {-1,-1};
    }
};