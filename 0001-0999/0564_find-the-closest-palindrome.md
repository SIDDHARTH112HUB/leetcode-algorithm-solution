[564.find-the-closest-palindrome](https://leetcode.com/problems/find-the-closest-palindrome/)  

Given an integer n, find the closest integer (not including itself), which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

**Example 1:**  

  
**Input:** "123"
  
**Output:** "121"
  

**Note:**  

1.  The input **n** is a positive integer represented by string, whose length will not exceed 18.
2.  If there is a tie, return the smaller one as answer.  



**Solution:**  

```cpp
class Solution {
public:
    long long change(string ns, int offset) {
        int i = (ns.size() - 1) / 2, j = (ns.size())/2;
        while(i >= 0 && j < ns.size()) {
            ns[i] += offset;
            if(j != i) {
                ns[j] += offset;
                if(ns[j] < '0')
                    ns[j] = '9';
                else if(ns[j] > '9')
                    ns[j] = '0';
            }
            ++j;
            if(ns[i] < '0' || ns[i] > '9'){
                ns[i] = ns[i] < '0' ? '9':'0';
            }
            else
                i = -1;
            --i;
        }
        return stoll(ns);
    }
    string nearestPalindromic(string n) {
        if(n == "0") return "-1";
        if(n.size() > 1 && n == "1" + string(n.size() - 1, '0')) return string(n.size()-1, '9');
        if(n.size() > 1 && n == "1" + (n.size() > 2 ? string(n.size() - 2, '0'):"") + "1") return string(n.size()-1, '9');
        if(n.size() > 1 && n == string(n.size(), '9')) return "1" + string(n.size() - 1, '0') + "1";
        string ns = n;
        for(int i = 0; i <= ns.size() /2;++i) {
            if(ns[i] != ns[ns.size() - 1 - i])
                ns[ns.size() - 1 - i] = ns[i];
        }
        long long origin = stoll(n);
        long long zero = stoll(ns);
        long long plus1 = change(ns, 1);
        long long minus1 = change(ns, -1);
        //cout<<origin<<" "<<zero<<" "<<plus1<<" "<<minus1<<" "<<ns<<" "<<n<<endl;
        //cout<<abs(plus1 - origin)<<" "<<abs(minus1 - origin)<<endl;
        if(ns == n) return abs(plus1 - origin) >= abs(minus1 - origin) ? to_string(minus1) : to_string(plus1);
        return abs(plus1 - origin) >= abs(minus1 - origin) ? 
            (abs(zero - origin) >= abs(minus1 - origin) ? to_string(minus1) : to_string(zero)) :
            (abs(plus1 - origin) >= abs(zero - origin) ? to_string(zero) : to_string(plus1));
    }
};
```
      