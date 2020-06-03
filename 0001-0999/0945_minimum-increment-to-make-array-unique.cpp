//Link: https://leetcode.com/problems/minimum-increment-to-make-array-unique/ 
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int M = 100002;
        int arr[100002] = {0};
        int l = -1, r=-1;
        for( int i = 0; i<A.size(); i++ ){
            arr[A[i]]++;
            
        }
        for( int i = 0; i<M; i++ ){
            if( l == -1 && arr[i] > 1 )
                l = i;
            if( l >= 0 && i > l && arr[i] == 0){
                r = i;
                break;
            }
        }
        int ans = 0;
        if( l == -1 )
            return 0;
        while( l <= M/2 ){
            if( arr[l] > 1 ){
                while( l > r || arr[r] != 0)
                    r++;
                arr[l]--;
                arr[r] = 1;
                ans += r-l;
                //cout<<l<<" "<<r <<endl;
                while(arr[r] > 0 )
                    r++;
                
            }else
                l++;
        }
        return ans;
    }
};