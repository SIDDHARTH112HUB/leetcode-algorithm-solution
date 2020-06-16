[954.array-of-doubled-pairs](https://leetcode.com/problems/array-of-doubled-pairs/)  

Given an array of integers `A` with even length, return `true` if and only if it is possible to reorder it such that `A[2 * i + 1] = 2 * A[2 * i]` for every `0 <= i < len(A) / 2`.

**Example 1:**

  
**Input:** \[3,1,3,6\]
  
**Output:** false
  

**Example 2:**

  
**Input:** \[2,1,2,6\]
  
**Output:** false
  

**Example 3:**

  
**Input:** \[4,-2,2,-4\]
  
**Output:** true
  
**Explanation:** We can take two groups, \[-2,-4\] and \[2,4\] to form \[-2,-4,2,4\] or \[2,4,-2,-4\].
  

**Example 4:**

  
**Input:** \[1,2,4,16,8,4\]
  
**Output:** false
  

**Note:**

1.  `0 <= A.length <= 30000`
2.  `A.length` is even
3.  `-100000 <= A[i] <= 100000`  



**Solution:**  

```cpp
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end(), [](int &a, int &b){
            if( a < 0 && b< 0)
                return a>b;
            return a<b;
        });
        unordered_map<int, int> m;
        for( auto n : A)
            ++m[n];
        //cout<<"begin"<<endl;
        for( int i = 0; i<A.size(); i++){
            int n = A[i];
          //  cout<<n<<endl;
            if( m[n] ){
                if( m[n*2] == 0)
                    return false;
            //    cout<<n<<" "<<2*n<<endl;
                --m[n];
                --m[n*2];
            }
        }
        return true;
    }
};
```
      