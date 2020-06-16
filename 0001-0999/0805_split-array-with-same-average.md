[805.split-array-with-same-average](https://leetcode.com/problems/split-array-with-same-average/)  

In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)

Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.

  
**Example :**
  
**Input:** 
  
\[1,2,3,4,5,6,7,8\]
  
**Output:** true
  
**Explanation:** We can split the array into \[1,4,5,8\] and \[2,3,6,7\], and both of them have the average of 4.5.
  

**Note:**

*   The length of `A` will be in the range \[1, 30\].
*   `A[i]` will be in the range of `[0, 10000]`.  



**Solution:**  

```cpp
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        sort(A.begin(), A.end() );
        int size = A.size();
        if(size <= 1) return false;
        if( size == 2 && A[0] != A[1] ) return false;
        int sum = accumulate(A.begin(), A.end(),0);
        int max_num = *max_element(A.begin(), A.end());
        if( max_num > sum - max_num ) return false;
        
        //cout<<max_num<<" "<<""<<sum<<" "<<avg<<endl;
        cout<<endl;
        for(int s = 1; s<=size/2; s++){
            if( sum*s % size == 0 ){
                if( dfs( A, s, sum*s/size, 0 ))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<int> &A, int num, int sum, int start){
        if( num == 0 )
            return sum == 0;
        for( int i = start; i<A.size(); i++){
            if( dfs( A, num-1, sum-A[i], i+1 ))
                return true;
        }
        return false;
    }
        
    
};
```
      