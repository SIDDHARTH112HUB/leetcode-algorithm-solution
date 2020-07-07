[1505.minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits](https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/)  

Given a string `num` representing **the digits** of a very large integer and an integer `k`.

You are allowed to swap any two adjacent digits of the integer **at most** `k` times.

Return _the minimum integer_ you can obtain also as a string.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/06/17/q4_1.jpg)

  
**Input:** num = "4321", k = 4  
**Output:** "1342"  
**Explanation:** The steps to obtain the minimum integer from 4321 with 4 adjacent swaps are shown.  

**Example 2:**

  
**Input:** num = "100", k = 1  
**Output:** "010"  
**Explanation:** It's ok for the output to have leading zeros, but the input is guaranteed not to have any leading zeros.  

**Example 3:**

  
**Input:** num = "36789", k = 1000  
**Output:** "36789"  
**Explanation:** We can keep the number without any swaps.  

**Example 4:**

  
**Input:** num = "22", k = 22  
**Output:** "22"  

**Example 5:**

  
**Input:** num = "9438957234785635408", k = 23  
**Output:** "0345989723478563548"  

**Constraints:**

*   `1 <= num.length <= 30000`
*   `num` contains **digits** only and doesn't have **leading zeros**.
*   `1 <= k <= 10^9`  



**Solution:**  

```cpp
struct BIT{
    vector<int> nums;
    BIT(){}
    void init(int size){
        nums.resize(size+1);
    }
    BIT(int size) : nums(size+1){}
    int lowbit(int x) { return x & -x; }
    void update(int x, int cnt){
        x++;
        while (x < nums.size()) {
            nums[x] += cnt;
            x += lowbit(x);
        }
    }
    
    int query(int x) {
        if(x < 0) return 0;
        ++x;
        int sum = 0;
        while(x > 0) {
            sum += nums[x];
            x -= lowbit(x);
        }
        return sum;
    }
};
class Solution {
public:
    string minInteger(string num, int k) {
        vector<vector<int> > cnt(10);
        for(int i = num.size() - 1; i >= 0; --i) {
            cnt[num[i] - '0'].push_back(i);
        }
        string ans(num.size(), 0);
        BIT bit(num.size() + 1);
        int j = 0;
        int idx = 0;
        while(idx < num.size()) {
            for(int i = 0; i <= 9; ++i) {
                if(cnt[i].size() == 0) continue;
                char c = '0' + i;
                int moves = cnt[i].back() - bit.query(cnt[i].back() - 1);
                if(moves <= k) {
                    ans[idx] = c;
                    k -= moves;
                    bit.update(cnt[i].back(), 1);
                    cnt[i].pop_back();
                    ++idx;
                    break;
                }
            }
        }
        return ans;
    }
};
```
      