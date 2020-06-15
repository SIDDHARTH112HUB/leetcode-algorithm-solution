[282.expression-add-operators](https://leetcode.com/problems/expression-add-operators/)  

Given a string that contains only digits `0-9` and a target value, return all possibilities to add **binary** operators (not unary) `+`, `-`, or `*` between the digits so they evaluate to the target value.

**Example 1:**

**Input:** `_num_ =` "123", _target_ = 6
**Output:** \["1+2+3", "1\*2\*3"\] 

**Example 2:**

**Input:** `_num_ =` "232", _target_ = 8
**Output:** \["2\*3+2", "2+3\*2"\]

**Example 3:**

**Input:** `_num_ =` "105", _target_ = 5
**Output:** \["1\*0+5","10-5"\]

**Example 4:**

**Input:** `_num_ =` "00", _target_ = 0
**Output:** \["0+0", "0-0", "0\*0"\]

**Example 5:**

**Input:** `_num_ =` "3456237490", _target_ = 9191
**Output:** \[\]

**Constraints:**

*   `0 <= num.length <= 10`
*   `num` only contain digits.  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        vector<pair<int, int> > items;
        solve(num, 0, target, 0, items);
        return ans;
    }
    
    void solve(string &str, int total, int target, int idx, vector<pair<int, int> > &items) {
        if (idx == str.size()) {
            if (target == total) {
                string s;
                for (int i = 0; i < items.size(); i++) {
                    auto &item = items[i];
                    s += to_string(item.first);
                    if (i < items.size() - 1) 
                        s.push_back(items[i+1].second);
                }
                ans.push_back(s);
            }
            return;
        }
        long long sum = 0;
        for (int i = idx; i < str.size(); ++i) {
            sum = sum * 10 + (str[i] - '0');
            if (sum > INT_MAX)
                break;
            items.push_back({sum, '+'});
            solve(str, total + sum, target, i+1, items);
            items.pop_back();
            if (items.size() > 0) {
                items.push_back({sum, '-'});
                solve(str, total - sum, target, i+1, items);
                items.pop_back();
                int prev = 1;
                for (int j = items.size()-1; j>=0; --j) {
                    prev *= items[j].first;
                    if (items[j].second == '-'){
                        prev *= -1;
                    }
                    if (items[j].second != '*')
                        break;
                }
                items.push_back({sum, '*'});
                solve(str, total - prev + prev * sum, target, i+1, items);
                items.pop_back();
            }
            if (sum == 0)
                break;
        }
    }
};
```
      