//Link: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/ 
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans= "";
        for( auto &str:d){
            if( str.size() > s.size() )
                continue;
            
            int i = 0, j=0;
            while( i<s.size() && j<str.size()){
                if( s[i] == str[j])
                    j++;
                i++;
            }
            if( j == str.size() ){
                if( ans == "")
                    ans = str;
                else{
                    if( ans.size() <= str.size() ){
                        if( ans.size() == str.size() )
                            ans = min(ans, str);
                        else
                            ans = str;
                    }
                }
            }
        }
        return ans;
    }
};