#Link: https://leetcode.com/problems/employee-free-time/ 
# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def employeeFreeTime(self, avails):
        """
        :type avails: List[List[Interval]]
        :rtype: List[Interval]
        """
        avails_list = []
        for employee in avails:
            for avail in employee:
                avails_list.append([avail.start, avail.end])
        avails_list.sort();
        print(avails_list);
        for idx in range(1,len(avails_list)):
            cur = avails_list[idx];
            prev = avails_list[idx-1];
            if( cur[0] >=0 and prev[0]>=0 and cur[0] <= prev[1] ):
                cur[0] = prev[0];
                if( cur[1] < prev[1]):
                    cur[1] = prev[1];
                prev[0] = -1
        start = -1;
        end = -1;
        ans = []
        for avail in avails_list:
            if( avail[0] >= 0 ):
                if( start >= 0):
                    ans.append([start, avail[0]]);
                start = avail[1]
        return ans;
        #for avail in avails:
            