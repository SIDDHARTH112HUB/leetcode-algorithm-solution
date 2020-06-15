[401.binary-watch](https://leetcode.com/problems/binary-watch/)  

A binary watch has 4 LEDs on the top which represent the **hours** (**0-11**), and the 6 LEDs on the bottom represent the **minutes** (**0-59**).

Each LED represents a zero or one, with the least significant bit on the right.

![](https://upload.wikimedia.org/wikipedia/commons/8/8b/Binary_clock_samui_moon.jpg)

For example, the above binary watch reads "3:25".

Given a non-negative integer _n_ which represents the number of LEDs that are currently on, return all possible times the watch could represent.

**Example:**

Input: n = 1  
Return: \["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"\]

**Note:**  

*   The order of output does not matter.
*   The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
*   The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".  



**Solution:**  

```cpp
class Solution {
public:
    //vector<string> m;
    //vector<string> s;
    int count1(int num){
        int cnt = 0;
        while(num > 0){
            cnt += (num%2);
            num = num >> 1;
        }
        return cnt;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for( int i = 0; i<=3; i++){
            int j = num - i;
            if( j < 0 || j > 5)
                continue;
            for( int m = 0; m<=11; m++){
                if( count1(m) == i){
                    for( int s = 0; s<=59; s++){
                        if( count1(s) == j){
                            string sec_str = to_string(s);
                            if(sec_str.size() == 1)
                                sec_str = "0"+sec_str;
                            ans.push_back(to_string(m)+":"+sec_str);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```
      