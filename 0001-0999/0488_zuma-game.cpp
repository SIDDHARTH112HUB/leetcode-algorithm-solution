//Link: https://leetcode.com/problems/zuma-game/ 
class Solution {
public:
    string merge(string s) {
        int prev = 0;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] != s[i-1] || i + 1 == s.size()) {
                int cur = s[i] == s[i-1] ? i : i-1;
                if(cur - prev >= 2) 
                    return merge(s.substr(0, prev) + s.substr(cur + 1));
                prev = i;
            }
        }
        return s;
    }
    int findMinStep(string board, string hand) {
        //cout<<"begin "<<board<<endl<<endl;
        vector<int> hm(128);
        for(auto c : hand)
            ++hm[c];
        int res = dfs(board, hm);
        return res >= 10000 ? -1 : res;
    }
    int dfs(string board, vector<int> &hm) {
        if(board.size() == 0) return 0;
        int ans = 10000;
        for(int i = 0; i < board.size(); ++i) {
            int cnt = 1 + (i + 1 == board.size()? 0 : board[i+1]==board[i]);
            int idx = i;
            if(cnt >1) ++i;
            int need = 3 - cnt;
            if(hm[board[i]]< need) continue;
            hm[board[i]] -= need;
            string ns = board.substr(0, idx) + board.substr(idx+cnt);
            //cout<<"new string "<<ns<<endl;
            ns = merge(ns);
            //cout<<"after merge "<<ns<<endl;
            ans = min(ans, dfs(ns, hm) + need);
            hm[board[i]] += need;
        }
        return ans;
    }
};