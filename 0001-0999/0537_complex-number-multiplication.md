[537.complex-number-multiplication](https://leetcode.com/problems/complex-number-multiplication/)  

Given two strings representing two [complex numbers](https://en.wikipedia.org/wiki/Complex_number).

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

**Example 1:**  

  
**Input:** "1+1i", "1+1i"
  
**Output:** "0+2i"
  
**Explanation:** (1 + i) \* (1 + i) = 1 + i2 + 2 \* i = 2i, and you need convert it to the form of 0+2i.
  

**Example 2:**  

  
**Input:** "1+-1i", "1+-1i"
  
**Output:** "0+-2i"
  
**Explanation:** (1 - i) \* (1 - i) = 1 + i2 - 2 \* i = -2i, and you need convert it to the form of 0+-2i.
  

**Note:**

1.  The input strings will not have extra blank.
2.  The input strings will be given in the form of **a+bi**, where the integer **a** and **b** will both belong to the range of \[-100, 100\]. And **the output should be also in this form**.  



**Solution:**  

```javascript
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var complexNumberMultiply = function(a, b) {
    const e1 = a.split("+");
    const e2 = b.split("+");
    const n1 = parseInt(e1[0]);
    const i1 = parseInt(e1[1]);
    const n2 = parseInt(e2[0]);
    const i2 = parseInt(e2[1]);
    return (n1 * n2 -i1 * i2) + "+" + (n1 * i2 + n2 * i1)+"i";
};
```
      