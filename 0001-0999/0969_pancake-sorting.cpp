//Link: https://leetcode.com/problems/pancake-sorting/ 
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int total = 0;
        vector<int> ans;
        while( A.size() ){
            auto mxit = max_element(A.begin(), A.end());
            if( A.back() == *mxit){
                A.pop_back();
                continue;
            }
            if( A[0] == *mxit ){
                ans.push_back(A.size());
                reverse(A.begin(), A.end());
                A.pop_back();
                continue;
            }
            ans.push_back(mxit - A.begin() + 1);
            //cout<<mxit - A.begin() + 1<<endl;
            reverse(A.begin(), mxit+1);
            //for( auto i : A )
            //    cout<<i<< " ";
            //break;
        }
        return ans;
    }
};