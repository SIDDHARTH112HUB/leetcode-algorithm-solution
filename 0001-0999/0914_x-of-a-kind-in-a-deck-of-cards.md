[914.x-of-a-kind-in-a-deck-of-cards](https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/)  

In a deck of cards, each card has an integer written on it.

Return `true` if and only if you can choose `X >= 2` such that it is possible to split the entire deck into 1 or more groups of cards, where:

*   Each group has exactly `X` cards.
*   All the cards in each group have the same integer.

**Example 1:**

  
**Input:** deck = \[1,2,3,4,4,3,2,1\]  
**Output:** true  
**Explanation**: Possible partition \[1,1\],\[2,2\],\[3,3\],\[4,4\].  

**Example 2:**

  
**Input:** deck = \[1,1,1,2,2,2,3,3\]  
**Output:** false´  
**Explanation**: No possible partition.  

**Example 3:**

  
**Input:** deck = \[1\]  
**Output:** false  
**Explanation**: No possible partition.  

**Example 4:**

  
**Input:** deck = \[1,1\]  
**Output:** true  
**Explanation**: Possible partition \[1,1\].  

**Example 5:**

  
**Input:** deck = \[1,1,2,2,2,2\]  
**Output:** true  
**Explanation**: Possible partition \[1,1\],\[2,2\],\[2,2\].  

**Constraints:**

*   `1 <= deck.length <= 10^4`
*   `0 <= deck[i] < 10^4`  



**Solution:**  

```cpp
int gcd(int n, int m){
    if( n == 0 ) return m;
    if( m == 0 ) return n;
    if( n % m == 0 ) return m;
    return gcd(m, n % m);
}
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if( deck.size() <= 1 ) return false;
        unordered_map<int, int> m;
        for( int n : deck)
            m[n]++;
        if( m.size() == 1 ) return true;
        vector<int> v;
        for( auto it : m ){
            v.push_back(it.second);
        }
        //sort(v.begin(), v.end());
        int g = gcd(v[1], v[0]);
        if( g <= 1 ) return false;
        for( int i = 2; i<v.size(); i++){
            g = gcd(v[i], g);
            if( g <= 1 )
                return false;
        }
        return true;
    }
};
```
      