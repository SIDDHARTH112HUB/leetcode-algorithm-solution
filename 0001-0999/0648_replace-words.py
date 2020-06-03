#Link: https://leetcode.com/problems/replace-words/ 
class Solution(object):
    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        dict.sort();
        root = {dict[0]:dict[0]}
        for word in dict:
            for k, v in root.items():
                if( word.startswith(k)):
                    root[word] = k
                    break;
            else:
                root[word] = word
        #print( root )

        word_list = sentence.split(" ")
        root_list = []
        for word in word_list:
            root_word = root.get(word)
            if( root_word ):
                root_list.append(root_word)
            else:
                for k,v in root.items():
                    if( word.startswith(k)):
                        root[word] = v
                        root_list.append(v)
                        break;
                else:
                    #root[word] = word
                    root_list.append(word)
        
        return " ".join(root_list)