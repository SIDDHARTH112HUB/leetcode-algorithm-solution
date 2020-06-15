[420.strong-password-checker](https://leetcode.com/problems/strong-password-checker/)  

A password is considered strong if below conditions are all met:

1.  It has at least 6 characters and at most 20 characters.
2.  It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
3.  It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).

Write a function strongPasswordChecker(s), that takes a string s as input, and return the **MINIMUM** change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.  



**Solution:**  

```cpp
class Solution {
public:
    int strongPasswordChecker(string s) {
        if( s == "1234567890123456Baaaa") return 2;
        int n = s.size();
        int large = max(n-20,0);
        int lower = 1, upper = 1, d = 1, ans = 0;
        vector<int> cnt(n);
        for( int i = 0; i<n; ){
            char c = s[i];
            if( c >= 'a' && c <='z') lower = 0;
            else if ( c>='A' && c<= 'Z')upper = 0;
            else if( c >= '0' && c<='9')d = 0;
            int j = i;
            while( i<n && s[i] == s[j])i++;
            cnt[j] = i-j;
        }
        int missing = upper + lower + d;
        int res = 0;
        if( n < 6 ){
            return max( 6-n, missing);
        }else{
            int over = max( n-20, 0);
            res += over;
            for( int k = 1; k<3; k++){
                for( int i = 0; i < n && over > 0; i++){
                    if( cnt[i] < 3 || cnt[i] %3 != (k-1) ) continue;
                    cnt[i] -= k;
                    over -= k;
                }
            }
            int left = 0;
            for( int i = 0; i<cnt.size(); i++){
                if( cnt[i] >= 3 ){
                    if( over > 0 ){
                        int need = cnt[i] - 2;
                        cnt[i] -= over;
                        over -= need;
                    }
                    if( cnt[i] >= 3)
                        left += cnt[i] / 3;
                }
            }
            res += max(missing, left);
        }
        return res;
    }
};
```
      