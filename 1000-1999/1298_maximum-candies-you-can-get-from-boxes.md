[1298.maximum-candies-you-can-get-from-boxes](https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/)  

Given `n` boxes, each box is given in the format `[status, candies, keys, containedBoxes]` where:

*   `status[i]`: an integer which is **1** if `box[i]` is open and **0** if `box[i]` is closed.
*   `candies[i]`: an integer representing the number of candies in `box[i]`.
*   `keys[i]`: an array contains the indices of the boxes you can open with the key in `box[i]`.
*   `containedBoxes[i]`: an array contains the indices of the boxes found in `box[i]`.

You will start with some boxes given in `initialBoxes` array. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.

Return _the maximum number of candies_ you can get following the rules above.

**Example 1:**

**Input:** status = \[1,0,1,0\], candies = \[7,5,4,100\], keys = \[\[\],\[\],\[1\],\[\]\], containedBoxes = \[\[1,2\],\[3\],\[\],\[\]\], initialBoxes = \[0\]
**Output:** 16
**Explanation:** You will be initially given box 0. You will find 7 candies in it and boxes 1 and 2. Box 1 is closed and you don't have a key for it so you will open box 2. You will find 4 candies and a key to box 1 in box 2.
In box 1, you will find 5 candies and box 3 but you will not find a key to box 3 so box 3 will remain closed.
Total number of candies collected = 7 + 4 + 5 = 16 candy.

**Example 2:**

**Input:** status = \[1,0,0,0,0,0\], candies = \[1,1,1,1,1,1\], keys = \[\[1,2,3,4,5\],\[\],\[\],\[\],\[\],\[\]\], containedBoxes = \[\[1,2,3,4,5\],\[\],\[\],\[\],\[\],\[\]\], initialBoxes = \[0\]
**Output:** 6
**Explanation:** You have initially box 0. Opening it you can find boxes 1,2,3,4 and 5 and their keys. The total number of candies will be 6.

**Example 3:**

**Input:** status = \[1,1,1\], candies = \[100,1,100\], keys = \[\[\],\[0,2\],\[\]\], containedBoxes = \[\[\],\[\],\[\]\], initialBoxes = \[1\]
**Output:** 1

**Example 4:**

**Input:** status = \[1\], candies = \[100\], keys = \[\[\]\], containedBoxes = \[\[\]\], initialBoxes = \[\]
**Output:** 0

**Example 5:**

**Input:** status = \[1,1,1\], candies = \[2,3,2\], keys = \[\[\],\[\],\[\]\], containedBoxes = \[\[\],\[\],\[\]\], initialBoxes = \[2,1,0\]
**Output:** 7

**Constraints:**

*   `1 <= status.length <= 1000`
*   `status.length == candies.length == keys.length == containedBoxes.length == n`
*   `status[i]` is `0` or `1`.
*   `1 <= candies[i] <= 1000`
*   `0 <= keys[i].length <= status.length`
*   `0 <= keys[i][j] < status.length`
*   All values in `keys[i]` are unique.
*   `0 <= containedBoxes[i].length <= status.length`
*   `0 <= containedBoxes[i][j] < status.length`
*   All values in `containedBoxes[i]` are unique.
*   Each box is contained in one box at most.
*   `0 <= initialBoxes.length <= status.length`
*   `0 <= initialBoxes[i] < status.length`  



**Solution:**  

```cpp
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        set<int> vb;
        set<int> v;
        for(auto b : initialBoxes) {
            if(v.count(b)) continue;
            q.push(b);
            v.insert(b);
            vb.insert(b);
            status[b] = 1;
        }
        int ans = 0;
        int t = 0;
        while(q.size()) {
            ++t;
            int k = q.front();
            q.pop();
            
            if(t > 1000000) return ans;
            if(vb.count(k) == 0 || status[k] == 0) {
                q.push(k);
                continue;
            }
            //cout<<" open box "<<k<<endl;
            for(auto b : containedBoxes[k]) {
                vb.insert(b);
                if(status[b] == 1 && v.count(b) == 0) {
                    q.push(b);
                    v.insert(b);
                }
            }
            ans += candies[k];
            for(auto n : keys[k]) {
                //cout<<"get key:"<< n<<endl;
                if(v.count(n)) continue;
                //cout<<"key: "<<n<<endl;
                q.push(n);
                v.insert(n);
                status[n] = 1;
            }
        }
        return ans;
    }
};
```
      