//Link: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/ 
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans= 0;
        for( int i = 0 ; i<A.size(); i++){
            int max = 0;
            for( int j =i; j<A.size(); j++){
                int num = A[j];
                if( max < num )
                    max = num;
                if( max >=L && max<=R ){
                    //printf("%d %d %d\n", max, num, ans);
                    ans++;
                }else{
                    //printf("break;\n");
                    continue;
                }
            }
        }
        return ans;
    }
};