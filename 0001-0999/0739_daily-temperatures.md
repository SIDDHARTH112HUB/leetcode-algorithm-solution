[739.daily-temperatures](https://leetcode.com/problems/daily-temperatures/)  

Given a list of daily temperatures `T`, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put `0` instead.

For example, given the list of temperatures `T = [73, 74, 75, 71, 69, 72, 76, 73]`, your output should be `[1, 1, 4, 2, 1, 1, 0, 0]`.

**Note:** The length of `temperatures` will be in the range `[1, 30000]`. Each temperature will be an integer in the range `[30, 100]`.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans;
        if(size == 0 ) return ans;
        for( int i =0; i<size-1; i++ ){
            int cur = temperatures[i];
            int warm_idx = 0;
            bool flag = false;
            for( int j = i+1; j<size; j++ ){
                if( temperatures[j] > cur){
                    warm_idx = j;
                    ans.push_back(j-i);
                    flag = true;
                    break;
                }
            }
            if( !flag ){
                ans.push_back(0);
            }
        }
        ans.push_back(0);
        return ans;
    }
};
```
      