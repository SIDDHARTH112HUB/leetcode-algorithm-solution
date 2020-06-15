[990.satisfiability-of-equality-equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)  

Given an array equations of strings that represent relationships between variables, each string `equations[i]` has length `4` and takes one of two different forms: `"a==b"` or `"a!=b"`.  Here, `a` and `b` are lowercase letters (not necessarily different) that represent one-letter variable names.

Return `true` if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.

**Example 1:**

**Input:** \["a==b","b!=a"\]
**Output:** false
**Explanation:** If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.

**Example 2:**

**Input:** \["b==a","a==b"\]
**Output:** true
**Explanation:** We could assign a = 1 and b = 1 to satisfy both equations.

**Example 3:**

**Input:** \["a==b","b==c","a==c"\]
**Output:** true

**Example 4:**

**Input:** \["a==b","b!=c","c==a"\]
**Output:** false

**Example 5:**

**Input:** \["c==c","b==d","x!=z"\]
**Output:** true

**Note:**

1.  `1 <= equations.length <= 500`
2.  `equations[i].length == 4`
3.  `equations[i][0]` and `equations[i][3]` are lowercase letters
4.  `equations[i][1]` is either `'='` or `'!'`
5.  `equations[i][2]` is `'='`  



**Solution:**  

```javascript
/**
 * @param {string[]} equations
 * @return {boolean}
 */
var m = {}
var find = function(c){
    if( m[c] == undefined )
        m[c] = c;
    else if( m[c] != c ) m[c] = find(m[c]);
    
    return m[c];
}

var combine = (a, b)=>{
    a = find(a);
    b = find(b);
    m[a] = b;
}
var equationsPossible = function(equations) {
    m = {}
    equations.sort((a,b)=>{
        if( a[1] == '=')
            return -1;
        else if( b[1] == '=')
            return 1;
        return 0;
    })
    //console.log("begin")
    for( var e of equations ){
        //console.log(e)
        var a = e[0];
        var b = e[3];
        var s = e[1];
        if( s == '='){
            combine(a, b)
        }else{
            if( find(a) == find(b) && m[a] != undefined && m[b] != undefined )
                return false;
        }
    }
    return true;
}; 
```
      