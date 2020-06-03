//Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/ 
class Solution {
public:
    int ans = 0;
    int maxLength(vector<string>& arr) {
        vector<int> v;
        for(auto &str: arr) {
            int num = 0;
            for(auto c : str) {
                if(( (num & ( 1 << (c-'a')) )!= 0)){
                    num = 0;
                    break;
                }
                num |= ( 1 << (c-'a'));
            }
            if(num > 0){
                //cout<<str<<endl;
                v.push_back(num);
            }
        }
        dfs(v, 0, 0);
        return ans;
    }
    int getbits(int num){
        int cnt = 0;
        //cout<<num<<endl;
        while(num > 0) {
            cnt += (num &1);
            num >>= 1;
        }
        //cout<<cnt<<" "<<num<<endl;
        return cnt;
    }
    void dfs(vector<int> &v, int idx, int num) {
        if(idx >= v.size()) {
            ans = max(ans, getbits(num));
            return;
        }
        dfs(v, idx + 1, num);
        if((num & v[idx]) == 0) {
            int nn = num | v[idx];
            dfs(v, idx + 1, nn);
        }
    }
};