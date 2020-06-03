//Link: https://leetcode.com/problems/groups-of-special-equivalent-strings/ 
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        int ans = 0;
        map<string, int> m;
        for(auto &s:A){
            string s1, s2;
            for( int i = 0; i<s.size(); i++){
                char c = s[i];
                if( i % 2 == 0 ){
                    s1 += c;
                }else{
                    s2 += c;
                }
            }
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            m[s1+s2]++;
        }
        return m.size();
    }
};