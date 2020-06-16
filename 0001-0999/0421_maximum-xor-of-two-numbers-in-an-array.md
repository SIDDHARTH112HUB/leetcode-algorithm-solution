[421.maximum-xor-of-two-numbers-in-an-array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/)  

Given a **non-empty** array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ _i_, _j_ < _n_.

Could you do this in O(_n_) runtime?

**Example:**

  
**Input:** \[3, 10, 5, 25, 2, 8\]
  

  
**Output:** 28
  

  
**Explanation:** The maximum result is **5** ^ **25** = 28.  



**Solution:**  

```cpp
/*struct Trie{
    Trie *node[2];
    Trie(){
        node[0]= NULL;node[1] = NULL;
    }
    void insert(int num){
        auto node = this;
        for( int i = 31; i>=0;i--){
            idx = (num >> i) & 1;
            node->node[idx] = new Trie();
            node = node->node[idx];
        }
    }
};*/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        int mask = 0,res = 0;
        for( int i = 31; i>=0; i--){
            mask |= (1<<i);
            set<int> dict;
            for( int i = 0; i < nums.size(); i++){
                int num = nums[i];
                dict.insert( num & mask);
            }
            int t = res | (1<<i);
            for( int prefix : dict){
                if( dict.count( t ^ prefix )){
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};
```
      