//Link: https://leetcode.com/problems/maximum-width-ramp/ 
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int ans = 0;
        vector<pair<int, int> > ramp;
        ramp.push_back({A[0], 0});
        for( int i = 1; i< A.size(); i++ ){
            int num = A[i];
            if( num >= ramp.back().first ){
                int l = 0, r = ramp.size()-1;
                int mid = l;
                while( l <= r ){
                    mid = (l + r)/2;
                    if( ramp[mid].first > num )
                        l = mid+1;
                    else{
                        if( mid > 0 ){
                            if( ramp[mid-1].first <= num)
                                r = mid-1;
                            else
                                break;
                        }else{
                            break;
                        }
                    }
                }
                if( ramp[mid].first <= num )
                    ans = max(ans, i - ramp[mid].second);
            }else{
                ramp.push_back({num, i});
            }
            
        }
        return ans;
    }
};