[699.falling-squares](https://leetcode.com/problems/falling-squares/)  

On an infinite number line (x-axis), we drop given squares in the order they are given.

The `i`\-th square dropped (`positions[i] = (left, side_length)`) is a square with the left-most point being `positions[i][0]` and sidelength `positions[i][1]`.

The square is dropped with the bottom edge parallel to the number line, and from a higher height than all currently landed squares. We wait for each square to stick before dropping the next.

The squares are infinitely sticky on their bottom edge, and will remain fixed to any positive length surface they touch (either the number line or another square). Squares dropped adjacent to each other will not stick together prematurely.

 

Return a list `ans` of heights. Each height `ans[i]` represents the current highest height of any square we have dropped, after dropping squares represented by `positions[0], positions[1], ..., positions[i]`.

**Example 1:**

  
**Input:** \[\[1, 2\], \[2, 3\], \[6, 1\]\]
  
**Output:** \[2, 5, 5\]
  
**Explanation:**
  

After the first drop of `positions[0] = [1, 2]: _aa _aa -------` The maximum height of any square is 2.

After the second drop of `positions[1] = [2, 3]: __aaa __aaa __aaa _aa__ _aa__ --------------` The maximum height of any square is 5. The larger square stays on top of the smaller square despite where its center of gravity is, because squares are infinitely sticky on their bottom edge.

After the third drop of `positions[1] = [6, 1]: __aaa __aaa __aaa _aa _aa___a --------------` The maximum height of any square is still 5. Thus, we return an answer of `[2, 5, 5]`.

 

**Example 2:**

  
**Input:** \[\[100, 100\], \[200, 100\]\]
  
**Output:** \[100, 100\]
  
**Explanation:** Adjacent squares don't get stuck prematurely - only their bottom edge can stick to surfaces.
  

**Note:**

*   `1 <= positions.length <= 1000`.
*   `1 <= positions[i][0] <= 10^8`.
*   `1 <= positions[i][1] <= 10^6`.  



**Solution:**  

```cpp
class Solution {
public:
    
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<int> ans;
        if( positions.size() == 0 ) return ans;
        ans.push_back(positions[0].second);
        if( positions.size() == 1 ) return ans;
        map<int, int> height;
        height[0] = positions[0].second;
        int max_h = height[0];
        for( int i =1; i<positions.size(); i++ ){
            auto &p = positions[i];
            bool flag = false;
            for( int j=0; j<i; j++ ){
                auto &pos = positions[j];
                int h = height[h];
                if( !( pos.first+pos.second <= p.first || pos.first >= p.first+p.second)){
                    if( height[j] + p.second > height[i] ){
                        height[i] = height[j] + p.second;
                        flag = true;
                        if( max_h < height[i])
                            max_h = height[i];
                    }
                }
            }
            if( !flag ){
                height[i] = p.second;
                if( max_h < p.second )
                    max_h = p.second;
            }
            ans.push_back(max_h);
        }
        return ans;
    }
};
```
      