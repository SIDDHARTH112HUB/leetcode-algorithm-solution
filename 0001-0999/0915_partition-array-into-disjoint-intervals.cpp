//Link: https://leetcode.com/problems/partition-array-into-disjoint-intervals/ 
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int l = 1;
        int maxLeft = A[0];
        for( int i =1; i<A.size(); i++){
            if( maxLeft <= A[i] ){
                int tmp = maxLeft;
                while(i < A.size() && maxLeft <= A[i] ){
                    tmp = max( tmp, A[i]);
                    i++;
                }
                maxLeft = tmp;
                if( i == A.size() )
                    return l;
                l = i+1;
            }else{
                l = i+1;
            }
        }
        return l;
    }
};