//Link: https://leetcode.com/problems/cracking-the-safe/ 
class Solution {
public:
    int n, k;
    string crackSafe(int n, int k) {
        this->n = n;
        this->k = k;
        int total = pow(k, n);
        string ans(n, '0');
        //cout<<ans<<" "<<total<<endl;
        unordered_set<string> visited{ans};
        
        helper(total, visited, ans);
        
        return ans;
    }
    void helper(int total, unordered_set<string> &visited, string &ans){
        if( total <= visited.size() )
            return;
        for( char c='0'+k-1; c>='0'; c--){
            string str = ans.substr(ans.size()-n+1, n-1);
            if( !visited.count(str+c) ){
                ans += c;
                visited.insert(str+c);
                helper(total, visited, ans);
            }
        }
    }
};