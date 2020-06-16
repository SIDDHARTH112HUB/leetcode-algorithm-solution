[1088.confusing-number-ii](https://leetcode.com/problems/confusing-number-ii/)  

We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid.

A _confusing number_ is a number that when rotated 180 degrees becomes a **different** number with each digit valid.(Note that the rotated number can be greater than the original number.)

Given a positive integer `N`, return the number of confusing numbers between `1` and `N` inclusive.

**Example 1:**

  
**Input:** 20
  
**Output:** 6
  
**Explanation:** 
  
The confusing numbers are \[6,9,10,16,18,19\].
  
6 converts to 9.
  
9 converts to 6.
  
10 converts to 01 which is just 1.
  
16 converts to 91.
  
18 converts to 81.
  
19 converts to 61.
  

**Example 2:**

  
**Input:** 100
  
**Output:** 19
  
**Explanation:** 
  
The confusing numbers are \[6,9,10,16,18,19,60,61,66,68,80,81,86,89,90,91,98,99,100\].
  

**Note:**

1.  `1 <= N <= 10^9`  



**Solution:**  

```cpp
vector<int> digits = {0, 1, -2, -3, -4, -5, 9, -7, 8, 6};
vector<int> cnt =    {1, 2, 2, 2, 2, 2, 3, 3, 4, 5};
class Solution {
public:

    int confusingNumberII(int N) {
        this->N = N;
        dfs(0);
        return ans;
    }
private:
    int ans = 0;
    vector<int> nums;
    long long N = 0;
    bool check() {
        int s=0,e=nums.size()-1;
        while(s<=e){
            if(nums[s]==6) {
                if(nums[e]!=9)
                    return true;
            }else if(nums[s]==9) {
                if(nums[e]!=6)
                    return true;
            }else if(nums[s]!=nums[e]) return true;
            s++;
            e--;
        }
        return false;
        
    }
    void dfs(long long sum) {
        if(check()){
            ++ans;
        }
        static int ad[5] = {0, 1, 6, 8, 9};
        for(int i = 0; i <= 4; ++i){
            int n = ad[i];
            long long ns = sum * 10 + n;
            if(ns <= N && ns > 0){
                nums.push_back(n);
                dfs(ns);
                nums.pop_back();
            }
        }        
    }
};
```
      