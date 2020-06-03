#Link: https://leetcode.com/problems/max-area-of-island/ 
class Solution(object):
    
    def setPoint(self, point, area, row, col, idx,mc, conn):
        point[row*mc+col] = idx;
        area[idx] = area.get(idx,[])
        delconn = []
        if( len(conn)> 1):
            sameidx = 0;
            for aidx in conn:
                if not sameidx:
                    sameidx = aidx
                else:
                    for xnum in area[aidx]:
                        if xnum not in area[sameidx]:
                            area[sameidx].append(xnum)
                for gidx in area[aidx]:
                    point[gidx] = sameidx
                if aidx != sameidx:
                    delconn.append(aidx);
        else:
            if row*mc+col not in area[idx]:
                area[idx].append(row*mc+col)
               

    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        point = {}
        area = {}
        Max = 0;
        mr = len(grid)
        mc = len(grid[0])
        #print(mr, mc)
        areaIdx = 1;
        for row in range(len(grid)):
            for col in range(len(grid[row])):
                conn = []
                if( grid[row][col] == 1 ):
                    for i in ( 1, 0,-1):
                        for j in (1,0,-1):
                            if abs(i) == abs(j):
                                continue
                            newr = row + i;
                            newc = col + j;
                            if( newr >=0 and newc>=0 and newr<mr and newc <mc):
                                if(  point.get(newr*mc+newc, 0)>0):
                                    idx = point.get(newr*mc+newc, 0)
                                    if( idx not in conn ):
                                        conn.append(idx)
                                    self.setPoint(point, area, row, col, idx, mc, conn);
                                    if( len(area[idx]) > Max ):
                                        Max = len(area[idx]);
                    if len(conn) == 0:
                        self.setPoint(point, area, row, col, areaIdx, mc, conn);
                        if( len(area[areaIdx]) > Max ):
                            Max = len(area[areaIdx]);
                        areaIdx += 1;
        for key,item in area.items():
            if( len(item) > Max):
                Max = len(item)
        #print(area)
        return Max;
                    