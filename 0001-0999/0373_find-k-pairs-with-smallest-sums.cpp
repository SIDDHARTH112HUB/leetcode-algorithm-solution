//Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/ 
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if( k == 0 ) return {};
        vector<pair<int, int> > ans;
        priority_queue<pair<int, pair<int,int> > > pq;
        int m = nums1.size(), n = nums2.size();
        for( auto a : nums1){
            for( auto b: nums2){
                if( k >= m*n){
                    ans.push_back({a, b});
                }else if( pq.size() < k ){
                    pq.push({a+b,{a, b}});
                }else if( a+b < pq.top().first ){
                    pq.pop();
                    pq.push({a+b,{a,b}});
                }
            }
        }
        if( k >= m*n ) return ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};