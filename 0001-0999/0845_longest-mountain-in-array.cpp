//Link: https://leetcode.com/problems/longest-mountain-in-array/ 
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if( A.size() <= 2 ) return 0;
        A.push_back( A.back() );
        int i = 0, b = 0, ans = 0;
        while(i < A.size() - 1 ){
            
            while( i < A.size()-1 && A[i] >= A[i+1])i++;
            b = i;
            
            while( i < A.size()-1 && A[i] < A[i+1])i++;
            int summit = i;
            while( i < A.size()-1 && A[i] > A[i+1])i++;
            if( summit == i )
                continue;
            ans = max(i - b + 1, ans);
        }
        return ans;
    }
};