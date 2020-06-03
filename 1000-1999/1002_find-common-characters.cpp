//Link: https://leetcode.com/problems/find-common-characters/ 
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<unordered_map<int, int> > m(A.size());
        for(int i = 0; i < A.size(); ++i)
            for(auto c : A[i])
                ++m[i][c];
        vector<string> ans;
        for(int c = 'a'; c <='z'; ++c) {
            int cnt = INT_MAX;
            for(int i  = 0; i < m.size(); ++i)
                cnt = min(cnt, m[i][c]);
            while(cnt-- > 0){
                ans.push_back("");
                ans.back() += c;
            }
        }
        return ans;
    }
};