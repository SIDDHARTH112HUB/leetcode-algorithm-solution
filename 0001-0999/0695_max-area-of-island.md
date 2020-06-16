[695.max-area-of-island](https://leetcode.com/problems/max-area-of-island/)  

Given a non-empty 2D array `grid` of 0's and 1's, an **island** is a group of `1`'s (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

**Example 1:**

  
\[\[0,0,1,0,0,0,0,1,0,0,0,0,0\],
  
 \[0,0,0,0,0,0,0,1,1,1,0,0,0\],
  
 \[0,1,1,0,1,0,0,0,0,0,0,0,0\],
  
 \[0,1,0,0,1,1,0,0,**1**,0,**1**,0,0\],
  
 \[0,1,0,0,1,1,0,0,**1**,**1**,**1**,0,0\],
  
 \[0,0,0,0,0,0,0,0,0,0,**1**,0,0\],
  
 \[0,0,0,0,0,0,0,1,1,1,0,0,0\],
  
 \[0,0,0,0,0,0,0,1,1,0,0,0,0\]\]
  

Given the above grid, return `6`. Note the answer is not 11, because the island must be connected 4-directionally.

**Example 2:**

  
\[\[0,0,0,0,0,0,0,0\]\]

Given the above grid, return `0`.

**Note:** The length of each dimension in the given `grid` does not exceed 50.  



**Solution:**  

```python
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
                    
```
      