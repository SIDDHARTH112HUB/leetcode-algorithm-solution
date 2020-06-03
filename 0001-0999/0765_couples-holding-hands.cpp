//Link: https://leetcode.com/problems/couples-holding-hands/ 
class Solution {
public:
    unordered_map<int, int> m;
    int minSwapsCouples(vector<int>& row) {
        return dfs(row, 0, 0);
    }
    
    int dfs(vector<int> &row, long long idx, long long mask) {
        if(idx >= row.size()) return 0;
        //if(m.count(mask)) return m[mask];
        if(abs(row[idx] - row[idx+1]) == 1 && max(row[idx], row[idx+1]) % 2) {
            return dfs(row, idx + 2, mask);
        }
        int ans = 0;
        long long src = mask;
        int a = row[idx] % 2 ? row[idx] - 1: row[idx] + 1;
        long long one = 1;
        for(long long i = idx + 2; i < row.size(); ++i) {
            if(row[i] == a) {
                swap(row[i], row[idx + 1]);
                mask |= (one <<(idx+1));
                mask |= (one <<i);
                ans = 1 + dfs(row, idx+ 2, mask);
                swap(row[i], row[idx + 1]);
                mask = src;
                break;
            }
        }
        /*
        a = row[idx+1] % 2 ? row[idx+1] - 1: row[idx+1] + 1;
        for(long long i = idx + 2; i < row.size(); ++i) {
            if(row[i] == a) {
                swap(row[i], row[idx]);
                mask |= (one <<(idx));
                mask |= (one <<i);
                ans = min(ans, 1 + dfs(row, idx+ 2, mask));
                swap(row[i], row[idx]);
                mask =src;
                break;
            }
        }
        m[src] = ans;*/
        return ans;
    }
};