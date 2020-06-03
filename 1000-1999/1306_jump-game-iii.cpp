//Link: https://leetcode.com/problems/jump-game-iii/ 
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        set<int> v;
        q.push(start);
        while(q.size()) {
            int i = q.front();q.pop();
            if(arr[i] == 0) return true;
            int r = arr[i] + i;
            if(r < arr.size() && v.count(r) == 0) {
                v.insert(r);
                q.push(r);
            }
            int l = i - arr[i];
            if(l >= 0 && v.count(l) == 0) {
                v.insert(l);
                q.push(l);
            }
        }
        return false;
    }
};