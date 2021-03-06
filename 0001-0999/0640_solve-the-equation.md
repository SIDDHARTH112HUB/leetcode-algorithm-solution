[640.solve-the-equation](https://leetcode.com/problems/solve-the-equation/)  

Solve a given equation and return the value of `x` in the form of string "x=#value". The equation contains only '+', '-' operation, the variable `x` and its coefficient.

If there is no solution for the equation, return "No solution".

If there are infinite solutions for the equation, return "Infinite solutions".

If there is exactly one solution for the equation, we ensure that the value of `x` is an integer.

**Example 1:**  

  
**Input:** "x+5-3+x=6+x-2"
  
**Output:** "x=2"
  

**Example 2:**  

  
**Input:** "x=x"
  
**Output:** "Infinite solutions"
  

**Example 3:**  

  
**Input:** "2x=x"
  
**Output:** "x=0"
  

**Example 4:**  

  
**Input:** "2x+3x-6x=x+2"
  
**Output:** "x=-1"
  

**Example 5:**  

  
**Input:** "x=x+2"
  
**Output:** "No solution"  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> xvec, nvec;
    int s2i(string &s, int l, int r, int sign2 ){
        int  sign = 1;
        int num = 0;
        bool hasNum = false;
        for( int j = l; j<r; j++ ){
            char pc = s[j];
            if( pc == '-')
                sign = -1;
            else if( pc == '+')
                continue;
            else if(pc=='x'){
                if(num ==0 && !hasNum )
                    num =1;
                num *= sign;
                num *= sign2;
                xvec.push_back(num);
                return num;
            }
            else{
                num =  num*10 + pc-'0';
                hasNum =  true;
            }
        }
        num *= (sign * sign2 * -1);
        nvec.push_back(num);
        cout<<num<<endl;
        return num;
    }
    string solveEquation(string equation) {
        int prev = 0;
        xvec.clear();
        nvec.clear();
        int sign = 1;
        for( int i = 0; i<= equation.size(); i++){
            if( i == equation.size()){
                s2i(equation, prev, i,sign);
                prev = i+1;
                break;
            }
            char c = equation[i];
            if( c == '+' || c=='-'){
                if( prev < i ){
                    s2i(equation, prev, i, sign);
                    prev = i;
                }
            }else if( c == '=' ){
                s2i(equation, prev, i, sign);
                sign = -1;
                prev = i+1;
                continue;
            }
        }
        int xs = accumulate(xvec.begin(), xvec.end(),0);
        int ns = accumulate(nvec.begin(), nvec.end(),0);
        if( xs == 0 && ns == 0 )
            return "Infinite solutions";
        else if( xs == 0 )
            return "No solution";
        else
            return "x="+to_string(ns/xs);
    }
};
```
      