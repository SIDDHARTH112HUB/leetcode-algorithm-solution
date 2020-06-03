//Link: https://leetcode.com/problems/sequence-reconstruction/ 
class Solution {
public:
    map<int, set<int> > g;
    int ans = 0;
    set<int> v;
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.size() == 0) return false;
        int n = org.size();
        vector<int> indegree(org.size() + 1, -1);
        for(auto &seq : seqs) {
            if(seq.size() == 0) continue;
            if(seq[0] > n || seq[0] <= 0) return false;
            g[seq[0]];
            if(indegree[seq[0]] == -1)
                indegree[seq[0]] = 0;
            for(int i = 1; i < seq.size(); ++i) {
                if(seq[i] > n || seq[i] <= 0) return false;
                g[seq[i-1]].insert(seq[i]);
                if(indegree[seq[i]] == -1)
                    indegree[seq[i]] = 0;
                ++indegree[seq[i]];
            }
        }
        for(int i = 1; i < indegree.size(); ++i) {
            if(indegree[i] == 0) {
                if(isCircle(i)) return false;
                v = {};
            }
        }
        
        for(int i = 1; i < indegree.size(); ++i) {
            if(indegree[i] == 0 && dfs(i, org, 0))
                return true;
        }
        return false;
    }
    bool isCircle(int num) {
        if(v.count(num)) return true;
        v.insert(num);
        for(auto next : g[num]) {
            if(isCircle(next)) return true;
        }
        v.erase(num);
        return false;
    }
    bool dfs(int num, vector<int> &org, int idx) {
        if(idx + 1 == org.size()) return true;
        if(org[idx] != num) return false;
        for(auto next : g[num]) {
            if(dfs(next, org, idx + 1)) return true;
        }
        return false;
    }
};