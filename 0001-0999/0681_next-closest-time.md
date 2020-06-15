[681.next-closest-time](https://leetcode.com/problems/next-closest-time/)  

Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

**Example 1:**

**Input:** "19:34"
**Output:** "19:39"
**Explanation:** The next closest time choosing from digits **1**, **9**, **3**, **4**, is **19:39**, which occurs 5 minutes later.  It is not **19:33**, because this occurs 23 hours and 59 minutes later.

**Example 2:**

**Input:** "23:59"
**Output:** "22:22"
**Explanation:** The next closest time choosing from digits **2**, **3**, **5**, **9**, is **22:22**. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.  



**Solution:**  

```python
class Solution(object):
    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        t = time.split(":")
        ct = int(t[0]) * 60 + int(t[1]);
        l = []
        
        minT = 1000000000;
        for c in time:
            if c != ":":
                l.append(int(c))
        res = time;
        for a in l:
            for b in l:
                for c in l:
                    for d in l:
                        h = a*10+b
                        m = c*10+d
                        if h<24 and m <60:
                            tt = h*60+m
                            if tt == ct:
                                continue
                            if tt < ct:
                                tt += 24*60
                            if tt < minT:
                                minT = tt
                                res = "%d%d:%d%d"%(a,b,c,d)
        return res;                        
```
      