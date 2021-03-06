[787.cheapest-flights-within-k-stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)  

There are `n` cities connected by `m` flights. Each flight starts from city `u` and arrives at `v` with a price `w`.

Now given all the cities and flights, together with starting city `src` and the destination `dst`, your task is to find the cheapest price from `src` to `dst` with up to `k` stops. If there is no such route, output `-1`.

  
**Example 1:**  
**Input:**   
n = 3, edges = \[\[0,1,100\],\[1,2,100\],\[0,2,500\]\]  
src = 0, dst = 2, k = 1  
**Output:** 200  
**Explanation:**   
The graph looks like this:  
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png)  
  
The cheapest price from city `0` to city `2` with at most 1 stop costs 200, as marked red in the picture.

  
**Example 2:**  
**Input:**   
n = 3, edges = \[\[0,1,100\],\[1,2,100\],\[0,2,500\]\]  
src = 0, dst = 2, k = 0  
**Output:** 500  
**Explanation:**   
The graph looks like this:  
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png)  
  
The cheapest price from city `0` to city `2` with at most 0 stop costs 500, as marked blue in the picture.  

**Constraints:**

*   The number of nodes `n` will be in range `[1, 100]`, with nodes labeled from `0` to `n` `- 1`.
*   The size of `flights` will be in range `[0, n * (n - 1) / 2]`.
*   The format of each flight will be `(src,` `dst``, price)`.
*   The price of each flight will be in the range `[1, 10000]`.
*   `k` is in the range of `[0, n - 1]`.
*   There will not be any duplicated flights or self cycles.  



**Solution:**  

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, unordered_map<int, int> > m;
        for( auto &flight : flights ){
            m[flight[0]][flight[1]] = flight[2];
        }
        queue< vector<int> > pq;
        pq.push({0, src, 0}); // { cost, src, k }
        unordered_map<int, int> seen;
        seen[src] = -1;
        int ans = INT_MAX;
        int k = 0;
        while( pq.size() ){
            int size = pq.size();
            while( size--> 0 ){
                int total = pq.front()[0];
                int src = pq.front()[1];
                int k = pq.front()[2];

                pq.pop();
                if(k > K )
                    continue;
                for( auto it: m[src]){
                    int des = it.first;
                    int price = it.second;
                    if( des == dst )
                        ans = min(ans, total + price);
                    else{
                        if( seen[des] == 0 || seen[des] > total + price  ){
                            pq.push({total + price, des, k+1});
                            seen[des] = total + price;
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```
      