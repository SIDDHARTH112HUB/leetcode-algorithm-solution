//Link: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/ 
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        set<int> vb;
        set<int> v;
        for(auto b : initialBoxes) {
            if(v.count(b)) continue;
            q.push(b);
            v.insert(b);
            vb.insert(b);
            status[b] = 1;
        }
        int ans = 0;
        int t = 0;
        while(q.size()) {
            ++t;
            int k = q.front();
            q.pop();
            
            if(t > 1000000) return ans;
            if(vb.count(k) == 0 || status[k] == 0) {
                q.push(k);
                continue;
            }
            //cout<<" open box "<<k<<endl;
            for(auto b : containedBoxes[k]) {
                vb.insert(b);
                if(status[b] == 1 && v.count(b) == 0) {
                    q.push(b);
                    v.insert(b);
                }
            }
            ans += candies[k];
            for(auto n : keys[k]) {
                //cout<<"get key:"<< n<<endl;
                if(v.count(n)) continue;
                //cout<<"key: "<<n<<endl;
                q.push(n);
                v.insert(n);
                status[n] = 1;
            }
        }
        return ans;
    }
};