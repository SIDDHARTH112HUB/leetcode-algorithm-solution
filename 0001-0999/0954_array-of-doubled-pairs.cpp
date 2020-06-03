//Link: https://leetcode.com/problems/array-of-doubled-pairs/ 
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end(), [](int &a, int &b){
            if( a < 0 && b< 0)
                return a>b;
            return a<b;
        });
        unordered_map<int, int> m;
        for( auto n : A)
            ++m[n];
        //cout<<"begin"<<endl;
        for( int i = 0; i<A.size(); i++){
            int n = A[i];
          //  cout<<n<<endl;
            if( m[n] ){
                if( m[n*2] == 0)
                    return false;
            //    cout<<n<<" "<<2*n<<endl;
                --m[n];
                --m[n*2];
            }
        }
        return true;
    }
};