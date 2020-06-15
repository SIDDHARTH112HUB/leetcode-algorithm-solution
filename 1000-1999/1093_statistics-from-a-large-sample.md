[1093.statistics-from-a-large-sample](https://leetcode.com/problems/statistics-from-a-large-sample/)  

We sampled integers between `0` and `255`, and stored the results in an array `count`:  `count[k]` is the number of integers we sampled equal to `k`.

Return the minimum, maximum, mean, median, and mode of the sample respectively, as an array of **floating point numbers**.  The mode is guaranteed to be unique.

_(Recall that the median of a sample is:_

*   _The middle element, if the elements of the sample were sorted and the number of elements is odd;_
*   _The average of the middle two elements, if the elements of the sample were sorted and the number of elements is even.)_

**Example 1:**

**Input:** count = \[0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0\]
**Output:** \[1.00000,3.00000,2.37500,2.50000,3.00000\]

**Example 2:**

**Input:** count = \[0,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0\]
**Output:** \[1.00000,4.00000,2.18182,2.00000,1.00000\]

**Constraints:**

1.  `count.length == 256`
2.  `1 <= sum(count) <= 10^9`
3.  The mode of the sample that count represents is unique.
4.  Answers within `10^-5` of the true value will be accepted as correct.  



**Solution:**  

```cpp
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        long long mn = -1, mx = -1, sum = 0, md = -1;
        double fmd = 0;
        long long total = accumulate(count.begin(), count.end(), 0);
        long long me = max_element(count.begin(), count.end()) - count.begin();
        long long prev =  0;
        long long sum2 = 0;
        vector<double> ans(4);
        for(int i = 0; i < count.size(); ++i) {
            if( count[i] > 0 && mn == -1){
                mn = i;
            }
            if( count[count.size()-1-i] > 0 && mx == -1)
                mx = count.size()-1-i;
            
            if(sum + count[i] >= (total+1) / 2 && md == -1) {
                if( total % 2 == 1){
                    md = i;
                    fmd = md;
                }
                else{
                    if(sum + count[i] == (total+1) / 2){
                        int cur = i+1;
                        for(int j = i+1; j< count.size();++j)
                            if(count[j]> 0){
                                cur = j;
                                break;
                            }
                        fmd = (cur+i) / 2.0;
                        md = fmd;
                    }else{
                        fmd = i;
                        md = i;
                    }
                }
            }
            if(count[i]> 0)
                prev = i;
            sum += count[i];
            sum2 += count[i] *i;
        }
        ans = {mn, mx, sum2*1.0/total, fmd, me};
        return ans;
    }
};
```
      