#Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ 
class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        left = 0
        l = len(num)
        if l == 1: return num[0]
        if l== 2: return num[0]>num[1] and num[1] or num[0]
        right = l-1
        while left!=right:
            mid = (left+right)/2
            if num[mid]<num[mid+1] and num[mid]<num[mid-1]:
                return num[mid]
            if num[mid]>num[right]:
                left = mid+1
            else:
                right = mid-1
        return num[left]