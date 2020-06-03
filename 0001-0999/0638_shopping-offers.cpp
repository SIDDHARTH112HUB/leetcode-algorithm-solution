//Link: https://leetcode.com/problems/shopping-offers/ 
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = inner_product(price.begin(), price.end(), needs.begin(), 0);
        auto src = needs;
        for(auto &s : special){
            int idx = 0;
            for(auto &n : needs)
                if((n -= s[idx++]) < 0)
                    break;
            if(needs[idx-1] >= 0)
                res = min(res, shoppingOffers(price, special, needs) + s.back());
            needs = src;
        }
        return res;
    }
    unordered_map<int, int> m;
    int shoppingOffers1(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        sort(special.begin(), special.end(), [](vector<int> &a, vector<int> &b){
            return a.back() < b.back();
        });
        int mx = 0;
        for(int i= 0; i < price.size(); ++i)
            mx += price[i] * needs[i];
        return min(helper(price, special, needs), mx);
    }
    
    int hash(vector<int> res) {
        int s = 0;
        int h = 0;
        for(int n : res){
            h |= (n << s);
            s+=4;
        }
        return h;
    }
    int helper(vector<int>& price, vector<vector<int>>& special, vector<int> &buys) {
        int res = INT_MAX;
        auto src = buys;
        int hashCode = hash(buys);
        if(hashCode == 0) return 0;
        if(m.count(hashCode)) return m[hashCode];
        for(int i = 0; i < special.size(); ++i) {
            auto &s = special[i];
            int idx = 0;
            int remain = 0;
            for(int &b: buys)
                if((b -= s[idx++])<0)
                    break;
            
            if(buys[idx-1] >= 0){
                int t = helper(price, special, buys);
                if(t != INT_MAX){
                    res = min(res, t + s.back());
                }
            }else{
                int t = 0;
                for(int i = 0; i < src.size(); ++i)
                    t += price[i] * src[i];
                res = min(res, t);
            }
            buys = src;
        }
        m[hashCode] = res;
        return res;
    }
};