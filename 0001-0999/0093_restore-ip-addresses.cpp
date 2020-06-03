//Link: https://leetcode.com/problems/restore-ip-addresses/ 
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        vector<string> item;
        dfs(s, 0, item);    
        return ans;
    }
    
    void dfs(string &s, int idx, vector<string> &item){
        long long num = 0;
        if( item.size() == 4 ){
            if( s.size() == idx ){
                string str = "";
                for( auto &i:item){
                    str+=i;
                    str+='.';
                }
                str.pop_back();
                ans.push_back(str);
            }
            return;
        }
        string str = "";
        for(int i = idx; i<s.size(); i++){
            if( num == 0 && s[i] == '0'){
                item.push_back("0");
                dfs(s, i+1, item);
                item.pop_back();
                break;
            }
            num = num*10 + (s[i]-'0');
            if( num <= 255 ){
                str += s[i];
                item.push_back(str);
                dfs(s, i+1, item);
                item.pop_back();
            }
        }
    }
    
};