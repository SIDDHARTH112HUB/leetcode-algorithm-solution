//Link: https://leetcode.com/problems/3sum/ 
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if( num.size() < 3) return {};
        sort(num.begin(), num.end());
        map<int, int> m;
        for( auto n : num )++m[n];
        if( num[0] > 0 ) return {};
        if( num.back() < 0 ) return {};
        vector<vector<int> > ans;
        for( auto it=m.begin(); it!= m.end(); ++it){
            if( it->first > 0 ) return ans;
            if( it->first == 0 ){
                if( it->second >=3 )
                    ans.push_back({0,0,0});
                return ans;
            }
            if( it->second >= 2 && m.count(0-2*it->first) ){
                ans.push_back({it->first, it->first, 0-2*it->first});
            }
            auto it2 = it;
            it2++;
            for( ; it2 != m.end(); ++it2){
                if( it->first + it2->first > 0 ) break;
                
                auto it3 = m.find(0 - it->first - it2->first);
                if( it3 != m.end() ){
                    if( it3->first < it2->first ) break;
                    if( it3->first == it2->first){
                        if( it2->second >= 2 ){
                            ans.push_back({it->first, it2->first, it3->first});
                        }
                    }else{
                        ans.push_back({it->first, it2->first, it3->first});
                    }
                }
            }
            
        }
        return ans;
    }
};