#Link: https://leetcode.com/problems/bold-words-in-string/ 
class Solution:
    def boldWords(self, words, S):
        """
        :type words: List[str]
        :type S: str
        :rtype: str
        """
        seg = []
        for word in words:
            idx = -1
            while( True ):
                idx = S.find(word, idx+1);
                seg.append([idx, idx+len(word)]);
                if( idx < 0 ):
                    break;
        seg.sort();
        print(seg)
        for idx in range(1, len(seg)):
            curseg = seg[idx];
            prevseg = seg[idx-1];
            if( curseg[0] >=0 and prevseg[0]>=0 and curseg[0] <= prevseg[1] ):
                curseg[0] = prevseg[0];
                if( curseg[1] < prevseg[1]):
                    curseg[1] = prevseg[1];
                prevseg[0] = -1
        print(seg)
        l = []
        prev=0;
        for s in seg:
            if( s[0] >= 0 ):
                l.append(S[prev:s[0]])
                l.append("<b>")
                l.append(S[s[0]:s[1]])
                l.append("</b>")
                prev = s[1]
        else:
            l.append(S[prev:len(S)]);
        print(l)
        return "".join(l)
            