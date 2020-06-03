//Link: https://leetcode.com/problems/split-array-with-same-average/ 
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        sort(A.begin(), A.end() );
        int size = A.size();
        if(size <= 1) return false;
        if( size == 2 && A[0] != A[1] ) return false;
        int sum = accumulate(A.begin(), A.end(),0);
        int max_num = *max_element(A.begin(), A.end());
        if( max_num > sum - max_num ) return false;
        
        //cout<<max_num<<" "<<""<<sum<<" "<<avg<<endl;
        cout<<endl;
        for(int s = 1; s<=size/2; s++){
            if( sum*s % size == 0 ){
                if( dfs( A, s, sum*s/size, 0 ))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<int> &A, int num, int sum, int start){
        if( num == 0 )
            return sum == 0;
        for( int i = start; i<A.size(); i++){
            if( dfs( A, num-1, sum-A[i], i+1 ))
                return true;
        }
        return false;
    }
        
    
};