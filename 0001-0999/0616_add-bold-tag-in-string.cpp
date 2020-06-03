//Link: https://leetcode.com/problems/add-bold-tag-in-string/ 
struct Trie {
    
};
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> arr(s.size());
        for(auto &str : dict) {
            int pos = 0;
            while((pos = s.find(str, pos)) != string::npos) {
                for(int i = pos; i < str.size() + pos; ++i) {
                    arr[i] = true;
                }
                pos += 1;
            }
        }
        string ans;
        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] == true) {
                if(i == 0 || arr[i-1] == false)
                    ans += "<b>";
            }else if(i > 0){
                if(arr[i-1] == true )
                    ans += "</b>";
            }
            ans += s[i];
        }
        if(arr.back() == true)
            ans += "</b>";
        return ans;
    }
};