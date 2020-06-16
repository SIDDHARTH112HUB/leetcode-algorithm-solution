[241.different-ways-to-add-parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/)  

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are `+`, `-` and `*`.

**Example 1:**

  
**Input:** `"2-1-1"`
  
**Output:** `[0, 2]`
  
**Explanation:** 
  
((2-1)-1) = 0 
  
(2-(1-1)) = 2

**Example 2:**

  
**Input:** `"2*3-4*5"`
  
**Output:** `[-34, -14, -10, -10, 10]`
  
**Explanation:** (2\*(3-(4\*5))) = -34 
  
((2\*3)-(4\*5)) = -14 
  
((2\*(3-4))\*5) = -10 
  
(2\*((3-4)\*5)) = -10 
  
(((2\*3)-4)\*5) = 10  



**Solution:**  

```cpp
class Solution {
public:
    vector<function<int(int,int)> > op;
    vector<int> nums;
    
    vector<int> diffWaysToCompute(string input) {
        
        
        vector<int> ans;
        if( input.size() == 0 ) return ans;
        int idx = 0, prev = 0;
        for( char c: input){
            if( c >= '0' && c<='9' ){
                if( idx == input.size()-1 ){
                    //cout<<input.substr(prev, idx+1)<<" "<<prev<< " "<< idx-prev+1<<endl;
                    nums.push_back( stoi(input.substr(prev, idx+1) ));
                }
            }else{
                if( c == '+')
                    op.push_back(plus<int>() );
                else if( c == '-')
                    op.push_back(minus<int>());
                else if( c == '*')
                    op.push_back(multiplies<int>());
                //cout<<input.substr(prev, idx+1)<<" "<<prev<< " "<< idx-prev+1<<endl;
                nums.push_back( stoi(input.substr(prev, idx+1) ));
                prev = idx+1;
            }
            idx++;
        }
        if( op.size() == 0 )
            return {nums[0]};
        return solve(0, op.size());
    }
    
    vector<int> solve(int min, int max){
        if( min == max ){
            return {nums[min]};
        }
        vector<int> vec;
        for( int i = min; i<max; i++){
            vector<int> left = solve(min,i);
            vector<int> right = solve(i+1, max);
            for( auto l:left){
                for( auto r: right){
                    vec.push_back(op[i](l, r));
                }
            }
        }
        return vec;
    }
};
```
      