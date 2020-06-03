//Link: https://leetcode.com/problems/stamping-the-sequence/ 
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> ans;
        int total = 0;
        unordered_set<int> v;
        while( total < target.size() ){
            bool found = false;
            for( int i = 0; i <= target.size()-stamp.size(); i++){
                int l = unstamp(stamp, target, i);
                if( l == 0 ) continue;
                if( v.count(i) ) continue;
                total += l;
                v.insert(i);
                ans.push_back(i);
                found = true;
                for( int k = 0; k< stamp.size(); k++ )
                    target[k+i] = '*';
            }
            if( !found ) return {};
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int unstamp(string &stamp, string &target, int idx){
        int l = 0;
        for( int i = 0; i < stamp.size(); i++){
            if( target[i+idx] == '*') 
                continue;
            if(target[i+idx] == stamp[i]){
                l++;
            }else{
                return 0;
            }
        }
        return l;
    }
};