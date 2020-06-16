[638.shopping-offers](https://leetcode.com/problems/shopping-offers/)  

In LeetCode Store, there are some kinds of items to sell. Each item has a price.

However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job is to output the lowest price you have to pay for **exactly** certain items as given, where you could make optimal use of the special offers.

Each special offer is represented in the form of an array, the last number represents the price you need to pay for this special offer, other numbers represents how many specific items you could get if you buy this offer.

You could use any of special offers as many times as you want.

**Example 1:**  

  
**Input:** \[2,5\], \[\[3,0,5\],\[1,2,10\]\], \[3,2\]
  
**Output:** 14
  
**Explanation:** 
  
There are two kinds of items, A and B. Their prices are $2 and $5 respectively. 
  
In special offer 1, you can pay $5 for 3A and 0B
  
In special offer 2, you can pay $10 for 1A and 2B. 
  
You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
  

**Example 2:**  

  
**Input:** \[2,3,4\], \[\[1,1,0,4\],\[2,2,1,9\]\], \[1,2,1\]
  
**Output:** 11
  
**Explanation:** 
  
The price of A is $2, and $3 for B, $4 for C. 
  
You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C. 
  
You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C. 
  
You cannot add more items, though only $9 for 2A ,2B and 1C.
  

**Note:**  

1.  There are at most 6 kinds of items, 100 special offers.
2.  For each item, you need to buy at most 6 of them.
3.  You are **not** allowed to buy more items than you want, even if that would lower the overall price.  



**Solution:**  

```cpp
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
```
      