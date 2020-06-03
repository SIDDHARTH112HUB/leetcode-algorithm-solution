//Link: https://leetcode.com/problems/defanging-an-ip-address/ 
class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(auto c : address) {
            if( c == '.') {
                ans.push_back('[');
                ans.push_back(c);
                ans.push_back(']');
            }else
                ans.push_back(c);
        }
        return ans;
    }
};