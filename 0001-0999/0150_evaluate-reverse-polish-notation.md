[150.evaluate-reverse-polish-notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)  

Evaluate the value of an arithmetic expression in [Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation).

Valid operators are `+`, `-`, `*`, `/`. Each operand may be an integer or another expression.

**Note:**

*   Division between two integers should truncate toward zero.
*   The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

**Example 1:**

  
**Input:** \["2", "1", "+", "3", "\*"\]
  
**Output:** 9
  
**Explanation:** ((2 + 1) \* 3) = 9
  

**Example 2:**

  
**Input:** \["4", "13", "5", "/", "+"\]
  
**Output:** 6
  
**Explanation:** (4 + (13 / 5)) = 6
  

**Example 3:**

  
**Input:** \["10", "6", "9", "3", "+", "-11", "\*", "/", "\*", "17", "+", "5", "+"\]
  
**Output:** 22
  
**Explanation:** 
  
  ((10 \* (6 / ((9 + 3) \* -11))) + 17) + 5
  
= ((10 \* (6 / (12 \* -11))) + 17) + 5
  
= ((10 \* (6 / -132)) + 17) + 5
  
= ((10 \* 0) + 17) + 5
  
= (0 + 17) + 5
  
= 17 + 5
  
= 22  



**Solution:**  

```python
class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
        n_s = []
        op = {"*":operator.mul,"-":operator.sub, "+":operator.add, "/":operator.div}
        for i in tokens:
            if i.isdigit()==True or len(i)>1:
                n_s.append(int(i))
            else:
                a2 =n_s.pop()
                a1 = n_s.pop()
                s = int(op[i](a1, a2*1.0))
                n_s.append(s)
        return n_s[0]
```
      