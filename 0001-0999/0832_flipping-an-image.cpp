//Link: https://leetcode.com/problems/flipping-an-image/ 
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int size = A.size();
        for( auto &a : A ){
            for( int i = 0; i<=size/2;i++){
                if(i > size - i - 1) continue;
                swap(a[i], a[size-i-1]);
                a[i] = 1 - a[i];
                if(i != size - i - 1)
                    a[size-i-1] = 1 - a[size-i-1];
            }
        }
        return A;
    }
};