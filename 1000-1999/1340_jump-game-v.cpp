//Link: https://leetcode.com/problems/jump-game-v/ 
class Solution {
public:
    map<int, set<int> > g;
    int ans = 0;
    int maxJumps(vector<int>& arr, int d) {
        for(int i = 0; i < arr.size(); ++i) {
            for(int j = i + 1; j < min((int)arr.size(), i + d + 1); ++j) {
                if(arr[j] >= arr[i]) break;
                g[i].insert(j);
            }
            for(int j = i - 1; j >= max(0, i - d); --j) {
                if(arr[j] >= arr[i]) break;
                g[i].insert(j);
            }
        }
        /*cout<<"begin"<<endl;
        for(auto &it:g) {
            cout<<it.first<<endl;
            for(auto n : it.second){
                cout<<n<<" ";
            }
            cout<<endl;
        }*/
        map<int, int> v;
        for(int i = 0; i < arr.size(); ++i) {
            //cout<<"start: "<<n<<endl;
            
            dfs(i, v);
        }
        return ans;
        
    }
    
    int dfs(int n, map<int, int> &v) {
        if(v.count(n)) {
            ans = max(ans, v[n]);
            return v[n];
        }
        int res = 0;
        for(auto nx: g[n]) {
            res = max(res, dfs(nx, v));
        }
        v[n] = res + 1;
        ans = max(ans, res + 1);
        return v[n];
    }
};