#Link: https://leetcode.com/problems/subdomain-visit-count/ 
class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        ans = {}
        for cp in cpdomains:
            cpair = cp.split(" ")
            domain_str_list = cpair[1].split(".")
            for i in range(0, len(domain_str_list)):
                s = ".".join(domain_str_list[i:])
                ans[s] = ans.get(s, 0) + int(cpair[0]);
                domain_str_list[i] = ""
        ans_list = []
        for k,v in ans.items():
            ans_list.append("%d %s"%(v, k))
        #print(ans_list)
        return ans_list
        