[800.similar-rgb-color](https://leetcode.com/problems/similar-rgb-color/)  

In the following, every capital letter represents some hexadecimal digit from `0` to `f`.

The red-green-blue color `"#AABBCC"` can be written as `"#ABC"` in shorthand.  For example, `"#15c"` is shorthand for the color `"#1155cc"`.

Now, say the similarity between two colors `"#ABCDEF"` and `"#UVWXYZ"` is `-(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2`.

Given the color `"#ABCDEF"`, return a 7 character color that is most similar to `#ABCDEF`, and has a shorthand (that is, it can be represented as some `"#XYZ"`

**Example 1:**
**Input:** color = "#09f166"
**Output:** "#11ee66"
**Explanation: ** 
The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.

**Note:**

*   `color` is a string of length `7`.
*   `color` is a valid RGB color: for `i > 0`, `color[i]` is a hexadecimal digit from `0` to `f`
*   Any answer which has the same (highest) similarity as the best answer will be accepted.
*   All inputs and outputs should use lowercase letters, and the output is 7 characters.  



**Solution:**  

```cpp
class Solution {
public:
    string similarRGB(string color) {
        map<char, int> map_color;
        for( int i = 0; i<10; i++){
            map_color[i+'0'] = i;
            map_color[i] = i+'0';
        }
        for( int i = 10; i<16; i++){
            map_color[i+'a'-10] = i;
            map_color[i] = i+'a'-10;
        }
        int AB = map_color[color[1]] *16 + map_color[color[2]];
        int CD = map_color[color[3]] *16 + map_color[color[4]];
        int EF = map_color[color[5]] *16 + map_color[color[6]];
        //printf(" AB:%d, CD:%d, EF:%d \n", AB, CD ,EF);
        char ans[8];
        ans[7] = 0;
        ans[0] = '#';
        int min_num = 100000;
        for( int i = 0; i<16; i++){
            for( int j = 0; j<16; j++){
                for( int k = 0; k<16; k++){
                    int num = -(AB-i*16-i ) * (AB-i*16-i ) - (CD-j*16-j)* (CD-j*16-j) - (EF-k*16-k)*(EF-k*16-k);
                    if( abs(num) < abs(min_num)){
                        min_num = num;
                        ans[1] = map_color[i];
                        ans[2] = map_color[i];
                        ans[3] = map_color[j];
                        ans[4] = map_color[j];
                        ans[5] = map_color[k];
                        ans[6] = map_color[k];
                       // printf("i %d j %d k%d num %d \n", i, j, k, num);
                    }
                }
            }
        }
        return ans;
    }
};
```
      