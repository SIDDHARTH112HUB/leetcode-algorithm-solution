//Link: https://leetcode.com/problems/verbal-arithmetic-puzzle/ 
class Solution {
public:
    unordered_map<char, int> m;
    vector<int> v;

    bool isSolvable(vector<string>& words, string result) {
        //words.push_back(result);
        for(auto &w : words) {
            reverse(w.begin(), w.end());
            if(w.size() > result.size())
                return false;
        }
        reverse(result.begin(), result.end());
        v.resize(128);
        for(auto &n: v) n = -1;
        return dfs(0, 0, words, result, 0);
    }
    
    bool dfs(int col, int row, vector<string>& words, string &result, int sum) {
        if(col >= result.size()) {
            return sum == 0 && v[result.back()] != 0;
        }
        if(row == words.size()) {
            int mod = sum % 10;
            int rc = result[col];
            if(v[rc] >= 0) {
                if(mod != v[rc])
                    return false;
            }else if(m[mod])
                return false;
            int srm = m[mod], srv = v[rc];
            m[mod] = 1;
            v[rc] = mod;
            if(dfs(col + 1, 0, words, result, sum / 10))
                return true;
            m[mod] = srm;
            v[rc] = srv;
            return false;
        }
        if(col >= words[row].size()) {
            return dfs(col, row + 1, words, result, sum);
        }
        int ch = words[row][col];
        if(v[ch] >= 0) {
            sum += v[ch];
            return dfs(col, row + 1, words, result, sum);
        }
        for(int i = (col + 1 == words[row].size() ? 1 : 0); i <= 9; ++i) {
            if(m[i]) continue;
            m[i] = 1;
            v[ch] = i;
            if(dfs(col, row+1, words, result, i + sum)) return true;
            m[i] = 0;
            v[ch] = -1;
        }
        return false;
    }
};