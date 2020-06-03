//Link: https://leetcode.com/problems/jump-game-iv/ 
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int> > m;
        for(int i = arr.size() - 1; i >=0; --i) {
            m[arr[i]].push_back(i);
        }
        queue<int> q;q.push(0);
        unordered_set<int> v;v.insert(0);
        int step = 0;
        while(q.size()) {
            int size = q.size();
            while(size-->0) {
                int cur = q.front();q.pop();
                if(cur == arr.size()-1) return step;
                for(auto n : m[arr[cur]]) {
                    if(v.count(n)) continue;
                    if(n == arr.size()-1) return step+1;
                    v.insert(n);
                    q.push(n);
                }
                for(int i = 1; i >= -1; i-=2) {
                    int nx = cur + i;
                    if(nx <0 || nx >= arr.size()) continue;
                    if(v.count(nx)) continue;
                    if(nx == arr.size() -1) return step + 1;
                    v.insert(nx);
                    q.push(nx);
                }
            }
            ++step;
        }
        return -1;
    }
};