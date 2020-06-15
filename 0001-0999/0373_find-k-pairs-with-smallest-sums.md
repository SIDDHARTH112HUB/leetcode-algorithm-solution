[373.find-k-pairs-with-smallest-sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)  

You are given two integer arrays **nums1** and **nums2** sorted in ascending order and an integer **k**.

Define a pair **(u,v)** which consists of one element from the first array and one element from the second array.

Find the k pairs **(u1,v1),(u2,v2) ...(uk,vk)** with the smallest sums.

**Example 1:**

**Input:** nums1 = \[1,7,11\], nums2 = \[2,4,6\], k = 3
**Output:** \[\[1,2\],\[1,4\],\[1,6\]\] 
**Explanation:** The first 3 pairs are returned from the sequence: 
             \[1,2\],\[1,4\],\[1,6\],\[7,2\],\[7,4\],\[11,2\],\[7,6\],\[11,4\],\[11,6\]

**Example 2:**

**Input:** nums1 = \[1,1,2\], nums2 = \[1,2,3\], k = 2
**Output:** \[1,1\],\[1,1\] **Explanation:** The first 2 pairs are returned from the sequence: 
             \[1,1\],\[1,1\],\[1,2\],\[2,1\],\[1,2\],\[2,2\],\[1,3\],\[1,3\],\[2,3\]

**Example 3:**

**Input:** nums1 = \[1,2\], nums2 = \[3\], k = 3
**Output:** \[1,3\],\[2,3\] **Explanation:** All possible pairs are returned from the sequence: \[1,3\],\[2,3\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if( k == 0 ) return {};
        vector<pair<int, int> > ans;
        priority_queue<pair<int, pair<int,int> > > pq;
        int m = nums1.size(), n = nums2.size();
        for( auto a : nums1){
            for( auto b: nums2){
                if( k >= m*n){
                    ans.push_back({a, b});
                }else if( pq.size() < k ){
                    pq.push({a+b,{a, b}});
                }else if( a+b < pq.top().first ){
                    pq.pop();
                    pq.push({a+b,{a,b}});
                }
            }
        }
        if( k >= m*n ) return ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      