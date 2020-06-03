//Link: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/ 
class Solution {
public:
    map<int, int> m;
    long long M = 1e9 + 7;
    vector<long long> p;
    int countOrders(int n) {
        n *= 2;
        p.resize(n + 1);
        vector<int> dp(n+1);
        p[0] = 0;
        //cout<<endl;
        for(int i = 1; i <=n; ++i) {
            p[i] = p[i-1] + i;
            //cout<<p[i]<<endl;
        }
        return dfs(n);
    }
    long long dfs(int n) {
        if(n == 0) return 0;
        if(n <= 2) return 1;
        if(m.count(n)) return m[n];
        long long sum = (p[n-1] * dfs(n - 2)) %M;
        m[n] = sum;
        return sum;
    }
};