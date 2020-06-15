[815.bus-routes](https://leetcode.com/problems/bus-routes/)  

We have a list of bus routes. Each `routes[i]` is a bus route that the i-th bus repeats forever. For example if `routes[0] = [1, 5, 7]`, this means that the first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.

We start at bus stop `S` (initially not on a bus), and we want to go to bus stop `T`. Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.

**Example:**
**Input:** 
routes = \[\[1, 2, 7\], \[3, 6, 7\]\]
S = 1
T = 6
**Output:** 2
**Explanation:** 
The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

**Constraints:**

*   `1 <= routes.length <= 500`.
*   `1 <= routes[i].length <= 10^5`.
*   `0 <= routes[i][j] < 10 ^ 6`.  



**Solution:**  

```python
class Solution(object):
    def numBusesToDestination(self, routes, S, T):
        """
        :type routes: List[List[int]]
        :type S: int
        :type T: int
        :rtype: int
        """
        if( S == T ):
            return 0
        busRouteDict = {}
        for idx, route in enumerate(routes):
            routeDict = {}
            for stop in route:
                routeList = busRouteDict.get(stop, [])
                routeList.append(idx)
                busRouteDict[stop] = routeList
                routeDict[stop] = 1
            routes[idx] = routeDict
        
        beginRouteList = busRouteDict[S]
        #print(busRouteDict)
        curRoute_Q = {}
        for ridx in beginRouteList:
            curRoute_Q[ridx] = 1;
        nextRoute_Q = {}
        visit_stop = {}
        visit_route = {}
        ans = 0
        while( len(curRoute_Q) >0 ):
            ans+=1
            for routeIdx in curRoute_Q.keys():
                    routeDict = routes[routeIdx]
                    visit_route[routeIdx] = 1
                    if( routeDict.has_key(T) ):
                        return ans;
                    else:
                        for stop in routeDict.keys():
                            nextRouteDict = busRouteDict[stop]
                            for nextRouteIdx in nextRouteDict:
                                if not visit_route.get(nextRouteIdx):
                                    nextRoute_Q[nextRouteIdx] = 1
            curRoute_Q = nextRoute_Q
            nextRoute_Q = {}
                            
        return -1
            
            
```
      