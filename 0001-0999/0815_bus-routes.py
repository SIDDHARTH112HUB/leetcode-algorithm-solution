#Link: https://leetcode.com/problems/bus-routes/ 
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
            
            