#Link: https://leetcode.com/problems/find-and-replace-in-string/ 
class Solution:
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        begin_idx = []
        for i,idx in enumerate(indexes):
            fidx = S[idx:].find(sources[i])
            if( fidx == 0 ):
                fidx = idx+fidx;
            else:
                fidx = -1;
            begin_idx.append((fidx,i));
        begin_idx.sort()
        #print('begin ',begin_idx)
        str_list = []
        prev = 0
        for idx,i in begin_idx:
            if( idx >= 0 ):
                str_list.append(S[prev:idx])
                str_list.append(targets[i])
                prev = idx+len(sources[i]);
                #print("prev ", prev, idx, len(sources[i]))
        
        str_list.append(S[prev:])
        return "".join(str_list)