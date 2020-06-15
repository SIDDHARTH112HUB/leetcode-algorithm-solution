[306.additive-number](https://leetcode.com/problems/additive-number/)  

Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain **at least** three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits `'0'-'9'`, write a function to determine if it's an additive number.

**Note:** Numbers in the additive sequence **cannot** have leading zeros, so sequence `1, 2, 03` or `1, 02, 3` is invalid.

**Example 1:**

**Input:** "112358"
**Output:** true
**Explanation:** The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
             1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

**Example 2:**

**Input:** "199100199"
**Output:** true
**Explanation:** The additive sequence is: 1, 99, 100, 199. 
             1 + 99 = 100, 99 + 100 = 199

**Constraints:**

*   `num` consists only of digits `'0'-'9'`.
*   `1 <= num.length <= 35`

**Follow up:**  
How would you handle overflow for very large input integers?  



**Solution:**  

```cpp
class Solution {
public:
    bool isAdditiveNumber(string num) {
        for( int i = 1; i<num.size() && i < 20; i++){
            for( int j = i+1; j<num.size()&& j-i <20; j++ ){
                if( solve(num, i, j) )
                    return true;
            }
        }
        return false;
    }
    
    bool solve(string &num, int i, int j){
        long long a = stoll(num.substr(0, i));
        //int len = i;
        if( a > 0 && num[0] == '0' )
            return false;
        //cout<<num.substr(i, j-i)<<endl;
        long long b = stoll(num.substr(i, j-i));
        if( b > 0 && num[i] =='0')
            return false;
        long long c = a+b;
        string str = to_string(c);
        //cout<<"begin"<<a<<" "<<b<<" "<<str<<endl;
        while( j+str.size() <= num.size()){
            //cout<<a<<" "<<b<<" "<<str<<endl;
            //if( num[j] == '0') return false;
            if( str == num.substr(j, str.size()) ){
                if( j + str.size() == num.size() )
                    return true;
                i = j;
                j += str.size();
                a = b;
                b = c;
                c=a+b;
                str = to_string(a+b);
            }else
                return false;
            
        }
        return false;
    }
};
```
      