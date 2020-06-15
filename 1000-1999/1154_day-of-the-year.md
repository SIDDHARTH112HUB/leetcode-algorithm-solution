[1154.day-of-the-year](https://leetcode.com/problems/day-of-the-year/)  

Given a string `date` representing a [Gregorian calendar](https://en.wikipedia.org/wiki/Gregorian_calendar) date formatted as `YYYY-MM-DD`, return the day number of the year.

**Example 1:**

**Input:** date = "2019-01-09"
**Output:** 9
**Explanation:** Given date is the 9th day of the year in 2019.

**Example 2:**

**Input:** date = "2019-02-10"
**Output:** 41

**Example 3:**

**Input:** date = "2003-03-01"
**Output:** 60

**Example 4:**

**Input:** date = "2004-03-01"
**Output:** 61

**Constraints:**

*   `date.length == 10`
*   `date[4] == date[7] == '-'`, and all other `date[i]`'s are digits
*   `date` represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.  



**Solution:**  

```javascript
/**
 * @param {string} date
 * @return {number}
 */
var dayOfYear = function(date) {
    var now = new Date(date);
    var start = new Date(now.getFullYear(), 0, 0);
    var diff = now - start;
    var oneDay = 1000 * 60 * 60 * 24;
    var day = Math.floor(diff / oneDay);
    return day;
};
```
      