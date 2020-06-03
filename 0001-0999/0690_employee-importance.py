#Link: https://leetcode.com/problems/employee-importance/ 
"""
# Employee info
class Employee(object):
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution(object):
    def findVal( self, employees, id):
        item = employees.get(id)
        if item:
            val = item.importance;
            for sub in item.subordinates:
                val += self.findVal(employees, sub)
            return val
        else:
            return 0
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        em = {}
        for e in employees:
            em[e.id] = e
        #item = employees[id]
        val = self.findVal( em, id )
        return val
        