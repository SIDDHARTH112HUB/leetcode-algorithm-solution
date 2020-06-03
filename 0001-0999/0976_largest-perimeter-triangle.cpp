//Link: https://leetcode.com/problems/largest-perimeter-triangle/ 
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        for( int i = A.size()-1; i >=2; i--){
            int a  = A[i];
            for( int j = i - 1; j >=1; j--){
                int b = A[j];
                
                if( a >= 2*b)
                    continue;
                for( int k = j-1; k >= 0; k--){
                    int c = A[k];
                    if( b + c <= a)
                        break;
                    if( b+c > a && a-b < c && a - c < b)
                        return a+b+c;
                    while( k > 0 && c == A[k-1])
                        k--;
                }
                while( b == A[j-1])
                    j--;
            }
            while( a == A[i-1])
                i--;
        }
        return ans;
    }
};